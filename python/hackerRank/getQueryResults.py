queries_columns = 3
queries_rows = 3

def getQueryResults(n, queries):
    good_arr = getGoodArray(n)
    query_ans_arr = []
    if len(queries) != queries_columns:
        return queries_columns
    for comb in queries:
        if len(comb) != queries_rows:
            continue
        if type(comb[0]) != int:
            continue
        l, r, m = comb[0], comb[1], comb[2]
        if l == r:
            ans = good_arr[l-1] % m
        else:
            ans = (good_arr[l-1] * good_arr[r-1]) % m
        query_ans_arr.append(ans)
    return query_ans_arr
        
def getGoodArray(n):
    good_arr = []
    count = 0  
    while n >= 1:
        mod = n % 2
        if mod == 1:
            good_arr.append(2 ** count)
        n = n // 2
        count += 1    
    return good_arr

n = 6
query = [[1,2,4], [2,2,8], [1,1,4]]
print(getQueryResults(n,query)) #0, 4, 2

