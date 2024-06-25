import sys

s = input()

l = int(len(s)/2)
length = len(s)
isP = 1
for i in range(l):
    if s[i] != s[length-i -1]:
        isP = 0


print(isP)



