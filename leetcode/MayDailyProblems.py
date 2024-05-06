class Solutions:
    def __init__(self):
        pass
    class ListNode(object):
        def __init__(self, x):
            self.val = x
            self.next = None

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
        else:
            print("Sorry, the problem for the day you entered is not available")


if __name__ == "__main__":
    main()
