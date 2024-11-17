import sys
from collections import deque

#sys.stdin = open("input.txt", "r")

while True:
    s = input()
    if s == ".":
        break
    s = list(s)
    flag = 0
    q1 = deque()
    q2 = deque()

    for ss in s:
        if ss == "(" or ss == ")" or ss == "[" or ss == "]":
            q1.append(ss)

    while q1:
        ns = q1.pop()
        if ns == ")" or ns == "]":
            q2.append(ns)
        if ns == "(":
            if len(q2) == 0 or q2[-1] != ")":
                flag = 1
                break
            elif q2[-1] == ")":
                q2.pop()
        elif ns == "[":
            if len(q2) == 0 or q2[-1] != "]":
                flag = 1
                break
            elif q2[-1] == "]":
                q2.pop()

    if len(q1) == 0 and len(q2) == 0 and flag == 0:
        print("yes")
    else:
        print("no")
