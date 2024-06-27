import sys

#sys.stdin = open("input.txt", "r")

n = int(input())
pattern = input()
isFront = 0

pos = 0
for i in range(len(pattern)):
    if pattern[i] == "*":
        pos = i

front_s = pattern[0:pos:]
back_s = pattern[pos+1::]

len_s = len(front_s)
len_b = len(back_s)
# front_s = "".join(s for s in front)
# back_s = "".join(s for s in back)

for i in range(n):
    ss = input()

    # 반례 처리를 위해서
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






