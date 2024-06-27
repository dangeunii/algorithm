import sys

#sys.stdin = open("input.txt", "r")

n = int(input())
pattern = input()
isFront = 0
front = []
back = []

for s in pattern:
    if s != "*":
        if isFront == 0:
            front.append(s)
        else:
            back.append(s)
    else:
        isFront = 1

front_s = "".join(s for s in front)
back_s = "".join(s for s in back)
for i in range(n):
    ss = input()
    len_s = len(front)
    len_b = len(back)
    if len(ss) < len_s+len_b:
        print("NE")
        continue
    ss_s = ss[0:len_s:]
    ss_b = ss[len(ss)-len_b::]
    if ss_s == front_s:
        if ss_b == back_s:
            print("DA")
        else:
            print("NE")
    else:
        print("NE")






