def solution(number, k):
    stack = []
    for i, num in enumerate(number):
        while stack and k > 0 and stack[-1] < num:
            stack.pop()
            k -= 1
        stack.append(num)
    
    # 만약 k가 아직 남아있다면, 뒤에서부터 k개를 잘라줌
    if k > 0:
        stack = stack[:-k]
    
    return ''.join(stack)
