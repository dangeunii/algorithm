def solution(n, computers):
    isVisited = [False] * n
    answer = 0
    
    def DFS(computers, n, point):
        isVisited[point] = True
        for i in range(n):
            if computers[point][i] == 1 and isVisited[i] == False:
                DFS(computers, n, i)
        
        
    for i in range(n):
        if isVisited[i] == False:
            DFS(computers, n, i)
            answer += 1
            
    return answer
        
        