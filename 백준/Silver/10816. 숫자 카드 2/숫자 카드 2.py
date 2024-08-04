import sys

#sys.stdin = open("input.txt")

M = int(input())
ms = list(map(int, input().split(" ")))
target = {}

for i in ms:
    if i in target:
        target[i] += 1
    else:
        target[i] = 1

N = int(input())
ns = list(map(int, input().split(" ")))

answer = []
for j in ns:
    if j in target:
        answer.append(target[j])
    else:
        answer.append(0)

print(*answer)