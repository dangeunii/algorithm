import sys

s = input()
answer = []
for str in s:
    if (ord(str) >= ord("a") and ord(str) <= ord("z")):
        if ord(str) >= ord("a") + 13:
            answer.append(chr(ord(str)-13))
        else:
            answer.append(chr(ord(str) + 13))
    elif ord(str) >= ord("A") and ord(str) <= ord("Z"):
        if ord(str) >= ord("A") + 13:
            answer.append(chr(ord(str)-13))
        else:
            answer.append(chr(ord(str)+13))
    else:
        answer.append(str)

answer = "".join(s for s in answer)

print(answer)

