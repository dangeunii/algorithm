import sys

#sys.stdin = open("input.txt", "r")

n = int(input())
arr = list(map(int, input().split(" ")))
target = int(input())

arr.sort()
answer = -1
start = 1
end = arr[-1]

while start <= end:
    mid = (start + end) // 2
    #print(mid)
    sum = 0
    for i in arr:
        sum += min(mid, i)
    #print(sum)
    if sum <= target:
        start = mid + 1
        answer = mid
    elif sum > target:
        end = mid - 1

print(answer)