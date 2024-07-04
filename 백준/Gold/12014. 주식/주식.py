import sys
input = sys.stdin.readline

def binary_search(left, right, target):
    while left <= right:
        mid = (left + right) // 2
        if lis[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return left

test_case = int(input())

for tc in range(1, test_case+1):
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    lis = [numbers[0]]
    for i in range(1, N):
        if lis[-1] < numbers[i]:
            lis.append(numbers[i])
        else:
            j = binary_search(0, len(lis)-1, numbers[i])
            lis[j] = numbers[i]

    print('Case #{}'.format(tc))
    if len(lis) >= K:
        print(1)
    else:
        print(0)