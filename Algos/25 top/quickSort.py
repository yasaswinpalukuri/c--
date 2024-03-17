'''
Quick Sort
    -> Divide and Conquer algorithm
    -> works with pivot element and partitions the array into two sub-arrays
    -> Time Complexity:
        => O(n^2), Worst case
        => O(nlogn), Best case and Average case
    -> Auxiliary Space: O(1)
    -> Sorting In Place: Yes, but it is not a stable sort
'''

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)
    
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quickSort(arr, 0, n-1)
print("Sorted array is: ", arr)