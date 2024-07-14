import sys

#sys.stdin = open("input.txt", "r")
sys.setrecursionlimit(100000)

N = int(input())
info = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
cnt = 0
cnt_arr = []

visited = [[0 for col in range(N)] for row in range(N)]

for i in range(N):
    arr = list(map(int, input().split()))
    info.append(arr)

max_val = max(list(map(max,info)))
#min_val = min(list(map(min,info)))
def DFS(y, x, k):
    visited[y][x] = 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= N or nx < 0 or nx >= N:
            continue
        if info[ny][nx] < k:
            continue
        if visited[ny][nx]:
            continue

        DFS(ny, nx,k)
    return

for k in range(max_val+1):
    #print("k : ", k)
    visited = [[0 for col in range(N)] for row in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(N):
            if info[i][j] >= k and visited[i][j] == 0:
                #print("i : ", i, " j : ", j)
                DFS(i,j,k)
                #print("!!")
                cnt += 1
    #print(cnt)
    cnt_arr.append(cnt)

cnt_arr.sort()

print(cnt_arr[-1])

