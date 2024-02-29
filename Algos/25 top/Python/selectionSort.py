'''
Selection Sort
    -> Simple sorting algorithm
    -> It works by selecting the smallest element from the unsorted portion and swapping it with the first element
    -> Time Complexity: O(n^2)
    -> Space Complexity: O(1)
    -> Not stable sort
'''

def selectionSort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

arr = [64, 25, 12, 22, 11]
selectionSort(arr)
print("Sorted array is: ", arr)