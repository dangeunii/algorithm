import sys

#sys.stdin = open("input.txt", "r")

N = int(input())
a , b= 0, 0
win_1 = 0
win_2 = 0

def calTime(time, prev):
    tt = time.split(":")
    t_time = int(tt[0]) * 60 + int(tt[1])
    prev = prev.split(":")
    p_time = int(prev[0]) * 60 + int(prev[1])
    return t_time - p_time

def secToTime(time):
    minute = str(time // 60).zfill(2)
    second = str(time % 60).zfill(2)
    print(f"{minute}:{second}")


for i in range(N):
    id, time = map(str,input().split())
    id = int(id)
    #print(id, time)

    if i == 0:
        prev = time
        #print(prev)

    # a가 우승인 상태로 입력값이 들어옴
    if a > b:
        # 그러면 가장 최근에 들어온 값이랑 지금 시간이랑 걸린 시간 계산 후
        # 둘다 win_1에 저장한다.
        t = calTime(time, prev)
        prev = time
        win_1 += t

    # b가 우승인 상태로 입력값이 들어옴
    elif a < b:
        # 그러면 win_2에 저장
        t = calTime(time, prev)
        prev = time
        win_2 += t

    elif a == b:
        prev = time

    if id == 1:
        a += 1
    elif id == 2:
        b += 1

    if i == N-1:
        t = calTime("48:00", prev)
        if a > b:
            win_1 += t
        elif a < b:
            win_2 += t


    #print(a,b)

secToTime(win_1)
secToTime(win_2)