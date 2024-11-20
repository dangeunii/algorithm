import sys

#sys.stdin = open("input.txt", "r")
mapp = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

answer = []
wall = []
realwall = []
virus = []

# 올바른 input 사용
N, M = map(int, input().split(" "))
#print("N:", N, "M:", M)
answer = 0


# 벽의 조합 구하기
def combination(n, new_arr, c):
    if len(new_arr) == n:
        realwall.append(new_arr)
        return
    for l in range(c, len(wall)):
        combination(n, new_arr + [wall[l]], l + 1)


def virus_spread(temp_map,y,x):
    isVisited[y][x] = 1
    for k in range(4):
        ny = y + dy[k]
        nx = x + dx[k]
        if 0 <= ny < N and 0 <= nx < M:
            if temp_map[ny][nx] == 0 and isVisited[ny][nx] == 0:
                #temp_map[ny][nx] = 2
                isVisited[ny][nx] = 1
                virus_spread(temp_map, ny, nx)



for i in range(N):
    s = list(map(int, input().split()))
    mapp.append(s)
    for idx, ss in enumerate(s):
        # 벽이 될 수 있는 후보군
        if ss == 0:
            wall.append((i, idx))
        elif ss == 2:
            virus.append((i, idx))


#1) 벽이 될 수 있는 조합을 구한다.
combination(3, [], 0)
#2) 벽의 조합만큼 바이러스를 퍼트린다.
for c_list in realwall:
    isVisited = [[0] * M for _ in range(N)]
    #print(c_list)
    # 이렇게 하니까 초기화가 이루어지지 않음
    # for j in range(N):
    #     temp_Map.append(mapp[j])
    # 벽 세우기
    for w in c_list:
        #print(w)
        y = w[0]
        x = w[1]
        mapp[y][x] = 1

    #print("벽 세우기 : ",mapp)
    for v in virus:
        vy = v[0]
        vx = v[1]
        virus_spread(mapp,vy,vx)

    # 안전 영역 갯수 세기
    t_cnt = 0
    for ty in range(N):
        for tx in range(M):
            if mapp[ty][tx] == 0 and isVisited[ty][tx] == 0:
                t_cnt += 1
    #print("temp_map", temp_Map)
    answer = max(answer, t_cnt)
    #print(answer)
    # 벽 지우기
    for w in c_list:
        # print(w)
        y = w[0]
        x = w[1]
        mapp[y][x] = 0
print(answer)




