import sys

#sys.stdin = open("input.txt", "r")

A, B, C = map(int,input().split())
counting = [0] * 101
result = 0
for i in range(3):
    s, e = map(int,input().split())
    for j in range (s,e):
        counting[j] += 1

for val in counting:
    if val == 1:
        result += A
    elif val == 2:
        result += (B*2)
    elif val == 3:
        result += (C*3)

print(result)



