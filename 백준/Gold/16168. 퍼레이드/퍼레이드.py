import sys

sys.setrecursionlimit(5000)

#sys.stdin = open("input.txt", "r")

V, E = map(int, input().split())

adj = [[] for _ in range(V + 1)]

for i in range(E):
    n1, n2 = map(int, input().split(" "))
    adj[n1].append(n2)
    adj[n2].append(n1)

visited = [0] * (V + 1)
visited[0] = 1


def dfs(u):
    visited[u] = 1
    for v in adj[u]:
        if visited[v]:
            continue
        dfs(v)
    return


dfs(1)
for i in visited:
    # print(i)
    if i == 0:
        print("NO")
        exit(0)

# 간선 탐색
# print(adj)
cnt_odd = 0
for i in range(1, V + 1):
    if len(adj[i]) % 2 != 0:
        cnt_odd += 1

if cnt_odd == 0 or cnt_odd == 2:
    print("YES")
else:
    print("NO")
