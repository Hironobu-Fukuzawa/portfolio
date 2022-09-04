import random

def countingSort(arr):
    result_list = [0] * n
    for i in range(len(arr)):
        result_list[arr[i]] += 1
    return result_list

n = 100
sample_list = []
for i in range(n):
    sample_list.append(random.randint(1, n-1))
print(sample_list)
print(countingSort(sample_list))
