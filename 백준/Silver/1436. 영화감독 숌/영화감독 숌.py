
n = int(input())
i = 0
cnt = 0

while(1):
    i += 1
    if "666" in str(i):
        #print(i)
        cnt += 1
        if cnt == n:
            break

print(i)
