import sys

#sys.stdin = open("input.txt","r")

A, B, C = map(int, input().split(" "))

def divide(a,b):
    # 재귀는 기저사례
    if b == 1:
        return a % C

    ret = divide(a, b//2)
    ret = (ret * ret) % C
    if b % 2 == 1:
        ret = (ret * a) % C
    return ret

print(divide(A,B))
