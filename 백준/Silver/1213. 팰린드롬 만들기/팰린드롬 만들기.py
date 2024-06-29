import sys
from collections import Counter
from collections import deque

#sys.stdin = open("input.txt", "r")

s = input()

cnt = Counter(s)
cnt = sorted(cnt.items(), key= lambda x:x[0], reverse= True)

flag = 0
answer = deque()
mid = ""
for char, count in cnt:
    if count % 2 == 1:
        mid = char
        count -= 1
        flag += 1
    elif flag == 2:
        break
    for i in range(0,count, 2):
        answer.append(char)
        answer.appendleft(char)

if mid is not None:
    answer.insert(len(s)//2 , mid)

if flag >= 2:
    print("I'm Sorry Hansoo")
else:
    ss = ""
    for i in answer:
        ss = ss+i
    print(ss)
