import sys
from heapq import heappop, heappush

#sys.stdin = open("input.txt", "r")

sol ={}
min_h = []
max_h = []

N = int(input())
for i in range(N):
    num, degree = map(int, input().split())
    sol[num] = degree
    heappush(min_h, (degree,num))
    heappush(max_h, (-degree, -num))
#print(sol)

M = int(input())

for i in range(M):
    str = list(input().split())
    #print(str)
    if str[0] == "add":
        num = int(str[1])
        degree = int(str[2])
        sol[num] = degree
        heappush(min_h, (degree, num))
        heappush(max_h, (-degree, -num))

    elif str[0] == "recommend":
        x = int(str[1])
        # 가장 어려운 문제를 제거하는 경우
        if x == 1:
            # sol에서 이미 제거된 경우 혹은 key와 value가 잘못 매칭된 경우 제거
            while -max_h[0][1] not in sol or sol[-max_h[0][1]] != -max_h[0][0]:
                heappop(max_h)
            print(-max_h[0][1])
        else:
            while min_h[0][1] not in sol or sol[min_h[0][1]] != min_h[0][0]:
                heappop(min_h)
            print(min_h[0][1])
    else:
        num = int(str[1])
        sol.pop(num)
        #print(sol)


