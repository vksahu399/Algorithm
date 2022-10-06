class Solution:
    def reverseWords(self, s: str) -> str:
        l=s.split(" ")
        print(l)
        x=[]
        for i in l:
            x.append(i[::-1])
        print(x)
        return " ".join(x)
            
