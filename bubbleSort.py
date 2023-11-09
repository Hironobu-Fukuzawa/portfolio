def bubbleSort(arr):
    N = len(arr)
    count = 0
    for i in range(N):
        swapped = False
        for j in range(N-1):
            count += 1
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            print(count)
            break
    
# arr = [5, 4, 3, 2, 1]
arr = [1, 2, 3, 5, 4]

print("bef: ", arr)
bubbleSort(arr)
print("aft: ", arr)

    