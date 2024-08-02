def solution(citations):
    
    sort_citations = sorted(citations)
    
    size = len(sort_citations)
    
    answer = 0
    
    for i in range(size):
        num = size - i
        print(num)
        if num >= sort_citations[i]:
            answer = sort_citations[i]
        elif num < sort_citations[i]:
            if answer < num:
                answer = num
            

    return answer