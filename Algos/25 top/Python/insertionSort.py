'''
Insertion Sort
    -> Simple sorting algorithm, follows incremental approach
    -> Its similar to a virtual split and merge system
    -> It works with each element separately and inserts it into respective postion based on the elements
    -> Time Complexity: 
        => O(n^2), Worst case and Avergae case
        => O(n), Best case
    -> Space Complexity: O(1)
'''

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

    return arr

arr = [64, 34, 25, 12, 22, 11, 90]
print(insertionSort(arr))
