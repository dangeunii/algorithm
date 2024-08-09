from collections import deque
def solution(people, limit):
    people.sort()
    answer = 0
    p1 = 0
    p2 = len(people) -1
    
    while(p1 <= p2):
        if people[p1] + people[p2] <= limit:
            p1 += 1
        p2 -= 1
        answer += 1
    return answer