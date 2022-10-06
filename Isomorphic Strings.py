class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d={}
        for i in range(len(s)):
            if s[i] in d:
                if d[s[i]]!=t[i]:
                    return False
            elif t[i] in d.values():
                return False
            else:
                d[s[i]]=t[i]
        return True
