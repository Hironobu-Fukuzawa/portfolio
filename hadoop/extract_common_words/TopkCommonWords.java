/*
NAME: HIRONOBU FUKUZAWA
MATRICULATION NUMBER: A0255967J
*/
import java.io.*; 
import java.util.*;
import java.util.stream.Collectors;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.fs.FileSystem;

public class TopkCommonWords {

    public static class TokenizerMapper extends Mapper<Object, Text, Text, Text>{

        private Text word = new Text();
        private Text file = new Text();
        private String filePath;
        private Set<String> stopWords = new HashSet<>();

        @Override
        public void setup(Context context) throws IOException, InterruptedException {
            Configuration conf = context.getConfiguration();
            Path stopWordsFile = new Path(conf.get("stopwords"));
            FileSystem fs = FileSystem.get(conf);
            FileSplit fileSplit = (FileSplit) context.getInputSplit();
            filePath = fileSplit.getPath().getName();
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(fs.open(stopWordsFile)))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    stopWords.add(line.trim());
                }
                reader.close();
            } catch (IOException e) {
                System.err.println("Error: " + e.getMessage());
            }
        }

        public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
            String line = value.toString();
            StringTokenizer tokens = new StringTokenizer(line);

            while (tokens.hasMoreTokens()) {
                boolean skip = false;
                String token = tokens.nextToken();

                if(stopWords.contains(token) || token.length() <= 4 || token.isEmpty()) {
                    continue;
                }
                word.set(token);
                file.set(filePath);
                context.write(word, file);
            }
        }
    }

    public static class IntSumReducer extends Reducer<Text, Text, IntWritable, Text> {

        private LinkedHashMap<String, Integer> result;
        private int k;

        @Override
        public void setup(Context context) throws IOException, InterruptedException {
            Configuration conf = context.getConfiguration();
            k = Integer.parseInt(conf.get("k"));
            result = new LinkedHashMap<String, Integer>();
        }
        
        @Override
        public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            int sum1 = 0;
            int sum2 = 0;
            String word = key.toString();
            String filename = null;
            List<String> ls;

            for (Text value : values) {
                if(filename == null){
                    filename = value.toString();
                    sum1 += 1;
                }else if(filename.equals(value.toString())){
                    sum1 += 1;
                }else {
                    sum2 += 1;
                }
            }

            if(sum1 > 0 && sum2 > 0){
                if(sum1 <= sum2) {
                    result.put(word, sum1);
                }else {
                    result.put(word, sum2);
                }
            }            
        }

        @Override
        public void cleanup(Context context) throws IOException, InterruptedException {
            result = result.entrySet()
            .stream()
            .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
            .limit(k)
            .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
            (oldValue, newValue) -> oldValue, LinkedHashMap::new));

            for (Map.Entry<String, Integer> entry : result.entrySet()) {
                context.write(new IntWritable(entry.getValue()), new Text(entry.getKey()));
            }
        }
    }

    public static void main(String[] args){
        try{
            Configuration conf = new Configuration();
            conf.set("stopwords", args[2]);
            conf.set("k", args[4]);

            Job job = Job.getInstance(conf, "common word");
            job.setJarByClass(TopkCommonWords.class);
            job.setMapperClass(TokenizerMapper.class);
            job.setReducerClass(IntSumReducer.class);
            job.setMapOutputKeyClass(Text.class);
            job.setMapOutputValueClass(Text.class);
            job.setOutputKeyClass(IntWritable.class);
            job.setOutputValueClass(Text.class);
            FileInputFormat.addInputPath(job, new Path(args[0]));
            FileInputFormat.addInputPath(job, new Path(args[1]));
            FileOutputFormat.setOutputPath(job, new Path(args[3]));
            System.exit(job.waitForCompletion(true) ? 0 : 1);

        }catch(IOException exception){
            System.out.println(exception.getMessage());

        }catch(InterruptedException exception){
            System.out.println(exception.getMessage());

        }catch(ClassNotFoundException exception){
            System.out.println(exception.getMessage());
        }
    } 
}
