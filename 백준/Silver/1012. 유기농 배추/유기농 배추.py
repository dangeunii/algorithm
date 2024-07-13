import sys

#sys.stdin = open("input.txt", "r")
sys.setrecursionlimit(5000)

T = int(input())

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def DFS(y, x):
    mapp[y][x] = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= N or nx <0 or nx >= M:
            continue
        if mapp[ny][nx] == 0:
            continue
        DFS(ny, nx)
    return


for i in range(T):
    cnt = 0
    M, N, K = map(int, input().split())
    mapp = [[0 for col in range(M)] for row in range(N)]
    for j in range(K):
        x, y = map(int, input().split())
        mapp[y][x] = 1

    #print(mapp)
    for col in range(N):
        for row in range(M):
            if mapp[col][row] == 1:
                DFS(col, row)
                cnt +=1
    print(cnt)