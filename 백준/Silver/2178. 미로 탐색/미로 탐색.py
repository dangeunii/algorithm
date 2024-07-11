import sys
from collections import deque

#sys.stdin = open("input.txt", "r")

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

N,M = map(int,input().split(" "))
map = [list(map(int,input())) for i in range(N)]

def BFS(pos_x, pos_y):
    q = deque()
    q.append((pos_y, pos_x))

    while q:
        # queue로 사용하므로 반드시 popleft를 해줘야 한다!!
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or ny >=N or nx <0 or nx >=M or map[ny][nx] == 0:
                continue

            if map[ny][nx] == 1:
                map[ny][nx] = map[y][x] + 1
                q.append((ny, nx))

BFS(0,0)
print(map[N-1][M-1])




