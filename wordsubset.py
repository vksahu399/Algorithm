from collections import Counter
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        
        res=set(words1)     
        l={}
        for i in words2:
            for j in i:
                count=i.count(j)
                if j not in l or count>l[j]:
                    l[j]=count
        print(l)
        for i in words1:
            for j in l:
                if i.count(j)<l[j]:
                    res.remove(i)
                    break
        print(res)
        return list(res)
                
        
        
        
        
        
        
        
        
        
        
        
