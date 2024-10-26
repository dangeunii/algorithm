import sys

n = int(input())


for i in range(n):
    cnt_2, cnt_5 = 0, 0
    m = int(input())
    k = 2
    while k <= m:
        cnt_2 += m // k
        k = k * 2

    k_5 = 5
    while k_5 <= m:
        cnt_5 += m // k_5
        k_5 = k_5 * 5

    cnt_10 = min(cnt_2, cnt_5)
    print(cnt_10)
