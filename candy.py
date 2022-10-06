class Solution:
    def candy(self, ratings: List[int]) -> int:
        l=[1]*(len(ratings))
        r=[1]*(len(ratings))
        print(r)
        for i in range(1,len(ratings)):
            if ratings[i-1]<ratings[i]:
                l[i]=l[i-1]+1
        print(l)
        for i in range(len(ratings)-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                r[i]=r[i+1]+1
        print(r)   
        sum=0
        for i in range(len(ratings)):
            sum+=max(l[i],r[i])
        return sum
