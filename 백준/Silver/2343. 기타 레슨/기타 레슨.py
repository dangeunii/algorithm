import sys

#sys.stdin = open("input.txt", "r")

N, M = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

start = max(arr)
end = sum(arr)
#print("sum : ", end)
#print("max : ", start)
answer = -1

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    remain_cnt = mid
    #print("mid : ",mid)

    for i in arr:
        if remain_cnt >= i:
            remain_cnt -= i
            #print("i : ", i)
        else:
            cnt += 1
            remain_cnt = mid
            remain_cnt -= i

    #print(cnt)
    if cnt > M:
        start = mid + 1
    else:
        answer = mid
        end = mid - 1

print(answer)