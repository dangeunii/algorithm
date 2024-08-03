import sys

#sys.stdin = open("input.txt", "r")

N = int(input())
target = {}
arr = list(map(int, input().split(" ")))
for i in arr:
    target[i] = 1

#print(arr)
#print(target)

M = int(input())
answer = []
arr2 = list(map(int, input().split(" ")))
for j in arr2:
    if j in target:
        answer.append(1)
    else:
        answer.append(0)
print(*answer)


