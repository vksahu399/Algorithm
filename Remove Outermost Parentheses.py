class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count=0
        l=[]
        for i in s:
            if i=="(":
                count+=1
                if count>1:
                    l.append(i)
            if  i==')':
                count-=1
                if count>0:
                    l.append(i)
        print(l)
        return "".join(l)
        
