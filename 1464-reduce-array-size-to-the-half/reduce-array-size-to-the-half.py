class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        heap = []
        cnt = [0] * (10*10*10*10*10+1)
        for item in arr:
            cnt[item] += 1
        
        for item in cnt:
            heapq.heappush(heap, -item)
        
        target = len(arr) / 2
        count = 0
        print(heap)
        i = 0
        while (count < target):
            print(1)
            n = heapq.heappop(heap)*(-1)
            count += n
            i += 1
        
        return i
    
