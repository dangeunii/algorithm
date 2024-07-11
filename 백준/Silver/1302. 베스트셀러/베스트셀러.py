import sys

#sys.stdin = open("input.txt")

N = int(input())
cnt = {}

for i in range(N):
    val = input()
    if val in cnt:
         cnt[val] +=1
    else:
        cnt[val] = 1

cnt = sorted(cnt.items(), key= lambda item :(-item[1], item[0]))
print(cnt[0][0])