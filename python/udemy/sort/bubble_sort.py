# def bubble_sort(numbers: list) -> list:
#     for i in range(len(numbers)):
#         for j in range(len(numbers)-i-1):
#             if numbers[j] > numbers[j+1]:
#                 numbers[j], numbers[j+1] = swap(numbers[j], numbers[j+1])
#     return numbers

def bubble_sort(numbers: list) -> list:
    for i in range(len(numbers)):
        for j in range(len(numbers)- i - 1):
            if numbers[j] > numbers[j+1]:
                numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
    return numbers

# def swap(a, b):
#     tmp = a;
#     a = b;
#     b = tmp
#     return a, b


print(bubble_sort([5, 4, 3, 2, 1]))
