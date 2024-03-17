'''
Knapsack problem
    -> It is an application of dynamic programming
    -> it follows greedy algorithm
    -> It is used to find the maximum weight that can be carried in a bag by placing the objects we have given their weights.
    -> Time Complexity: O(n*W), where n is the number of items and W is the capacity of knapsack.
    -> Space Complexity: O(n*W)+O(n), where n is the number of items and W is the capacity of knapsack.
'''

# This is the memoization approach of 
# 0 / 1 Knapsack in Python in simple 
# we can say recursion + memoization = DP 


def knapsack(wt, val, W, n): 

	# base conditions 
	if n == 0 or W == 0: 
		return 0
	if t[n][W] != -1: 
		return t[n][W] 

	# choice diagram code 
	if wt[n-1] <= W: 
		t[n][W] = max( 
			val[n-1] + knapsack( 
				wt, val, W-wt[n-1], n-1), 
			knapsack(wt, val, W, n-1)) 
		return t[n][W] 
	elif wt[n-1] > W: 
		t[n][W] = knapsack(wt, val, W, n-1) 
		return t[n][W] 

# Driver code 
if __name__ == '__main__': 
	profit = [60, 100, 120] 
	weight = [10, 20, 30] 
	W = 50
	n = len(profit) 
	
	# We initialize the matrix with -1 at first. 
	t = [[-1 for i in range(W + 1)] for j in range(n + 1)] 
	print(knapsack(weight, profit, W, n)) 
