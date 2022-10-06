class Solution:
    def removeDuplicates(self, s: str) -> str:
        l=[]
        for i in range(len(s)):
            if len(l)==0:
                l.append(s[i])
                print(l)
            else:
                if s[i]==l[-1]:
                    l.pop()
                else:
                    l.append(s[i])
        return "".join(l)
        
