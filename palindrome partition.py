class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans=[]
        def solve(s,ans,temp):
            if temp:
                if temp[-1]!=temp[-1][::-1]:
                    return
                elif not s:
                    ans.append(temp)
                    return
            for i in range(len(s)):
                solve(s[i+1:],ans,temp+[s[0:i+1]])
        solve(s,ans,[])
        return ans
        
