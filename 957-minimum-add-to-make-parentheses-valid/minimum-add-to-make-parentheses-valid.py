class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        q = deque()
        cnt = 0
        for val in s:
            if val == "(":
                q.append(val)
            elif val == ")" and len(q) > 0:
                q.pop()
            else:
                cnt += 1
    
        return cnt + len(q)