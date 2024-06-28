import sys

#sys.stdin = open("input.txt", "r")

N, M = map(int, input().split())
s = list(map(int, input().split()))

# 부분합 계산
cnt = [0] * (N + 1)
for i in range(1, N + 1):
    cnt[i] = cnt[i - 1] + s[i - 1]

# 슬라이딩 윈도우를 사용하여 최대 합 계산
max_sum = float('-inf')
for i in range(N - M + 1):
    current_sum = cnt[i + M] - cnt[i]
    if current_sum > max_sum:
        max_sum = current_sum

print(max_sum)
