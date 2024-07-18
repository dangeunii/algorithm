import sys

#sys.stdin = open("input.txt", "r")
sys.setrecursionlimit(100000)

M, N, K = map(int, input().split())

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

mapp = [[1 for col in range(M)] for row in range(N)]
visited = [[0 for col in range(M)] for row in range(N)]
answer = []
cnt = 0
num = 0

def DFS(y, x):
    ret = 1
    visited[y][x] = 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= N or nx < 0 or nx >= M:
            continue
        if visited[ny][nx] == 1:
            continue
        if mapp[ny][nx] == 1:
            ret += DFS(ny, nx)
    return ret


## map 그리기
for i in range(K):
    fy, fx, ey, ex = map(int, input().split())
    for j in range(fy, ey):
        for k in range(fx, ex):
            mapp[j][k] = 0
#print(mapp)

## dfs 호출해서 완전탐색으로 그래프 갯수 찾기
for i in range(N):
    for j in range(M):
        if mapp[i][j] and visited[i][j] == 0:
            cnt = DFS(i, j)
            #print(cnt)
            answer.append(cnt)
            num += 1

print(num)
answer.sort()
print(*answer)
