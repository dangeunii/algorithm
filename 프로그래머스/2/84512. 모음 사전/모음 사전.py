import itertools

def solution(word):
    arr = ['A', 'E', 'I', 'O', 'U']
    target = []
    answer = 0
    for i in range(1,6):
        n = list(itertools.product(arr,repeat = i))
        for w in n:
            target.append(''.join(w))
    target.sort()
    
    for i in range(len(target)):
        if word == target[i]:
            answer = i+1
            break
    return answer