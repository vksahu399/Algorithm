class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        while p%2==0 and q%2==0:
            p=p//2
            q=q//2
        if p%2==0 and q%2==1:
            return 2
        elif p%2==1 and q%2==1:
            return 1
        elif p%2==1 and q%2==0:
            return 0
        else:
            return -1
        
