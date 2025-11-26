from typing import List

def swap(a, b):
    tmp = a;
    a = b;
    b = tmp
    return a, b

def shell_sort(numbers: List[int]) -> List[int]:
    len_num = len(numbers)
    gap = len_num / 2
    for i in range(len(numbers)):
        for j in range(len(numbers)-i-1):
            if numbers[j] > numbers[j+1]:
                numbers[j], numbers[j+1] = swap(numbers[j], numbers[j+1])
    return numbers

print(shell_sort([5, 4, 3, 2, 1]))
