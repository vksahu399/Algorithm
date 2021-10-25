N = int(input("Enter number of elements: "))
Arr = list(map(int,input("Enter the elements: ").strip().split()))[:N]
start = 0
end = N - 1
while start < end:
    temp = Arr[start]
    Arr[start] = Arr[end]
    Arr[end] = temp
    start = start + 1
    end = end - 1
print("Reverse Array:",*Arr)
© 2021 GitHub, Inc.
Terms
Privacy
