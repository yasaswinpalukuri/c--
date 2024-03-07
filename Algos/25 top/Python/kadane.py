'''
Kadane Algorithm
    -> Used to find largest subarray sum
    -> Time Complexity: O(n)
    -> Space Complexity: O(1)
'''

# Python program to find maximum contiguous subarray

# Function to find the maximum contiguous subarray
from sys import maxsize


def maxSubArraySum(a, size):

	max_so_far = -maxsize - 1
	max_ending_here = 0

	for i in range(0, size):
		max_ending_here = max_ending_here + a[i]
		if (max_so_far < max_ending_here):
			max_so_far = max_ending_here

		if max_ending_here < 0:
			max_ending_here = 0
	return max_so_far


def maxSubArraySumPrint(a, size):
 
    max_so_far = -maxsize - 1
    max_ending_here = 0
    start = 0
    end = 0
    s = 0
 
    for i in range(0, size):
 
        max_ending_here += a[i]
 
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
            start = s
            end = i
 
        if max_ending_here < 0:
            max_ending_here = 0
            s = i+1
 
    print("Maximum contiguous sum is %d" % (max_so_far))
    print("Starting Index %d" % (start))
    print("Ending Index %d" % (end))
# Driver function to check the above function


a = [-2, -3, 4, -1, -2, 1, 5, -3]

print("Maximum contiguous sum is", maxSubArraySum(a, len(a)))
maxSubArraySumPrint(a, len(a))