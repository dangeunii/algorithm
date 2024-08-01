def solution(cards1, cards2, goal):
    # 사용 순서를 어떻게 체크할까?
    answer = ""
    for target in goal:
        if len(cards1) > 0:
            test1 = cards1[0]
        else:
            test1 = "null"
        if len(cards2) > 0:
            test2 = cards2[0]
        else:
            test2 = "null"
        print(target, test1, test2)
        if target == test1:
            cards1.pop(0)
        elif target == test2:
            cards2.pop(0)
        else:
            answer = "No"
            break
            
    if answer != "No":
        answer = "Yes"
    return answer