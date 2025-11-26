from typing import List, NewType

IndexNum = NewType('IndexNum', int)

def linear_search(numbers:List[int], value:int) -> IndexNum:
    for i in range(0, len(numbers)):
        if numbers[i] == value:
            return i
    return -1

def binary_search(numbers:List[int], value:int) -> IndexNum:
    left, right = 0, len(numbers) - 1
    while left <= right:
        mid = (left + right) // 2
        if numbers[mid] < value:
            left = mid + 1
        elif numbers[mid] > value:
            right = mid - 1
        else:
            return mid
    return -1

def rec_binary_search(numbers:List[int], value:int) -> IndexNum:
    def _binary_search(numbers:List[int], left:IndexNum, right:IndexNum, value:int) -> IndexNum:
        if left <= right:
            mid = (left + right) // 2
            if numbers[mid] == value:
                return mid
            elif numbers[mid] < value:
                return _binary_search(numbers, mid+1, right, value)
            else:
                return _binary_search(numbers, left, mid-1, value)
        else:
            return -1
    return _binary_search(numbers, 0, len(numbers) - 1, value)

if __name__ == "__main__":
    import random
    numbers = [2, 5, 7, 8, 9, 11, 15, 17, 19, 20]
    # print(numbers)
    # print(linear_search(numbers, 16))
    # print(binary_search(numbers, 9))
    print(rec_binary_search(numbers, 5))