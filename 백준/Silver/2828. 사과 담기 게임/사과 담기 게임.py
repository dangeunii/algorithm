import sys

#sys.stdin = open("input.txt", "r")

N,M = map(int, input().split())

J = int(input())

l = 1
ret = 0
for i in range(J):
    apple = int(input())

    # 왼쪽 포인터 위치
    r = l + M -1
    if apple >= l and apple <= r:
        continue
    else:
        if apple > r:
            temp = l
            l += apple - r
            ret += abs(l - temp)
        else:
            temp = l
            l -= l-apple
            ret += abs(l - temp)
print(ret)