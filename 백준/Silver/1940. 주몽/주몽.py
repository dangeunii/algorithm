import sys

#sys.stdin = open("input.txt", "r")

N = int(input())
M = int(input())
arr =list(map(int, input().split()))
arr.sort()

i = 0
j = len(arr)-1
sum = 0
cnt = 0

while( i < j ):
    if i > len(arr) or j < 0:
        break
    sum = int(arr[i]) + int(arr[j])
    if sum < M:
        i += 1
    elif sum > M:
        j -= 1
    else:
        cnt += 1
        i += 1
        j -= 1

print(cnt)