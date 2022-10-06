class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows<=1:
            return s
        n=['']*numRows
        cr=0
        mod=1
        for i in s:
            n[cr]+=i
            if cr==numRows-1:
                mod=-1
            if cr==0:
                mod=1
            cr+=mod
        return "".join(n)
            
        
