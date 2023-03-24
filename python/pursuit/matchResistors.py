def matchResistors(R,n):
    R, dict, result_list = sorted(R), {}, []
    for i in range(len(R)):
        if dict.get(R[i]) is None:
            dict[R[i]] = 1
        else:
            dict[R[i]] += 1
        target = n - R[i]
        # A duplicate pair needs at least 2 count numbers
        if target == R[i] and dict[R[i]] < 2:
            continue
        if target in dict:
            if dict[target] > 0 and dict[R[i]] > 0:
                dict[R[i]] -= 1
                dict[target] -= 1
                result_list.append((R[i], target))
    return result_list

from random import shuffle
longlist = [i for i in range(1, 10000)]
shuffle(longlist)
print(len(matchResistors(longlist, 10001)))

# print(matchResistors((75,80,90,77,88,91,60,74,73,70,55,93,59),150))
# print(matchResistors((1,5,5,9,1), 10))    

# def matchResistorsBiSearch(R,n):
#     result_list, d1 = [], {i: R[i] for i in range(len(R))}
#     d2 = d1.copy()
#     while l > 1:
#         pair_val = n - R[0]
#         target_index = binarySearch(d2, pair_val, 0, len(R)-1)
#         if target_index != 0:
#             R.pop(target_index)
#             result_list.append((R[0], pair_val))
#         R.pop(0) #Search the pair value except the original value
#         l = len(R)
#     return result_list

# def binary_search(key, seq):
#     if seq == []:
#         return False
#     mid = len(seq) // 2
#     if key == seq[mid]:
#         return True
#     elif key < seq[mid]:
#         return binary_search(key, seq[:mid])
#     else:
#         return binary_search(key, seq[mid+1:])

# def binarySearch(R, target_val, low, high):
#     while low < high:
#         mid = int((low + high) / 2)
#         if(target_val == R[high]):
#             return high
#         elif(target_val == R[mid]):
#             return mid
#         elif(target_val == R[low]):
#             return low
#         elif(target_val > R[mid]):
#             low = mid + 1
#         elif(target_val < R[mid]):
#             high = mid - 1
#     return 0

# Recursive version
# def matchResistorsRecursive(R,n):
#     R, l = sorted(R), len(R)
#     if l <= 1:
#         return []
#     val1 = R[0]
#     val2 = n - R[0]
#     R.remove(val1)
#     for value in R:
#         if value == val2:
#             pair_list = [(val1, val2)]
#             R.remove(val2)
#             return pair_list + matchResistorsRecursive(R, n)
#     return matchResistorsRecursive(R, n)

# Using list methods (O(n) version)
# def matchResistors(R,n):
#     R, l = sorted(R), len(R)
#     result_list = []
#     while l > 1:
#         val1, val2 = R[0], n - R[0]
#         R.remove(val1)
#         for value in R:
#             if value == val1:
#                 R.remove(value)
#             elif value == val2:
#                 R.remove(val2)
#                 result_list.append((val1, val2))
#                 break
#         l = len(R)
#     return result_list
# print(matchResistors((75,80,90,77,88,91,60,74,73,70,55,93,59),150))
# print(matchResistors((1,5,5,9,1), 10))    
# R = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
# R = [1,5,5,9,1]
# R = [5,5]
# print(binarySearch(R, 5, 0, 4))

# def returnUniqueList(l:list):
#     for ele in l:
#         count = l.count(ele)
#         while count > 1:
#             l.index(ele)
#             l.remove(ele)
#             count = l.count(ele)
#     return l

# print(matchResistors((23,75,80,90,77,88,91,60,1,74,73,4,70,55,7,9,93,59,12,43),170))
# print(matchResistors((75,80,90,77,88,91,60,74,73,70,55,93,59),110))
# print(matchResistors((10,12,40,10,12,10,12, 10, 22, 12, 12,12),22))
# print(matchResistors((75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,40,110),150))
# print(matchResistors((10,12,40,10,12, 10, 12, 10, 22, 12, 12,12),22))
# print(matchResistors((10,12,40,10,12),22))
# print(matchResistors((1,5,5,9,1), 10))    
# print(matchResistors((75,75,75,75,75,75,75,75,75,75,75,75,75,75,40,110),150))
# print(matchResistorsRecursive((75,80,90,77,88,91,60,74,73,70,55,93,59),150))
# print(matchResistorsRecursive((75,80,90,77,88,91,60,74,73,70,55,93,59),115))
# print(matchResistorsRecursive((23,75,80,90,77,88,91,60,1,74,73,4,70,55,7,9,93,59,12,43),170))
# print(matchResistorsRecursive((75,80,90,77,88,91,60,74,73,70,55,93,59),110))
