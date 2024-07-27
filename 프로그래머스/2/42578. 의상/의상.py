def solution(clothes):
    dict = {}
    cnt = 1
    for i in range(len(clothes)):
        if clothes[i][1] not in dict:
            dict[clothes[i][1]] = 1
        else:
            dict[clothes[i][1]] += 1
    
    for n in dict.values():
        cnt = cnt * (n+1)
        
    answer = cnt -1
    return answer