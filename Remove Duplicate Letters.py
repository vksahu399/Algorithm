from collections import Counter
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        freq={}
        st=[]
        visited=set()
        for i in range(len(s)):
            freq[s[i]]=i
            
        for i in range(len(s)):
            if s[i] not in visited:
                while st and st[-1]>s[i] and freq[st[-1]]>i:
                    visited.remove(st.pop())
                    
                st.append(s[i])
                visited.add(s[i])
        return "".join(st)
                    
            
        
        
