n, c = map(int,input().split(" "))
arr = list(map(int, input().split(" ")))
val = {}

for i in arr:
     if i not in val:
         val[i] = 1
     else:
         val[i] += 1

sorted_dict = dict(sorted(val.items(), key=lambda x: x[1], reverse=True))

for i in sorted_dict:
    for j in range(sorted_dict[i]):
        print(i, end=" ")