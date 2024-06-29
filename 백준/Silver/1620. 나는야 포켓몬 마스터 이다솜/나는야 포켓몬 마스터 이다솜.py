import sys

#sys.stdin = open("input.txt", "r")

N, M = map(int, sys.stdin.readline().split())

dict={}
arr = []
for i in range (1, N+1):
    s = sys.stdin.readline().strip()
    dict[s] = i
    arr.append(s)

# print(dict)
# print(arr)
# 여기서 이중 for문을 사용하면서 시간초과가 발생한다..
# 그래서 자료구조를 두개 사용한다.

for i in range(M):
    n = sys.stdin.readline().strip()
    if n.isdigit():
        print(arr[int(n)-1])
    else:
        print(dict.get(n))
