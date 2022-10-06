class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        l=[]
        x=[]
        for i in range(len(s)):
            if s[i]=="#":
                l=l[:-1]
            else:
                l.append(s[i])
        print(l)
        for i in range(len(t)):
            if t[i]=="#":
                x=x[:-1]
            else:
                x.append(t[i])
        print(x)
        if l==x:
            return True
        return False
        
