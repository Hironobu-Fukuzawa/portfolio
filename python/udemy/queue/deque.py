from collections import deque

def reverse(queue) -> deque:
    new_que = deque()    
    while queue:
        new_que.append(queue.pop())        
    # for ele in queue:
    #     new_que.appendleft(ele)
    return new_que

if __name__ == "__main__":
    q = deque()
    q.append(1)
    q.append(2)
    q.append(3)
    q.append(4)
    print(q)
    print(reverse(q))
