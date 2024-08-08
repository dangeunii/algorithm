import sys

#sys.stdin = open("input.txt", "r")

N = int(input())

isVisited = [[0 for col in range(N)] for row in range(N)]
mapp = []

dy = [-1, 0 ,1, 0]
dx = [0, 1, 0, -1]

for i in range(N):
    arr = list(input())
    mapp.append(list(map(int, arr)))

answer = []

def dfs(y, x):
    cnt = 1
    isVisited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= N or nx < 0 or nx >= N:
            continue
        else:
            if mapp[ny][nx] == 1 and isVisited[ny][nx] == 0:
                cnt += dfs(ny, nx)
    #print("y : ", y, " x : ", x, "cnt : ", cnt)
    return cnt

for i in range(N):
    for j in range(N):
        if mapp[i][j] == 1 and isVisited[i][j] == 0:
            cnt = dfs(i,j)
            answer.append(cnt)

answer.sort()
print(len(answer))
for i in range(len(answer)):
    print(answer[i])

