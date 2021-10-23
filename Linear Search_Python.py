A=[2,3,4,5,6,7,8]
flag = 0
key=int(input("Enter the element to be searched: "))
for i in range(len(A)):
    if(A[i] == key):
        flag = 1
        break
if(flag == 1):
    print("Element found at position ", i, ".")
else:
    print("Element not found!!!")
