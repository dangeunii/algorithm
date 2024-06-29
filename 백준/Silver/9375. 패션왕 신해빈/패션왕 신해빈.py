import sys

#sys.stdin = open("input.txt", "r")

N = int(input())

for i in range(N):
    dict = {}
    cnt = 0
    M = int(input())
    if M == 0:
        print(0)
    else:
        for j in range(M):
            s = list(input().split())
            category = s[1]
            if dict.get(category) is None:
                dict[category] = 1
            else:
                dict[category] += 1
        for key, value in dict.items():
            if cnt == 0:
                cnt = value + 1
            else:
                cnt = cnt * (value+1)
        print(cnt - 1)
