import heapq
from collections import deque
from collections import defaultdict
from __main__ import TrieNode


class Solutions:
    def __init__(self):
        pass
    class ListNode(object):
        def __init__(self, x):
            self.val = x
            self.next = None

    class TreeNode:
        def __init__(self, x):
            self.val = x
            self.left = None
            self.right = None

    class TrieNode:
        def __init__(self):
            self.isEnd = False
            self.children = [None] * 26  # For lowercase English letters

    class TrieNode:
        def __init__(self):
            self.children = {}
            self.is_end_of_word = False

    class Trie:
        def __init__(self):
            self.root = TrieNode()

        def insert(self, word):
            node = self.root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_end_of_word = True

        def search(self, word):
            node = self.root
            for char in word:
                if char not in node.children:
                    return False
                node = node.children[char]
            return node.is_end_of_word

        def startsWith(self, prefix):
            node = self.root
            for char in prefix:
                if char not in node.children:
                    return False
                node = node.children[char]
            return True



    # Day 1: Reverse Prefix of Word - Q2000(Easy)
    '''
    Example 1:

    Input: word = "abcdefd", ch = "d"
    Output: "dcbaefd"
    Explanation: The first occurrence of "d" is at index 3. 
    Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

    Example 2:
    Input: word = "xyxzxe", ch = "z"
    Output: "zxyxxe"
    Explanation: The first and only occurrence of "z" is at index 3.
    Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

    Example 3:
    Input: word = "abcd", ch = "z"
    Output: "abcd"
    Explanation: "z" does not exist in word.
    You should not do any reverse operation, the resulting string is "abcd".
    '''
    def reversePrefix(self, word, ch):
        index = word.find(ch)
        if index != -1:
            word = word[:index+1][::-1] + word[index+1:]
        return word

    '''
    Day 2: Largest Positive Integer That Exists With Its Negative - Q2441(Easy)
    
    Example 1:
    Input: nums = [-1,2,-3,3]
    Output: 3
    Explanation: 3 is the only valid k we can find in the array.
    
    Example 2:
    Input: nums = [-1,10,6,7,-7,1]
    Output: 7
    Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
        
    Example 3:
    Input: nums = [-10,8,6,7,-2,-3]
    Output: -1
    Explanation: There is no a single valid k, we return -1.
    '''
    # Here I am inputing three methods for this problem.
    # Method 1: Using HashSet
    def findMaxK(self, nums):
        num_set = set(nums)
        maxK = float('-inf')
        for num in nums:
            if -num in num_set:
                maxK = max(maxK, num)
        return maxK if maxK != float('-inf') else -1

    # Method 2: Using Sorting
    def findMaxKSorting(self, nums):
        nums.sort()
        maxK = float('-inf')
        for num in nums:
            if -num in nums:
                maxK = max(maxK, num)
        return maxK if maxK != float('-inf') else -1

    # Method 3: Using Two Pointers
    def findMaxK2Pointers(self, nums):
        nums.sort()
        left, right = 0, len(nums) - 1
        maxK = float('-inf')
        while left < right:
            _sum = nums[left] + nums[right]
            if _sum == 0:
                maxK = max(maxK, nums[right])
                left += 1
                right -= 1
            elif _sum < 0:
                left += 1
            else:
                right -= 1
        return maxK if maxK != float('-inf') else -1

    '''
    Day 3: Compare Version Numbers - Q165(Medium)
    Example 1:
    Input: version1 = "1.01", version2 = "1.001"
    Output: 0
    Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
        
    Example 2:
    Input: version1 = "1.0", version2 = "1.0.0"
    Output: 0
    Explanation: version1 does not specify revision 2, which means it is treated as "0".

    Example 3:
    Input: version1 = "0.1", version2 = "1.1"
    Output: -1
    Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
    '''
    def compareVersion(self, v1, v2):
        v1_split = list(map(int, v1.split('.')))
        v2_split = list(map(int, v2.split('.')))
        n1, n2 = len(v1_split), len(v2_split)
        i, j = 0, 0
        while i < n1 or j < n2:
            x1 = v1_split[i] if i < n1 else 0
            x2 = v2_split[j] if j < n2 else 0
            if x1 < x2:
                return -1
            elif x1 > x2:
                return 1
            i += 1
            j += 1
        return 0
    
    '''
    Day 4: Boats to Save People - Q881(Medium)
    
    Example 1:
    Input: people = [1,2], limit = 3
    Output: 1
    Explanation: 1 boat (1, 2)
    
    Example 2:
    Input: people = [3,2,2,1], limit = 3
    Output: 3
    Explanation: 3 boats (1, 2), (2) and (3)
    
    Example 3:
    Input: people = [3,5,3,4], limit = 5
    Output: 4
    Explanation: 4 boats (3), (3), (4), (5)
    '''
    def numRescueBoats(self, people, limit):
        people.sort()
        i, j = 0, len(people) - 1
        boats = 0
        while i <= j:
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
            boats += 1
        return boats

    # Day 5: Delete Node in a Linked List - Q237(Easy)
    '''    
    Example 1:
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

    Example 2:
    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
    '''
    def deleteNode(self, node: ListNode):
        node.val = node.next.val
        node.next = node.next.next

    # Day 6: Remove Nodes From Linked List - Q2487(Medium)
    '''
    Example 1:
    Input: head = [5,2,13,3,8]
    Output: [13,8]
    Explanation: The nodes that should be removed are 5, 2 and 3.
    - Node 13 is to the right of node 5.
    - Node 13 is to the right of node 2.
    - Node 8 is to the right of node 3.

    Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,2,3,4,5]
    Explanation: There are no nodes to remove.
    '''
    def removeNodes(self, head:ListNode) -> ListNode:
        cur = head
        stack = []
        while cur:
            while stack and stack[-1].val < cur.val:
                stack.pop()
            stack.append(cur)
            cur = cur.next
        
        nxt = None
        while stack:
            cur = stack.pop()
            cur.next = nxt
            nxt = cur
        
        return cur
    
    # Day 7: Double a Number Represented as a Linked List - Q2816(Medium)
    '''
    Example 1:
    Input: head = [1,8,9]
    Output: [3,7,8]
    Explanation:
    The figure above corresponds to the given linked list which represents the number 189. 
    Hence, the returned linked list represents the number 189 * 2 = 378.

    Example 2:
    Input: head = [1,2,3,4]
    Output: [2,4,6,8]
    Explanation:
    The figure above corresponds to the given linked list which represents the number 1234.
    Hence, the returned linked list represents the number 1234 * 2 = 2468.
    '''
    def doubleNumber(self, head:ListNode) -> ListNode:
        cur = head
        stack = []
        while cur:
            while stack and stack[-1].val < cur.val:
                stack.pop()
            stack.append(cur)
            cur = cur.next
        
        nxt = None
        while stack:
            cur = stack.pop()
            cur.next = nxt
            nxt = cur
        
        return cur
    
    # Day 8: Relative Ranks - Q506(Easy)
    '''
    Example 1:
    Input: score = [5,4,3,2,1]
    Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
    Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

    Example 2:
    Input: score = [10,3,8,9,4]
    Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
    '''
    def findRelativeRanks(self, score):
        n = len(score)
        rank = sorted(range(n), key=lambda x: score[x], reverse=True)
        res = [0] * n
        for i in range(n):
            if i == 0:
                res[rank[i]] = "Gold Medal"
            elif i == 1:
                res[rank[i]] = "Silver Medal"
            elif i == 2:
                res[rank[i]] = "Bronze Medal"
            else:
                res[rank[i]] = str(i+1)
        return res
    
    # Day 9: Maximize Happiness of Selected Children - Q3075(Medium)
    '''
    Example 1:
    Input: happiness = [1,2,3], k = 2
    Output: 4
    Explanation: We can pick 2 children in the following way:
    - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
    - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
    The sum of the happiness values of the selected children is 3 + 1 = 4.

    Example 2:
    Input: happiness = [1,2,3,4], k = 2
    Output: 6
    Explanation: We can pick 2 children in the following way:
    - Pick the child with the happiness value == 4. The happiness value of the remaining children becomes [0,1,2].
    - Pick the child with the happiness value == 2. The happiness value of the remaining children becomes [0,1].
    The sum of the happiness values of the selected children is 4 + 2 = 6.
    '''
    def maximizeHappiness(self, h, k):
        n = len(h)
        h.sort()
        sum = 0
        for i in range(k):
            h[n-i-1] = max(h[n-i-1]-i,0)
            sum += h[n-i-1]
        return sum
    
    # Day 10: K-th Smallest Prime Fraction - Q786(Medium)
    '''
    Example 1:
    Input: arr = [1,2,3,5], k = 3
    Output: [2,5]
    Explanation: The fractions to be considered in sorted order are:
    1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
    The third fraction is 2/5.
    
    Example 2:
    Input: arr = [1,7], k = 1
    Output: [1,7]
    '''
    def kthSmallestPrimeFraction(self, arr, k):
        pq = []
        def compare(a, b):
            return a[0] - b[0]
        for i in range(len(arr)):
            heapq.heappush(pq, ((arr[i] / arr[-1]), i, len(arr) - 1))
        for _ in range(k - 1):
            cur = heapq.heappop(pq)
            numerator_index = cur[1]
            denominator_index = cur[2] - 1
            if denominator_index > numerator_index:
                heapq.heappush(pq, (
                    (arr[numerator_index] / arr[denominator_index]), 
                    numerator_index, 
                    denominator_index
                ))
        result = heapq.heappop(pq)
        return [arr[result[1]], arr[result[2]]]
    
    # Day 11: Minimum Cost to Hire K Workers - Q857(Hard)
    '''
    Example 1:
    Input: quality = [10,20,5], wage = [70,50,30], k = 2
    Output: 105.00000
    Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
    
    Example 2:
    Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
    Output: 30.66667
    Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
    '''
    def mincostToHireWorkers(self, quality, wage, k):
        n = len(quality)
        workers = sorted([(w/q, q) for w, q in zip(wage, quality)])
        res = float('inf')
        qsum = 0
        heap = []
        for r, q in workers:
            qsum += q
            heapq.heappush(heap, -q)
            if len(heap) > k:
                qsum += heapq.heappop(heap)
            if len(heap) == k:
                res = min(res, qsum*r)
        return res
    
    # Day 12: Largest Local Values in a Matrix - Q2373(Easy)
    '''
    Example 1:
    Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    Output: [[9,9],[8,6]]
    Explanation: The diagram above shows the original matrix and the generated matrix.
    Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
    
    
    Example 2:
    Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
    Output: [[2,2,2],[2,2,2],[2,2,2]]
    Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
    '''
    def find_max(self, grid, x, y):
        max_element = 0
        for i in range(x, x + 3):
            for j in range(y, y + 3):
                max_element = max(max_element, grid[i][j])
        
        return max_element

    def largestLocal(self, grid):
        N = len(grid)
        max_local = [[0] * (N - 2) for _ in range(N - 2)]
        for i in range(N - 2):
            for j in range(N - 2):
                max_local[i][j] = self.find_max(grid, i, j)
        
        return max_local

    # Day 13: Score After Flipping Matrix - Q861(Medium)
    '''
    Example 1:
    Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: grid = [[0]]
    Output: 1
    '''
    def matrixScore(self, grid):
        m = len(grid)
        n = len(grid[0])
        score = (1 << (n - 1)) * m
        for j in range(1, n):
            count_same_bits = 0
            for i in range(m):
                if grid[i][j] == grid[i][0]:
                    count_same_bits += 1
            count_same_bits = max(count_same_bits, m - count_same_bits)
            column_score = (1 << (n - j - 1)) * count_same_bits
            score += column_score

        return score

    # Day 14: Path with Maximum Gold - Q1219(Medium)
    '''
    Example 1:
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    Explanation:
    [[0,6,0],
    [5,8,7],
    [0,9,0]]
    Path to get the maximum gold, 9 -> 8 -> 7.
    
    Example 2:
    Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    Output: 28
    Explanation:
    [[1,0,7],
    [2,0,6],
    [3,4,5],
    [0,3,0],
    [9,0,20]]
    Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
    '''
    def getMaximumGold(self, grid: list[list[int]]) -> int:
        DIRECTIONS = [0, 1, 0, -1, 0]
        rows = len(grid)
        cols = len(grid[0])
        max_gold = 0

        def dfs_backtrack(grid, rows, cols, row, col):
            if row < 0 or col < 0 or row == rows or col == cols or \
                    grid[row][col] == 0:
                return 0
            max_gold = 0
            original_val = grid[row][col]
            grid[row][col] = 0
            for direction in range(4):
                max_gold = max(max_gold,dfs_backtrack(grid, rows, cols, DIRECTIONS[direction] + row,DIRECTIONS[direction + 1] + col))

            grid[row][col] = original_val
            return max_gold + original_val

        for row in range(rows):
            for col in range(cols):
                max_gold = max(max_gold, dfs_backtrack(grid, rows, cols, row, col))
        return max_gold
    
    # Day 15: Find the Safest Path in a Grid - Q2812(Medium)
    '''
    Example 1:
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 0
    Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
    
    
    Example 2:
    Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
    Output: 2
    Explanation: The path depicted in the picture above has a safeness factor of 2 since:
    - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
    It can be shown that there are no other paths with a higher safeness factor.
    

    Example 3:
    Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
    Output: 2
    Explanation: The path depicted in the picture above has a safeness factor of 2 since:
    - The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
    - The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
    It can be shown that there are no other paths with a higher safeness factor.
    '''
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maximumSafenessFactor(self, grid: list[list[int]]) -> int:
        n = len(grid)

        multi_source_queue = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    multi_source_queue.append((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = -1

        while multi_source_queue:
            size = len(multi_source_queue)
            while size > 0:
                curr = multi_source_queue.popleft()
                for d in self.dir:
                    di, dj = curr[0] + d[0], curr[1] + d[1]
                    val = grid[curr[0]][curr[1]]
                    if self.isValidCell(grid, di, dj) and grid[di][dj] == -1:
                        grid[di][dj] = val + 1
                        multi_source_queue.append((di, dj))
                size -= 1

        start, end, res = 0, 0, -1
        for i in range(n):
            for j in range(n):
                end = max(end, grid[i][j])

        while start <= end:
            mid = start + (end - start) // 2
            if self.isValidSafeness(grid, mid):
                res = mid
                start = mid + 1
            else:
                end = mid - 1

        return res
    
    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

    def isValidSafeness(self, grid, min_safeness) -> bool:
        n = len(grid)

        if grid[0][0] < min_safeness or grid[n - 1][n - 1] < min_safeness:
            return False

        traversal_queue = deque([(0, 0)])
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        while traversal_queue:
            curr = traversal_queue.popleft()
            if curr[0] == n - 1 and curr[1] == n - 1:
                return True

            for d in self.dir:
                di, dj = curr[0] + d[0], curr[1] + d[1]
                if self.isValidCell(grid, di, dj) and not visited[di][dj] and grid[di][dj] >= min_safeness:
                    visited[di][dj] = True
                    traversal_queue.append((di, dj))

        return False
    
    # Day 16: Evaluate Boolean Binary Tree - Q2331(Easy)
    '''
    You are given the root of a full binary tree with the following properties:
    * Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
    * on-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
     
    The evaluation of a node is as follows:
    if the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
    Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
        
    Return the boolean result of evaluating the root node.

    A full binary tree is a binary tree where each node has either 0 or 2 children.

    A leaf node is a node that has zero children.

    Example 1:
    Input: root = [2,1,3,null,null,0,1]
    Output: true
    Explanation: The above diagram illustrates the evaluation process.
    The AND node evaluates to False AND True = False.
    The OR node evaluates to True OR False = True.
    The root node evaluates to True, so we return true.


    Example 2:
    Input: root = [0]
    Output: false
    Explanation: The root node is a leaf node and it evaluates to false, so we return false.
    '''
    def evaluateTree(self, root:TreeNode) -> bool:
        if not root.left and not root.right:
            # Handles the case for leaf nodes.
            return root.val != 0

        # Store the evaluations for the left subtree and right subtree.
        evaluate_left_subtree = self.evaluateTree(root.left)
        evaluate_right_subtree = self.evaluateTree(root.right)
        if root.val == 2:
            evaluate_root = evaluate_left_subtree or evaluate_right_subtree
        else:
            evaluate_root = evaluate_left_subtree and evaluate_right_subtree

        return evaluate_root
    
    # Day 17: Delete Leaves With a Given Value - Q1325(Medium)
    '''
    Given a binary tree root and an integer target, delete all the leaf nodes with value target.
    Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
    it should also be deleted (you need to continue doing that until you cannot).

    Example 1:
    Input: root = [1,2,3,2,null,2,4], target = 2
    Output: [1,null,3,null,4]
    Explanation: Leaf nodes in green with value (target = 2) are removed.
    After removing, new nodes become leaf nodes with value (target = 2).
    
    Example 2:
    Input: root = [1,3,3,3,2], target = 3
    Output: [1,3,null,null,2]
    '''
    def removeLeafNodes(self, root:TreeNode, target:int) -> TreeNode:
        if not root:
            return None
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        if not root.left and not root.right and root.val == target:
            return None
        return root
    
    # Day 18: Distribute Coins in Binary Tree - Q979(Medium)
    '''
    You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

    In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

    Return the minimum number of moves required to make every node have exactly one coin.

    Example 1:
    Input: root = [3,0,0]
    Output: 2
    Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

    Example 2:
    Input: root = [0,3,0]
    Output: 3
    Explanation: From the root of the tree, we move one coin to the root's right child, and two coins to the root's left child.
    '''
    def distributeCoins(self, root: TreeNode) -> int:
        self.moves = 0

        def dfs(current):
            if current == None: return 0

            # Calculate the coins each subtree has available to exchange
            left_coins = dfs(current.left)
            right_coins = dfs(current.right)

            # Add the total number of exchanges to moves
            self.moves += abs(left_coins) + abs(right_coins)

            # The number of coins current has available to exchange
            return (current.val - 1) + left_coins + right_coins

        dfs(root)

        return self.moves
    
    # Day 19: Find the Maximum Sum of Node Values - Q3068(Hard)
    '''
    There exists an undirected tree with n nodes numbered 0 to n - 1. 
    You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. 
    You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

    Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

    Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
    nums[u] = nums[u] XOR k
    nums[v] = nums[v] XOR k
    Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
    '''
    def maxSumOfNodes(self, index, isEven, nums, k, memo):
        if index == len(nums):
            # If the operation is performed on an odd number of elements return INT_MIN
            return 0 if isEven == 1 else -float("inf")
        if memo[index][isEven] != -1:
            return memo[index][isEven]

        # No operation performed on the element
        noXorDone = nums[index] + self.maxSumOfNodes(index + 1, isEven, nums, k, memo)
        # XOR operation is performed on the element
        xorDone = (nums[index] ^ k) + self.maxSumOfNodes(
            index + 1, isEven ^ 1, nums, k, memo
        )

        # Memoize and return the result
        memo[index][isEven] = max(xorDone, noXorDone)
        return memo[index][isEven]

    def maximumValueSum(self, nums: list[int], k: int, edges: list[list[int]]) -> int:
        memo = [[-1] * 2 for _ in range(len(nums))]
        return self.maxSumOfNodes(0, 1, nums, k, memo)
    

    # Day 20: Sum of All Subset XOR Totals - Q1863(Easy)
    '''
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums. 

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
    '''
    def subsetXORSum(self, nums: list[int]) -> int:
        res = 0
        for i in range(1 << len(nums)):
            xor = 0
            for j in range(len(nums)):
                if i & (1 << j):
                    xor ^= nums[j]
            res += xor
        return res
    
    # Day 21: Subsets - Q78(Medium)
    '''
        Given an integer array nums of unique elements, return all possible subsets(the power set).
        The solution set must not contain duplicate subsets. Return the solution in any order.
        Example 1:
        Input: nums = [1,2,3]
        Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

        Example 2:

        Input: nums = [0]
        Output: [[],[0]]
    '''
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = []
        def backtrack(start, path):
            res.append(path)
            for i in range(start, len(nums)):
                backtrack(i + 1, path + [nums[i]])
        backtrack(0, [])
        return res
    
    # Day 22: Palindrome Partitoning - Q131(Medium)
    '''
        Given a string s, partition s such that every substring of the partition is a palindrome
        Return all possible palindrome partitioning of s.

        Example 1:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]
        
        Example 2:
        Input: s = "a"
        Output: [["a"]]
    '''
    def partition(self, s: str) -> list[list[str]]:
        def is_palindrome(sub):
            return sub == sub[::-1]
            # [::-1] helps with checking string from -1 to 0
            # [:-1] it is substring from 0 to -1

        def backtrack(start, path):
            if start == len(s):
                result.append(path[:])
                return
            for end in range(start + 1, len(s) + 1):
                if is_palindrome(s[start:end]):
                    backtrack(end, path + [s[start:end]])

        result = []
        backtrack(0, [])
        return result
    
    # Day 23: The Number of Beautiful Subsets - Q2597(Medium)
    '''
        You are given an array nums of positive integers and a positive integer k.
        A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
        Return the number of non-empty beautiful subsets of the array nums.
        A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums.
        Two subsets are different if and only if the chosen indices to delete are different.

        Example 1:
        Input: nums = [2,4,6], k = 2
        Output: 4
        Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
        It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
        
        Example 2:
        Input: nums = [1], k = 1
        Output: 1
        Explanation: The beautiful subset of the array nums is [1].
        It can be proved that there is only 1 beautiful subset in the array [1].
    '''
    def beautifulSubsets(self, nums: list[int], k: int) -> int:
        total_count = 1

        freq_map = defaultdict(dict)
        for num in nums:
            remainder = num % k
            freq_map[remainder][num] = freq_map[remainder].get(num, 0) + 1

        for fr in freq_map.values():
            n = len(fr)

            subsets = sorted(fr.items())
            counts = [0] * (n + 1)
            counts[n] = 1

            for i in range(n - 1, -1, -1):
                skip = counts[i + 1]
                take = 2 ** subsets[i][1] - 1
                if i + 1 < n and subsets[i + 1][0] - subsets[i][0] == k:
                    take *= counts[i + 2]
                else:
                    take *= counts[i + 1]
                counts[i] = skip + take

            total_count *= counts[0]

        return total_count - 1
    

    # Day 24: Maximum Score Words Formed by Letters - Q1255(Hard)
    '''
        Given a list of words, list of  single letters (might be repeating) and score of every character.

        Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

        It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

        

        Example 1:
        Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
        Output: 23
        Explanation:
        Score  a=1, c=9, d=5, g=3, o=2
        Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
        Words "dad" and "dog" only get a score of 21.
        
        Example 2:
        Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
        Output: 27
        Explanation:
        Score  a=4, b=4, c=4, x=5, z=10
        Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
        Word "xxxz" only get a score of 25.
        
        Example 3:
        Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
        Output: 0
        Explanation:
        Letter "e" can only be used once.
    '''
    def maxScoreWords(self, words: list[str], letters: list[str], score: list[int]) -> int:
        W = len(words)
        self.max_score = 0
        freq = [0 for i in range(26)]
        subset_letters = [0 for i in range(26)]
        for c in letters:
            freq[ord(c) - 97] += 1

        def is_valid_word(subset_letters):
            for c in range(26):
                if freq[c] < subset_letters[c]:
                    return False
            else:
                return True
        
        def check(w, words, score, subset_letters, total_score):
            if w == -1:
                self.max_score = max(self.max_score, total_score)
                return
            
            check(w - 1, words, score, subset_letters, total_score)

            L = len(words[w])
            for i in range(L):
                c = ord(words[w][i]) - 97
                subset_letters[c] += 1
                total_score += score[c]

            if is_valid_word(subset_letters):
                check(w - 1, words, score, subset_letters, total_score)
                
            for i in range(L):
                c = ord(words[w][i]) - 97
                subset_letters[c] -= 1
                total_score -= score[c]

        check(W - 1, words, score, subset_letters, 0)
        return self.max_score
    
    # Day 25: Word Break II - Q14(Hard)
    '''
        Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

        Note that the same word in the dictionary may be reused multiple times in the segmentation.

        Example 1:
        Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
        Output: ["cats and dog","cat sand dog"]
        
        Example 2:
        Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
        Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        Explanation: Note that you are allowed to reuse a dictionary word.
        
        Example 3:
        Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        Output: []

        Constraints:
        1 <= s.length <= 20
        1 <= wordDict.length <= 1000
        1 <= wordDict[i].length <= 10
        s and wordDict[i] consist of only lowercase English letters.
        All the strings of wordDict are unique.
        Input is generated in a way that the length of the answer doesn't exceed 10^5.
    '''
    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
        # trie = Solutions.Trie()
        # for word in wordDict:
        #     trie.insert(word)

        # dp = {}

        # for start_idx in range(len(s), -1, -1):
        #     valid_sentences = []

        #     current_node = trie.root

        #     for end_idx in range(start_idx, len(s)):
        #         char = s[end_idx]
        #         index = ord(char) - ord("a")

        #         if not current_node.children[index]:
        #             break

        #         current_node = current_node.children[index]

        #         if current_node.isEnd:
        #             current_word = s[start_idx : end_idx + 1]

        #             if end_idx == len(s) - 1:
        #                 valid_sentences.append(current_word)
        #             else:
        #                 sentences_from_next_index = dp.get(end_idx + 1, [])
        #                 for sentence in sentences_from_next_index:
        #                     valid_sentences.append(
        #                         current_word + " " + sentence
        #                     )
        #     dp[start_idx] = valid_sentences
        # return dp.get(0, [])



def main():
    print("Welcome to May Daily Leetcode Problems")
    print("This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024")
    print("So, without any further ado, let's get started")

    sol = Solutions()

    while True:
        print("Enter the day of the problem you want the answer for or 88 to Exit:")
        print("Day 1: Reverse Prefix of Word")
        print("Day 2: Largest Positive Integer That Exists With Its Negative")
        print("Day 3: Compare Version Numbers")
        print("Day 4: Boats to Save People")
        print("Day 5: Delete Node in a Linked List")
        print("Day 6: Remove Nodes From Linked List")
        print("Day 7: Double a Number Represented as a Linked List")
        print("Day 8: Relative Ranks")
        print("Day 9: Maximize Happiness of Selected Children")
        print("Day 10: K-th Smallest Prime Fraction")
        print("Day 11: Minimum Cost to Hire K Workers")
        print("Day 12: Largest Local Values in a Matrix")
        print("Day 13: Score After Flipping Matrix")
        print("Day 14: Path with Maximum Gold")
        print("Day 15: Find the Safest Path in a Grid")
        print("Day 16: Evaluate Boolean Binary Tree")
        print("Day 17: Delete Leaves With a Given Value")
        print("Day 18: Distribute Coins in Binary Tree")
        print("Day 19: Find the Maximum Sum of Node Values")
        print("Day 20: Sum of All Subset XOR Totals")
        print("Day 21: Subsets")
        print("Day 22: Palindrome Partitoning")
        print("Day 23: The Number of Beautiful Subsets")
        print("Day 24: Maximum Score Words Formed by Letters")
        print("Day 25: Word Break II")
        print("88: Exit")
        
        day = int(input())
        
        if day == 88:
            print("Thank you for using the May Daily Leetcode Problems :)")
            break
        
        if day == 1:
            word = input("Enter the word: ")
            ch = input("Enter the character you want to reverse the prefix of: ")
            print("The word after reversing the prefix of the character is:", sol.reversePrefix(word, ch))
        elif day == 2:
            n = int(input("Enter the number of elements in the array: "))
            nums = []
            for _ in range(n):
                nums.append(int(input("Enter the elements of the array: ")))
            print("The largest positive integer that exists with its negative is (Using HashSet):", sol.findMaxK(nums))
            print("The largest positive integer that exists with its negative is (Using Sorting):", sol.findMaxKSorting(nums))
            print("The largest positive integer that exists with its negative is (Using Two Pointer Technique):", sol.findMaxK2Pointers(nums))
        elif day == 3:
            version1 = input("Enter the first version number: ")
            version2 = input("Enter the second version number: ")
            print("The comparison of the two version numbers is:", sol.compareVersion(version1, version2))
        elif day == 4:
            people = list(map(int, input("Enter the weights of the people: ").split()))
            limit = int(input("Enter the weight limit of the boat: "))
            print("The number of boats required to save all the people is:", sol.numRescueBoats(people, limit))
        elif day == 5:
            nodes = list(map(int, input("Enter the elements of the linked list: ").split()))
            head = sol.ListNode(nodes[0])
            node = head
            for i in nodes[1:]:
                inode = sol.ListNode(i)
                node.next = inode
                node = node.next
            delNode = int(input("Enter the value of the node to be deleted: "))
            d = head
            while d:
                if d.val == delNode:
                    break
                d = d.next
            sol.deleteNode(d)
            print("The linked list after deleting the node is:",end=" ")
            while head:
                print(head.val, end=" ")
                head = head.next
            print()
        elif day == 6:
            nodes = list(map(int, input("Enter the elements of the linked list: ").split()))
            head = sol.ListNode(nodes[0])
            node = head
            for i in nodes[1:]:
                inode = sol.ListNode(i)
                node.next = inode
                node = node.next
            head = sol.removeNodes(head)
            print("The linked list after removing the nodes is:",end=" ")
            while head:
                print(head.val, end=" ")
                head = head.next
            print()
        elif day == 7:
            nodes = list(map(int, input("Enter the elements of the linked list: ").split()))
            head = sol.ListNode(nodes[0])
            node = head
            for i in nodes[1:]:
                inode = sol.ListNode(i)
                node.next = inode
                node = node.next
            head = sol.doubleNumber(head)
            print("The linked list after doubling the number is:",end=" ")
            while head:
                print(head.val, end=" ")
                head = head.next
            print()
        elif day == 8:
            scores = list(map(int, input("Enter the scores of the players: ").split()))
            print("The scores of the players are:", scores)
            print("The relative ranks of the players are:")
            print(sol.findRelativeRanks(scores))
        elif day == 9:
            happiness = list(map(int, input("Enter the happiness values of the children: ").split()))
            k = int(input("Enter the number of children to be picked: "))
            print("The maximum happiness of the selected children is:", sol.maximizeHappiness(happiness, k))
        elif day == 10:
            arr = list(map(int, input("Enter the elements of the array: ").split()))
            k = int(input("Enter the value of k: "))
            print("The k-th smallest prime fraction is:", sol.kthSmallestPrimeFraction(arr, k))
        elif day == 11:
            quality = list(map(int, input("Enter the qualities of the workers: ").split()))
            wage = list(map(int, input("Enter the wages of the workers: ").split()))
            k = int(input("Enter the number of workers to be hired: "))
            print("The minimum cost to hire k workers is:", sol.mincostToHireWorkers(quality, wage, k))
        elif day == 12:
            grid = []
            n = int(input("Enter the number of rows & columns in the matrix: "))
            print("Enter the elements of the matrix row by row:")
            for _ in range(n):
                grid.append(list(map(int, input().split())))
            print("The largest local values in the matrix are:")
            print(sol.largestLocal(grid))
        elif day == 13:
            grid = []
            n = int(input("Enter the number of rows & columns in the matrix: "))
            print("Enter the elements of the matrix row by row:")
            for _ in range(n):
                grid.append(list(map(int, input().split())))
            print("The score after flipping the matrix is:", sol.matrixScore(grid))
        elif day == 14:
            grid = []
            m = int(input("Enter the number of rows in the grid: "))
            n = int(input("Enter the number of columns in the grid: "))
            print("Enter the elements of the grid row by row:")
            for _ in range(m):
                grid.append(list(map(int, input().split())))
            print("The maximum gold that can be collected is:", sol.getMaximumGold(grid))
        elif day == 15:
            grid = []
            n = int(input("Enter the number of rows & columns in the grid: "))
            print("Enter the elements of the grid row by row:")
            for _ in range(n):
                grid.append(list(map(int, input().split())))
            print("The safest path in the grid is:", sol.maximumSafenessFactor(grid))
        elif day == 16:
            root = sol.TreeNode(2)
            root.left = sol.TreeNode(1)
            root.right = sol.TreeNode(3)
            root.right.left = sol.TreeNode(0)
            root.right.right = sol.TreeNode(1)
            print("The evaluation of the boolean binary tree is:", sol.evaluateTree(root))
        elif day == 17:
            root = sol.TreeNode(1)
            root.left = sol.TreeNode(2)
            root.right = sol.TreeNode(3)
            root.left.left = sol.TreeNode(2)
            root.left.right = sol.TreeNode(2)
            root.right.left = sol.TreeNode(0)
            root.right.right = sol.TreeNode(1)
            target = 2
            print("The tree after deleting the leaves with the value target is:", sol.removeLeafNodes(root, target))
        elif day == 18:
            root = sol.TreeNode(3)
            root.left = sol.TreeNode(0)
            root.right = sol.TreeNode(0)
            print("The minimum number of moves required to make every node have exactly one coin is:", sol.distributeCoins(root))
        elif day == 19:
            n = int(input("Enter the number of nodes in the tree:"))
            nums = [0] * n
            print("Enter the values of the nodes in the tree:")
            nums = list(map(int, input().split()))

            k = int(input("Enter the value of k:"))
            
            e = int(input("Enter the number of edges in the tree:"))
            
            edges = []
            print("Enter the edges of the tree:")
            for i in range(e):
                u,v = map(int, input().split())
                edges.append([u, v])
            print("The maximum possible sum of the values Alice can achieve is:", sol.maximumValueSum(nums, k, edges))
        elif day == 20:
            nums = list(map(int, input("Enter the elements of the array: ").split()))
            print("The sum of all XOR totals for every subset of nums is:", sol.subsetXORSum(nums))
        elif day == 21:
            nums = list(map(int, input("Enter the elements of the array: ").split()))
            print("The power set of the array is:", sol.subsets(nums))
        elif day == 22:
            s = input("Enter the string: ")
            print("The palindrome partitioning of the string is:", sol.partition(s))
        elif day == 23:
            nums = list(map(int, input("Enter the elements of the array: ").split()))
            k = int(input("Enter the value of k: "))
            print("The number of non-empty beautiful subsets of the array nums is:", sol.beautifulSubsets(nums, k))
        elif day == 24:
            words = list(map(str, input("Enter the words: ").split()))
            letters = list(map(str, input("Enter the letters: ").split()))
            score = list(map(int, input("Enter the scores of the characters: ").split()))
            print("The maximum score of any valid set of words formed by using the given letters is:", sol.maxScoreWords(words, letters, score))
        elif day == 25:
            s = input("Enter the string: ")
            wordDict = list(map(str, input("Enter the words in the dictionary: ").split()))
            print("The possible sentences formed by the string are:", sol.wordBreak(s, wordDict))
        else:
            print("Sorry, the problem for the day you entered is not available")


if __name__ == "__main__":
    main()
