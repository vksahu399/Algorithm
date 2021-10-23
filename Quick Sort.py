# Implementation of Quick Sort

# Function to swap values
def swap(Arr,i,j):
    temp = Arr[i]
    Arr[i] = Arr[j]
    Arr[j] = temp
    
# Function to find the partition position   
def partition(Arr,l,r):
    pivot = Arr[r]
    i = l - 1
    for j in range(l,r):
        if Arr[j] < pivot:
            i = i + 1
            swap(Arr,i,j)
    swap(Arr,i+1,r)
    return i+1

# Function to perform quicksort   
def QuickSort(Arr,l,r):
    if l < r:
        pi = partition(Arr,l,r)
        QuickSort(Arr,l,pi-1)
        QuickSort(Arr,pi+1,r)
    
N = int(input("Enter number of elements: "))
Arr = list(map(int,input("Enter elements: ").strip().split()))[:N]
QuickSort(Arr,0,N-1)
print("Sorted Array: ",*Arr)
