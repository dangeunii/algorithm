import sys

#sys.stdin = open("input.txt", "r")

N = int(input())

mapp = [list(map(str, input())) for _ in range(N)]

def quard(y, x, size):
    tmp = mapp[y][x]
    if size == 1:
        return tmp
    ret = ""
    for i in range(y, y+size):
        for j in range(x, x+size):
            if tmp != mapp[i][j]:
                ret += "("
                ret += quard(y, x, size//2)
                ret += quard(y, x+size//2, size//2)
                ret += quard(y+size//2, x, size//2)
                ret += quard(y+size//2, x + size//2, size//2)
                ret += ")"
                return ret
    return tmp
                

print(quard(0,0,N))


