class Solution:
    def numsSameConsecDiff(self, N: int, k: int) -> List[int]:
        res=[]
        if N==1:
            res.append(0)
        def dfs(num,N):
            if N==0:
                res.append(num)
                return 
            last_digit=num%10
            if last_digit>=k:
                dfs(num*10+last_digit-k,N-1)
            if last_digit+k<10 and k>0:
                dfs(num*10+last_digit+k,N-1)
        for i in range(1,10):
            dfs(i,N-1)
        return res
                
        
