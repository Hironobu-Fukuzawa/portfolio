import random
CURRENT_POSITION = (50, 70)
NO_RESTAURANT = 50 + 65
SIZE_OF_SIG = 100
DISTANCE_RANGE = 50

def find_nearest_three_restaurants(my_loc: tuple):
    all_loc_list = generate_list() 
    nearest_list, distance_list = [], []
    for loc in all_loc_list:
        dist = distance(my_loc, loc)
        distance_dict = {dist: key for key in loc.keys()}
        distance_list.append(distance_dict)
    for i in range(3):
        min = findMin(distance_list)
        for i in range(len(distance_list)):
            for key in distance_list[i].copy():
                if key == min:
                    nearest_list.append(distance_list[i][key])
                    del distance_list[i][key]
    return nearest_list

def generate_list():
    output_list = []
    for i in range(65, NO_RESTAURANT):
        output_list.append({(random.randint(1, SIZE_OF_SIG), random.randint(1, SIZE_OF_SIG)): chr(i)})    
    return output_list

def findMin(list: list):
    min = [key for key in list[0].keys()][0]
    for dict in list[1:]:
        for ele in dict.keys():
            if min > ele:
                min = ele
    return min

def distance(loc1: tuple, loc2: dict):
    loc2_list = [key for key in loc2.keys()]
    distance = sqrt(square(loc1[0] - loc2_list[0][0]) * square(loc1[1] - loc2_list[0][1]))
    return distance

def square(x):
    return x * x

def sqrt(x):
    return x ** 0.5

# print(find_nearest_three_restaurants(CURRENT_POSITION))
