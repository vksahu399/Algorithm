class Solution:
    def isAnagram(self, s1: str, t: str) -> bool:
        s=[]
        x=Counter(s1)
        y=Counter(t)
        print(x,y)
        if len(s1)==len(t):
            for k in y.elements():
                if k in x:
                    if y[k]==x[k]:
                        s.append(1)
                    else:
                        s.append(0)
                else:
                    s.append(0)
            print(s)
            for i in s:
                if i!=1:
                    return False
            return True
        return False
        
        
