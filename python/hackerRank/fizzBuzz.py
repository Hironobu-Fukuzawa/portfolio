def fizzBuzz(n):
    if n % 3 == 0 and n % 5 == 0:
        print(n, ' is FizzBuzz')
    elif n % 3 == 0 and n % 5 != 0:
        print(n, ' is Fizz')
    elif n % 3 != 0 and n % 5 == 0:
        print(n, ' is Buzz')
    else:
        print(n)

# for i in range(0, 101):
#     fizzBuzz(i)


