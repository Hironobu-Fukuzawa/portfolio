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

----------------------
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
----------------------









