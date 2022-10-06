class MyCalendar:

    def __init__(self):
        self.l=[]

    def book(self, start: int, end: int) -> bool:
        for i,j in self.l:
            if i<end and j>start:
                return False
        self.l.append([start,end])
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
