import sys

def hanoi(answer, n, start, end, help):
    # n이 1이면 그냥 목적지로 바로 이동
    if n == 1:
        return answer.append([start, end])
    # 아니면 n-1개의 원판을 보조 기둥으로 이동
    hanoi(answer, n-1, start, help, end)
    # 맨 마지막에 제일 큰 원판을 목적지로 이동
    answer.append([start, end])
    # 보조 기둥에 있는 탑을 목적지로 이동
    hanoi(answer, n-1 ,help, end, start)
        
def solution(n):
    ## 하노이를 해결하기 위한 키 포인트는 재귀
    ## 재귀를 사용해서 가장 큰 원반 전까지를 보조 기둥으로 옮기는게 필요하다
    answer = []
    hanoi(answer, n, 1, 3, 2)
    return answer