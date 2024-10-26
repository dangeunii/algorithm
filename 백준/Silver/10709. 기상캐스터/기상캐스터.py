

h,w = map(int, input().split())

weather = []
result = [[-1]*w for _ in range(h)]

for i in range(h):
    weather.append(list(map(str, input())))

for i in range(h):
    for j in range(w):
        if weather[i][j] == "c":
            result[i][j] = 0
        elif j == 0:
            continue
        elif result[i][j-1] != -1:
            result[i][j] = result[i][j-1] + 1


for i in range(h):
    ## 이 출력방법 외워두기!
    print(*result[i])