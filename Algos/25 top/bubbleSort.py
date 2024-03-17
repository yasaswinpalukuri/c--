'''
Buuble Sort
    -> Simplest sorting algo
    -> basic concept is to swap adjacent elements if they are not in ascending or descending based on our requirement
    -> Time Complexity: best-case => O(n), worst-case => O(n^2)
    -> Space Complexity: O(1)
    -> Doesn't work with large volumes, as it is a comparison based algorithm

'''

def bubbleSort(arr):
    n = len(arr)
    for i in range(n): # running the loop for length of array
        for j in range(0, n-i-1): # running loop from current element to element in place from the last.
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j] # swapping if condition not satisified
    return arr

arr = [64, 34, 25, 12, 22, 11, 90]
print(bubbleSort(arr))