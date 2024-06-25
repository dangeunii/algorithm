import sys

#sys.stdin = open("input.txt","r")

N = int(input())
arr = [0] * 30

for i in range(N):
    s = input()
    first = ord(s[0]) - ord("a")
    arr[first] += 1

answer = []
for i in range(26):
    if arr[i] >= 5:
        s_answer = chr(i + ord("a"))
        answer.append(s_answer)

if len(answer) == 0:
    answer = "PREDAJA"
else:
    answer = "".join(answer)

print(answer)
