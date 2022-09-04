def lonelyinteger(a):
    for ele in a:
        if a.count(ele) == 1:
            return ele
        
        
# Input a[1,2,3,4,5,4,3,2,1]
# Output 5
# a = [1, 2, 3, 4, 5, 4, 3, 2, 1]
# print(lonelyinteger(a))
