class Solution:
    def romanToInt(self, s: str) -> int:
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        c=0
        for i in range(len(s)-1):
            if d[s[i]]<d[s[i+1]]:
                c-=d[s[i]]
            else:
                c+=d[s[i]]
        c+=d[s[-1]]
        return c
        
