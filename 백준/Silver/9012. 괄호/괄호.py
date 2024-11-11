import sys
from collections import deque


N = int(input())


for i in range(N):
    flag = 0
    tmp = deque()
    s = list(input())
    s = deque(s)

    #print(s)
    while s:
        t = s.pop()
        #print(t)
        if t == ")":
            tmp.append(t)
            #print("tmp : ", tmp)
        elif t == "(":
            if len(tmp) == 0:
                flag = 1
            else:
                tmp.pop()

    #print(tmp)
    if len(tmp) != 0:
        flag = 1

    if flag == 0:
        print("YES")
    else:
        print("NO")