class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=0
        j=0
        f=0
        while i<len(s) and j <len(t):
            if s[i]==t[j]:
                f+=1
                i+=1
            j+=1
        if f==len(s):
            return True
        return False
                
                
        
