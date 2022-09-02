def minMaxSum(arr):
    min, max = 0, 0        
    for i in range(len(arr) - 1):
        for j in range(len(arr) - 1):
            arr[j], arr[j+1] = swapVal(arr[j], arr[j+1])
    for ele in arr[:4]:
        min += ele
    for ele in arr[1:]:
        max += ele
    
    print(min, max)

def swapVal(a, b):
    tmp = a
    if a > b:
        a = b
        b = tmp
    return a, b

