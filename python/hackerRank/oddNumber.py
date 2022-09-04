def oddNumbers(l, r):
    odd_list = []
    num_list = []
    for i in range(l, r+1):
        num_list.append(i)
    if num_list[0] % 2 == 0:
        odd_list = num_list[1::2]
    else:
        odd_list = num_list[::2]
    return odd_list

# print(oddNumbers(3, 9))
# print(oddNumbers(96, 97))
# print(oddNumbers(1, 100))
