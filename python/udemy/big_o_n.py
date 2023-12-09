# O(logn)
def func1(n):
    if n <= 1:
        return n
    else:
        print(n)
        func1(n / 2)


# O(n * logn)
def func2(n):
    # O(n)
    for i in range(int(n)):
        print(i, end=' ')
    print()
    if n <= 1:
        return
    # O(log n)w
    func2(n/2)


# O(n**2)
def func3(num):
    for i in range(1, num+1):
        for j in range(1, num+1):
            print(i, j)
        print()


func1(10)
func2(10)
func3(10)
