n = 8
arr = [1,6,10,14,5,90,100,45]

def findMedian(arr):
    index = n // 2
    arr = sorted(arr)
    # for i in range(n - 1 // 2):
    #     for j in range(n - 1):
    #         arr[j], arr[j+1] = swap(arr[j], arr[j+1])
    return arr[index:index+1][0]
    
# def swap(a, b):
#     tmp = a
#     if a > b:
#         a = b
#         b = tmp
#     return a, b

print(findMedian(arr))
