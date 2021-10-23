# Implementation of Insertion Sort
N = int(input("Enter number of elements: "))
Arr = list(map(int,input("Enter elements: ").strip().split()))[:N]
for i in range(1,N):
    key = Arr[i]
    j = i - 1
    while(j>=0 and Arr[j] >key):
        Arr[j+1] = Arr[j]
        j = j -1
    Arr[j+1] = key
print("Sorted Array: ",*Arr)
        
