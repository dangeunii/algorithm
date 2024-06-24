class Solution:
    def removeStars(self, s: str) -> str:
        q = deque()
        for val in s:
            if val == "*":
                q.pop()
            else:
                q.append(val)    
  
        answer = ""
        for i in range(len(q)):
            answer = answer + q[i]
        return answer