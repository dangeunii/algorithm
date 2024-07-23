def solution(x, n):
    answer = []
    for i in range(n):
        temp = x + i*x
        answer.append(temp)

    return answer