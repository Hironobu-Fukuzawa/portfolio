import random


def in_order(numbers: list) -> bool:
    # if all values are True, then return True
    return all(numbers[i] < numbers[i+1] for i in range(len(numbers)-1))
    # for i in range(len(numbers)-1):
    #     if numbers[i] > numbers[i+1]:
    #         return False
    # return True


def bogo_sort(numbers: list) -> list:
    count = 0
    while not in_order(numbers):
        count += 1
        random.shuffle(numbers)
    print("sort times: ", count)
    return numbers


if __name__ == '__main__':
    print(bogo_sort([1,5,3,2,6]))
