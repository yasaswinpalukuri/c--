'''
Binary Search
    -> It can be executed with sorted arrays or lists only
    -> It is a divide and conquer algorithm
    -> We can do it using recursive or iterative approach
    -> Complexities:
        -> Time: O(log n)
        -> Space: recursive => O(log n) as it creates a stack of calls. Iterative => O(1)
'''

def binarySearchRecursive(arr, x, low, high):
    if low > high:
        return -1
    mid = low + (high - low) // 2
    if arr[mid] == x:
        return mid
    elif arr[mid] > x:
        return binarySearchRecursive(arr, x, low, mid - 1)
    else:
        return binarySearchRecursive(arr, x, mid + 1, high)

def binarySearchIterative(arr, x):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1
    return -1

# Test
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
x = 5
print(binarySearchRecursive(arr, x, 0, len(arr) - 1)) if binarySearchRecursive(arr, x, 0, len(arr) - 1) != -1 else print("Element not found")
print(binarySearchIterative(arr, x)) if binarySearchIterative(arr, x, 0, len(arr) - 1) != -1 else print("Element not found")