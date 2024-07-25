def solution(s):
    answer = []
    # 1. 문자열을 스페이스바 기준으로 split
    arr = list(s.split(" "))
    
    # 2. 첫 문자열을 제외하고 아스키 코드로 비교했을때 65 이상이면 small case 로 변경
    for ss in arr:
        ss = list(ss)
        for i in range(len(ss)):
                #print(ss[i], ord(ss[i]))
                if i == 0:
                    if 'a' <= ss[i] <= 'z':
                        ss[i] = chr(ord(ss[i]) - 32)
                        #print(ss)
                else:
                    if 'A' <= ss[i] <= 'Z':
                        ss[i] = chr(ord(ss[i]) + 32)
        ss = ''.join(ss)
        answer.append(ss)
                    
    
    answer = ' '.join(answer)
    return answer