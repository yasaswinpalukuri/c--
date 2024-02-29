'''
Merge Sort
    -> It is based on Divide and Conquer algorithm
    -> It divides the input array into two halves, calls itself for the two halves and then merges the two sorted halves
    -> Recursive algorithm
    -> Time Complexity: O(nlogn), it is guaranteed to perform O(nlogn) comparisons even in the worst case scenarios
    -> Space Complexity: O(n)
    -> Applications: used in external sorting, Inversion Count Problem, Custom Sorting, etc
    -> Merge Sort is useful for sorting linked lists in O(nLogn) time

'''

def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        mergeSort(L)
        mergeSort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    return arr

arr = [64, 34, 25, 12, 22, 11, 90]
print(mergeSort(arr))