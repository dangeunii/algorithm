import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    while len(scoville) > 1:
        first = heapq.heappop(scoville)
        if first >= K:
            break
        second = heapq.heappop(scoville)
        if first >= K:
            break
        else:
            tmp = first + (second * 2)
            answer += 1
            heapq.heappush(scoville,tmp)
                
    if scoville[0] < K:
        answer = -1
                
    return answer