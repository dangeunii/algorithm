
n = int(input())

answer = []
for i in range(n):
    ss = input()
    ret = ""
    for s in ss:
        ## s가 숫자일때
        if s.isnumeric():
            #print("s : ", s)
            ret += s
        ## s가 문자일때
        ## 그러면 return 값에서 맨 앞이 0인것만 제거
        ## 근데 000이면 제거하면 안됨...
        elif s.isalpha():
            ret.lstrip("0")
            if len(ret) > 0:
                answer.append(int(ret))
                ret = ""
    if ret != "":
        ret = ret.lstrip("0")

        if len(ret) > 0:
            answer.append(int(ret))
        elif len(ret) == 0:
            answer.append(0)
answer.sort()
for i in range(len(answer)):
    print(answer[i])





