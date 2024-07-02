import sys

#sys.stdin = open("input.txt", "r")

while True:
    try:
        target = "1"
        n = int(input())
        while True:
            if int(target) % n == 0:
                break
            else:
                target = target + "1"
        print(len(target))
    except EOFError:
        break
