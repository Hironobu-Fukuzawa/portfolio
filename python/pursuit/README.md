# Find Nearst Location

###1.NUS optional homework
FILE: find_nearest_restaurants.py<br>
DESIGN: Return all locations which satifify the distance which is less than the particular distance.<br>
Input: (50, 50)<br>
Output: [{(44, 64): 'A'}, {(47, 57): 'P'}, {(48, 46): 'X'}, {(44, 66): 'h'}]<br><br>

###2.Customized Program
FILE: find_nearest_three_restaurants.py<br>
DESIGN: Return three locations which satifify the distance which is the third nearst the particular distance.<br>
Input: (50, 50)<br>
Output: [(51, 49), (51, 52), (52, 52)]<br>

--------------------------------------------
Points need to be modified<br><br>

1) Dictionary structure for data<br>
In this case, a dictionary is not strictly necessary to store the name and location of a restaurant. For example, you can use a tuple (x, y, name), or a nested tuple ((x, y), name). There’s nothing wrong with using a dictionary of course, but it does incur a slight extra overhead cost due to hashing (you will learn this in 5003). Nevertheless, it does make the code slightly more readable, so I think it is a good method :)<br><br>

2) Code logic<br>
Your approach of using a dictionary mapping distance: single restaurant is interesting. However, it does result in some inefficiencies when finding the 3 minimum distance restaurants.
The approach I would take is to have a dictionary of lists, which I will name distances_to_restaurants. distances_to_restaurants[distance] will give a list containing all the restaurants at that distance. I will populate distances_to_restaurants by doing one iteration over all restaurants (i.e. O(n), if you know big O notation for analysing time complexity).
During the population phase, I will note the 3 minimum distances seen.<br><br>

After population distances_to_restaurants, I can lookup the minimum 3 distances seen in order. If the first shortest distance list already contains 3 restaurants, I don’t even need to check the next 2 :) It might seem confusing, so let me know if you want a video chat or meetup in person to discuss this.<br><br><br>


3) Squared distance<br>
In general, square root is an extremely inefficient function. Since you are comparing distances, why not just use the squared distance? If you think about it, both squared and square-rooted distances give the same results :)<br>
--------------------------------------------

# Match Resistors

## Introduction
Everything is ready except that they need some resistors in their main circuits! For each drone, it needs two extra resistors that must be connected in series to produce the desired total resistance. Namely, total resistance R = R1 + R2.
For example, if you need a total resistance of 10 ohms, you can connect two resistors with resistances 2 ohms and 8 ohms, or another pair of 3 ohms and 7 ohms. You are given as many drones as possible, and they all need the same resistance R. In your hands, you are given a lot of resistors such that every resistor is unique and none of them has the same resistance with each other (Note that we will relax this uniqueness requirement in the later part). And of course, every resistor has a positive non-zero integer value of resistance. Your task is, given a tuple that contains the resistance values of all the resistors, find out all the pairs of resistors that can produce a total sum of R ohms. For example, if you have a tuple of resistors:
You can call your function to find out what are the combinations for different total resistance. These two examples find all the resistors that can sum up to 150 ohms and 152 ohms.

## Basic
Write the function ‘matchResistors(R,n)’ to return a list of tuples L. And each of the tuple contains a pair of resistor in the list L that sum up to R like the examples above. Again, here are some rules for your function in order to gain full marks:
   
• You cannot modify the original input. And your function should work with inputs of both lists and tuples. You cannot hardcode the input
• You cannot import any packages or functions but you may use any of the built-in functions and methods. You may use sorted() function and .sort() method freely. However, you cannot use any set operations. (Believe us, that is not helpful at all.)
• Every item in your output must be unique (in this part). Namely, you cannot output the same pair twice, even if you swap the two values.
• Your output may be in a different order, and that is ok. Coursemology checker (i.e., test_resistors) is doing the job of checking any possible correct order for you.

## Duplication
You will get this 5 marks if your function ‘matchResistors(R,n)’ can take in inputs with duplicate resistors. In other words, the input may contains two resistors with the same value. Note that each resistor can still only be used at most once. Hence, in the sample run below, once one of the 10 ohm resistor is used with a 12 ohm resistor, both are not available anymore but since there is still another 10 ohm and another 12 ohm, we can still get another pair. However, if your output has duplicates, they must have the correct number of copies.

## Large Inputs
You get this 5 marks if your function ‘matchResistors(R,n)’ can handle large cases, e.g. the length of the input tuple > 1000000. (The function shuffle() is just used to create an example input list. Namely, it just randomly shuffle the list.)

--------------------------------------------

--------------------------------------------





