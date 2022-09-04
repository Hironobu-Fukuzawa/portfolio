import random
# CONSTANT VARIABLES
CURRENT_POSITION = (50, 50)
NO_RESTAURANT = 50 + 65
SIZE_OF_SIG = 100
DISTANCE_RANGE = 50

def find_nearest_restaurants(my_loc: tuple):
    all_locations = generate_list()
    near_list = []
    for loc in all_locations:
        if distance(CURRENT_POSITION, loc) < DISTANCE_RANGE:
            near_list.append(loc)
    return near_list
            
def generate_list():
    output_list = []
    for i in range(65, NO_RESTAURANT):
        output_list.append({(random.randint(1, SIZE_OF_SIG), random.randint(1, SIZE_OF_SIG)): chr(i)})    
    return output_list
    
def distance(loc1: tuple, loc2: dict):
    loc2_list = [key for key in loc2.keys()]
    distance = sqrt(square(loc1[0] - loc2_list[0][0]) * square(loc1[1] - loc2_list[0][1]))
    return distance

def square(x):
    return x * x

def sqrt(x):
    return x ** 0.5

print(find_nearest_restaurants(CURRENT_POSITION))
