import sys
from collections import deque

#sys.stdin = open("input.txt", "r")

N = int(input())
arr = deque()

cnt = 0
for n in range(N):
    q = deque()
    s = input()

    num = 0
    #print("start !")
    for val in s:
        #print("val : ", val)
        if len(q) == 0:
            q.append(val)
            num += 1
        else:
            tmp = q.pop()
            if tmp == val:
                num -= 1
            else:
                q.append(tmp)
                q.append(val)
                num += 1
        #print("num : ", num)

    if num == 0:
        cnt += 1
    #print("cnt : ", cnt)

print(cnt)

