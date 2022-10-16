def merge_sort(arr):
  return helper(arr, 0, len(arr) - 1)
  
def helper(arr, lo, hi):
  if lo == hi:
    return [arr[lo]]
    
  mid = (lo + hi)//2
  arr1 = helper(arr, lo, mid)
  arr2 = helper(arr, mid + 1, hi)
  i1 = 0
  i2 = 0
  new_arr = [0 for _ in range(hi - lo + 1)]
  
  while i1 < len(arr1) or i2 < len(arr2):
    if i1 < len(arr1) and (not i2 < len(arr2) or arr1[i1] < arr2[i2]):
      new_arr[i1 + i2] = arr1[i1]
      i1 += 1
    else:
      new_arr[i1 + i2] = arr2[i2]  
      i2 += 1
  return new_arr
  
if __name__ == '__main__':
    arr = [37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54]
    print(f'List: {arr}')
    print('Sorting...')
    sorted_arr = merge_sort(arr)
    print(f'List: {sorted_arr}')
