package leetcode;
import java.util.*;

// This File consists of all the problems solved in May Daily Leetcode Challenge 2024
public class MayDailyProblems {
    class ListNode{
        int val;
        ListNode next;
        ListNode(int val){
            this.val = val;
        }
        ListNode(int val, ListNode next){
            this.val = val; this.next = next;
        }
    }
    class TrieNode {

        boolean isEnd;
        TrieNode[] children;
    
        TrieNode() {
            isEnd = false;
            children = new TrieNode[26];
        }
    }
    
    class Trie {
    
        TrieNode root;
    
        Trie() {
            root = new TrieNode();
        }
    
        void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEnd = true;
        }
    }
    
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Welcome to May Daily Leetcode Problems");
        System.out.println("This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024");
        System.out.println("So, without any further ado, let's get started");
        do{
            System.out.println("Enter the day of the problem you want the answer for or 88 to Exit:");
            System.out.println("Day 1: Reverse Prefix of Word");
            System.out.println("Day 2: Largest Positive Integer That Exists With Its Negative");
            System.out.println("Day 3: Compare Version Numbers");
            System.out.println("Day 4: Boats to Save People");
            System.out.println("Day 5: Delete Node in a Linked List");
            System.out.println("Day 6: Remove Nodes From Linked List");
            System.out.println("Day 7: Double a Number Represented as a Linked List");
            System.out.println("Day 8: Relative Ranks");
            System.out.println("Day 9: Maximize Happiness of Selected Children");
            System.out.println("Day 10: K-th Smallest Prime Fraction");
            System.out.println("Day 11: Minimum Cost to Hire K Workers");
            System.out.println("Day 12: Largest Local Values in a Matrix");
            System.out.println("Day 13: Score After Flipping Matrix");
            System.out.println("Day 14: Path with Maximum Gold");
            System.out.println("Day 15: Find the Safest Path in a Grid");
            System.out.println("Day 16: Evaluate Boolean Binary Tree");
            System.out.println("Day 17: Delete Leaves With a Given Value");
            System.out.println("Day 18: Distribute Coins in Binary Tree");
            System.out.println("Day 19: Find the Maximum Sum of Node Values");
            System.out.println("Day 20: Sum of All Subset XOR Totals");
            System.out.println("Day 21: Subsets");
            System.out.println("Day 22: Palindrome Partitioning");
            System.out.println("Day 23: The Number of Beautiful Subsets");
            System.out.println("Day 24: Maximum Score Words Formed by Letters");
            System.out.println("Day 25: Word Break II");
            System.out.println("Day 26: Student Attendance Record II");
            System.out.println("Day 27: Special Array With X Elements Greater Than or Equal X");
            System.out.println("Day 28: Get Equal Substrings Within Budget");
            System.out.println("88: Exit");
            int day = scan.nextInt();
            switch(day){
                case 1:
                    System.out.println("Enter the word and the character you want to reverse the prefix of:");
                    String word = scan.next();
                    char ch = scan.next().charAt(0);
                    System.out.println("The word after reversing the prefix of the character is: " + reversePrefix(word, ch));
                    break;
                case 2:
                    System.out.println("Enter the number of elements in the array:");
                    int n = scan.nextInt();
                    int[] nums = new int[n];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n; i++) {
                        nums[i] = scan.nextInt();
                    }
                    System.out.println("The largest positive integer that exists with its negative is(Using HashSet): " + findMaxK(nums));
                    System.out.println("The largest positive integer that exists with its negative is(Using Arrays.sort and Arrays.binarySearch): " + findMaxKSorting(nums));
                    System.out.println("The largest positive integer that exists with its negative is(Using Two Pointer Technique): " + findMaxK2Pointers(nums));
                    break;
                case 3:
                    System.out.println("Enter the two version numbers you want to compare:");
                    String version1 = scan.next();
                    String version2 = scan.next();
                    System.out.println("The comparison of the two version numbers is: " + compareVersion(version1, version2));
                    break;
                case 4:
                    System.out.println("Enter the number of people and the limit of the boat:");
                    int n1 = scan.nextInt();
                    int[] people = new int[n1];
                    for (int i = 0; i < n1; i++) {
                        people[i] = scan.nextInt();
                    }
                    int limit = scan.nextInt();
                    System.out.println("The number of boats required to save the people is: " + numRescueBoats(people, limit));
                    break;
                case 5:
                    System.out.println("Enter the number of elements in the linked list:");
                    int n2 = scan.nextInt();
                    System.out.println("Enter the elements of the linked list:");
                    ListNode head = new MayDailyProblems().new ListNode(scan.nextInt());
                    ListNode temp = head;
                    for (int i = 1; i < n2; i++) {
                        temp.next = new MayDailyProblems().new ListNode(scan.nextInt());
                        temp = temp.next;
                    }
                    System.out.println("Enter the node value you want to delete:");
                    int nodeVal = scan.nextInt();
                    ListNode node = head;
                    while (node.val != nodeVal) {
                        node = node.next;
                    }
                    deleteNode(node);
                    System.out.println("The linked list after deleting the node is:");
                    while (head != null) {
                        System.out.print(head.val + " ");
                        head = head.next;
                    }
                    System.out.println();
                    break;
                case 6:
                    System.out.println("Enter the number of elements in the linked list:");
                    int n3 = scan.nextInt();
                    System.out.println("Enter the elements of the linked list:");
                    ListNode head1 = new MayDailyProblems().new ListNode(scan.nextInt());
                    ListNode temp1 = head1;
                    for (int i = 1; i < n3; i++) {
                        temp1.next = new MayDailyProblems().new ListNode(scan.nextInt());
                        temp1 = temp1.next;
                    }
                    ListNode res = removeNodes(head1);
                    System.out.println("The linked list after removing the nodes is:");
                    while (res != null) {
                        System.out.print(res.val + " ");
                        res = res.next;
                    }
                    System.out.println();
                    break;
                case 7:
                    System.out.println("Enter the number of elements in the linked list:");
                    int n4 = scan.nextInt();
                    System.out.println("Enter the elements of the linked list:");
                    ListNode head2 = new MayDailyProblems().new ListNode(scan.nextInt());
                    ListNode temp2 = head2;
                    for (int i = 1; i < n4; i++) {
                        temp2.next = new MayDailyProblems().new ListNode(scan.nextInt());
                        temp2 = temp2.next;
                    }
                    break;
                case 8:
                    System.out.println("Enter the number of elements in the array:");
                    int n5 = scan.nextInt();
                    int[] score = new int[n5];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n5; i++) score[i] = scan.nextInt();
                    System.out.println("The scores are: " + Arrays.toString(score));
                    System.out.println("The relative ranks of the scores are: " + Arrays.toString(findRelativeRanks(score)));
                    break;
                case 9:
                    System.out.println("Enter the number of elements in the array:");
                    int n6 = scan.nextInt();
                    int[] happiness = new int[n6];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n6; i++) happiness[i] = scan.nextInt();
                    System.out.println("Enter the number of children you want to select:");
                    int k = scan.nextInt();
                    System.out.println("The maximum happiness of the selected children is: " + maximumHappinessSum(happiness, k));
                    break;
                case 10:
                    System.out.println("Enter the number of elements in the array:");
                    int n7 = scan.nextInt();
                    int[] arr = new int[n7];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n7; i++) arr[i] = scan.nextInt();
                    System.out.println("Enter the value of k:");
                    int k1 = scan.nextInt();
                    System.out.println("The k-th smallest prime fraction is: " + Arrays.toString(kthSmallestPrimeFraction(arr, k1)));
                    break;
                case 11:
                    System.out.println("Enter the number of workers:");
                    int n8 = scan.nextInt();
                    int[] quality = new int[n8];
                    int[] wage = new int[n8];
                    System.out.println("Enter the quality of the workers:");
                    for (int i = 0; i < n8; i++) quality[i] = scan.nextInt();
                    System.out.println("Enter the wage of the workers:");
                    for (int i = 0; i < n8; i++) wage[i] = scan.nextInt();
                    System.out.println("Enter the number of workers you want to hire:");
                    int k2 = scan.nextInt();
                    System.out.println("The minimum cost to hire the workers is: " + minCostToHireWorkers(quality, wage, k2));
                    break;
                case 12:
                    System.out.println("Enter the number of rows and columns in the matrix:");
                    int n12 = scan.nextInt();
                    int[][] grid = new int[n12][n12];
                    System.out.println("Enter the elements of the matrix:");
                    for (int i = 0; i < n12; i++) {
                        for (int j = 0; j < n12; j++) {
                            grid[i][j] = scan.nextInt();
                        }
                    }
                    System.out.println("The largest local values in the matrix are: " + Arrays.deepToString(largestLocal(grid)));
                    break;
                case 13:
                    System.out.println("Enter the number of rows and columns in the matrix:");
                    int n13 = scan.nextInt();
                    int[][] grid1 = new int[n13][n13];
                    System.out.println("Enter the elements of the matrix:");
                    for (int i = 0; i < n13; i++) {
                        for (int j = 0; j < n13; j++) {
                            grid1[i][j] = scan.nextInt();
                        }
                    }
                    System.out.println("The score after flipping the matrix is: " + matrixScore(grid1));
                    break;
                case 14:
                    System.out.println("Enter the number of rows in the matrix:");
                    int m14 = scan.nextInt();
                    System.out.println("Enter the number of columns in the matrix:");
                    int n14 = scan.nextInt();
                    int[][] grid2 = new int[m14][n14];
                    System.out.println("Enter the elements of the matrix:");
                    for (int i = 0; i < m14; i++) {
                        for (int j = 0; j < n14; j++) {
                            grid2[i][j] = scan.nextInt();
                        }
                    }
                    System.out.println("The maximum gold that can be obtained is: " + getMaximumGold(grid2));
                    break;
                case 15:
                    System.out.println("Enter the number of rows in the grid:");
                    int n15 = scan.nextInt();
                    List<List<Integer>> grid3 = new ArrayList<>();
                    System.out.println("Enter the elements of the grid:");
                    for (int i = 0; i < n15; i++) {
                        List<Integer> row = new ArrayList<>();
                        for (int j = 0; j < n15; j++) {
                            row.add(scan.nextInt());
                        }
                        grid3.add(row);
                    }
                    System.out.println("The maximum safeness factor of the path is: " + maximumSafenessFactor(grid3));
                    break;
                case 16:
                    System.out.println("Enter the root value:");
                    int rootValue = scan.nextInt();
                    TreeNode root = new TreeNode(rootValue);
                    buildTree(scan, root);
                    System.out.println("The boolean evaluation of the binary tree is: " + evaluateTree(root));
                    break;
                case 17:
                    System.out.println("Enter the root value:");
                    int rootValue1 = scan.nextInt();
                    TreeNode root1 = new TreeNode(rootValue1);
                    buildTree(scan, root1);
                    System.out.println("Enter the value of the node you want to delete:");
                    int target = scan.nextInt();
                    System.out.print("The tree after deleting the leaves with the given value is: ");
                    printTree(removeLeafNodes(root1, target));
                    System.out.println();
                    break;
                case 18:
                    System.out.println("Enter the root value:");
                    int rootValue2 = scan.nextInt();
                    TreeNode root2 = new TreeNode(rootValue2);
                    buildTree(scan, root2);
                    System.out.println("The minimum number of moves required to distribute the coins in the binary tree is: " + distributeCoins(root2));
                    break;
                case 19:
                    System.out.println("Enter the number of nodes in the tree:");
                    int n19 = scan.nextInt();
                    int[] nums19 = new int[n19];
                    System.out.println("Enter the values of the nodes in the tree:");
                    for (int i = 0; i < n19; i++) {
                        nums19[i] = scan.nextInt();
                    }
                    System.out.println("Enter the value of k:");
                    int k19 = scan.nextInt();
            
                    System.out.println("Enter the number of edges in the tree:");
                    int e = scan.nextInt();
                    System.out.println("Enter the edges of the tree:");
                    int[][] edges19 = new int[e][2];
                    for (int i = 0; i < e; i++) {
                        edges19[i][0] = scan.nextInt();
                        edges19[i][1] = scan.nextInt();
                    }
                    System.out.println("The maximum sum of node values is: " + maximumValueSum(nums19, k19, edges19));
                    break;
                case 20:
                    System.out.println("Enter the number of elements in the array:");
                    int n20 = scan.nextInt();
                    int[] nums20 = new int[n20];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n20; i++) {
                        nums20[i] = scan.nextInt();
                    }
                    System.out.println("The sum of all subset XOR totals is: " + subsetXORSum(nums20));
                    break;
                case 21:
                    System.out.println("Enter the number of elements in the array:");
                    int n21 = scan.nextInt();
                    int[] nums21 = new int[n21];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n21; i++) {
                        nums21[i] = scan.nextInt();
                    }
                    System.out.println("The subsets of the array are: " + subsets(nums21));
                    break;
                case 22:
                    System.out.println("Enter the string:");
                    String s22 = scan.next();
                    System.out.println("The palindrome partitioning of the array is: " + partition(s22));
                    break;
                case 23:
                    System.out.println("Enter the number of elements in the array:");
                    int n23 = scan.nextInt();
                    int[] nums23 = new int[n23];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n23; i++) {
                        nums23[i] = scan.nextInt();
                    }
                    System.out.println("Enter the value of k:");
                    int k23 = scan.nextInt();
                    System.out.println("The number of beautiful subsets is: " + beautifulSubsets(nums23, k23));
                    break;
                case 24:
                    System.out.println("Enter the number of words:");
                    int n24 = scan.nextInt();
                    String[] words24 = new String[n24];
                    System.out.println("Enter the words:");
                    for (int i = 0; i < n24; i++) {
                        words24[i] = scan.next();
                    }
                    System.out.println("Enter the number of letters:");
                    int n25 = scan.nextInt();
                    char[] letters24 = new char[n25];
                    System.out.println("Enter the letters:");
                    for (int i = 0; i < n25; i++) {
                        letters24[i] = scan.next().charAt(0);
                    }
                    int[] scores24 = new int[26];
                    System.out.println("Enter the scores:");
                    for (int i = 0; i < 26; i++) {
                        scores24[i] = scan.nextInt();
                    }
                    System.out.println("The maximum score words formed by the letters is: " + maxScoreWords(words24, letters24, scores24));
                    break;
                case 25:
                    System.out.println("Enter the string:");
                    String s25 = scan.next();
                    System.out.println("Enter the number of words:");
                    int nw = scan.nextInt();
                    List<String> wordDict = new ArrayList<>();
                    System.out.println("Enter the words:");
                    for (int i = 0; i < nw; i++) {
                        wordDict.add(scan.next());
                    }
                    System.out.println("The word break II is: " + wordBreak(s25, wordDict));
                    break;
                case 26:
                    System.out.println("Enter the number of students:");
                    int n26 = scan.nextInt();
                    System.out.println("The number of possible attendance records is: " + checkRecord(n26));
                    break;
                case 27:
                    System.out.println("Enter the number of elements in the array:");
                    int n27 = scan.nextInt();
                    int[] nums27 = new int[n27];
                    System.out.println("Enter the elements of the array:");
                    for (int i = 0; i < n27; i++) {
                        nums27[i] = scan.nextInt();
                    }
                    System.out.println("The number of special arrays is: " + specialArray(nums27));
                    break;
                case 28:
                    System.out.println("Enter the string:");
                    String s28 = scan.next();
                    System.out.println("Enter the string:");
                    String t28 = scan.next();
                    System.out.println("Enter the maximum cost:");
                    int maxCost = scan.nextInt();
                    System.out.println("The equal substrings within budget are: " + equalSubstring(s28, t28, maxCost));
                    break;
                case 88:
                    System.out.println("Thank you for using the May Daily Leetcode Problems :)");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Sorry, the problem for the day you entered is not available");
                    break;
            }
        }while(true);
    }

    // 2000 May 1: Reverse Prefix of Word - Easy
    /*
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
     */
    static public String reversePrefix(String word, char ch) {
        int index = -1;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                index = i;
                break;
            }
        }
        String fh = word.substring(0, index + 1);
        String sh = word.substring(index + 1);
        
        StringBuilder sb = new StringBuilder(fh);
        sb.reverse();
        sb.append(sh);
        
        return sb.toString();
    }

    // 2441 - Largest Positive Integer That Exists With Its Negative - Easy
    /*
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
    */
    // Here I am inputing three methods for this problem.
    // Method 1: Using HashSet
    static public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int maxK = Integer.MIN_VALUE;
        for (int num : nums) {
            if (set.contains(-num)) {
                maxK = Math.max(maxK, num);
            }
        }
        return maxK != Integer.MIN_VALUE ? maxK : -1;
    }
    // Method 2: Using Sorting
    static public int findMaxKSorting(int[] nums) {
        Arrays.sort(nums);
        int maxK = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (Arrays.binarySearch(nums, -nums[i]) >= 0) {
                maxK = Math.max(maxK, nums[i]);
            }
        }
        return maxK != Integer.MIN_VALUE ? maxK : -1;
    }
    // Method 3: Using Two Pointers
    static public int findMaxK2Pointers(int[] nums) {
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1;
        int maxK = Integer.MIN_VALUE;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == 0) {
                maxK = Math.max(maxK, nums[right]);
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
        return maxK != Integer.MIN_VALUE ? maxK : -1;
    }

    // Day 3: Compare Version Numbers - Q165(Medium)
    /*
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
    */
    static public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        for(int i=0;i<Math.max(v1.length,v2.length);i++){
            int num1 = i<v1.length ? Integer.parseInt(v1[i]) : 0;
            int num2 = i<v2.length ? Integer.parseInt(v2[i]) : 0;
            if(num1<num2){
                return -1;
            }
            if(num1>num2){
                return 1;
            }
        }
        return 0;
    }

    // Day 4: Boats to Save People - Q881(Medium)
    /*
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
    */

    static public int numRescueBoats(int[] p, int limit) {
        Arrays.sort(p);
        int l = 0, ans = 0, r = p.length-1;
        while(l <= r){
            ans++;
            if(p[l] + p[r] <= limit) l++;
            r--;
        }
        return ans;
    }

    // Day 5: Delete Node in a Linked List - Q237(Easy)
    /*
    Example 1:
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

    Example 2:
    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
    */
    static public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }


    // Day 6: Remove Nodes From Linked List - Q2487(Medium)
    /*
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
    */
    static public ListNode removeNodes(ListNode head) {
        ListNode cur = head;
        Stack<ListNode> stack = new Stack<>();
        
        while (cur != null) {
            while (!stack.isEmpty() && stack.peek().val < cur.val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur.next;
        }
        
        ListNode nxt = null;
        while (!stack.isEmpty()) {
            cur = stack.pop();
            cur.next = nxt;
            nxt = cur;
        }
        
        return cur;
    }


    // Day 7: Double a Number Represented as a Linked List - Q2816(Medium)
    /*
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
    */
    static public ListNode doubleIt(ListNode head) {
        if (head.val > 4) {
            head = new MayDailyProblems().new ListNode(0, head);
        }
        ListNode temp = head;
        while (temp != null) {
            temp.val = (temp.val * 2) % 10;
            if (temp.next != null && temp.next.val > 4) {
                temp.val++;
            }
            temp = temp.next;
        }
        return head;
    }


    // Day 8: Relative Ranks - Q506(Easy)
    /*
    Example 1:
    Input: score = [5,4,3,2,1]
    Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
    Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

    Example 2:
    Input: score = [10,3,8,9,4]
    Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
    */
    static public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        String[] res = new String[n];
        int[] temp = Arrays.copyOf(score, n);
        Arrays.sort(temp);
        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                map.put(temp[i], "Gold Medal");
            } else if (i == n - 2) {
                map.put(temp[i], "Silver Medal");
            } else if (i == n - 3) {
                map.put(temp[i], "Bronze Medal");
            } else {
                map.put(temp[i], String.valueOf(n - i));
            }
        }
        for (int i = 0; i < n; i++) {
            res[i] = map.get(score[i]);
        }
        return res;
    }

    // Day 9: Maximize Happiness of Selected Children - Q3075(Medium)
    /*
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
    */
    static public long maximumHappinessSum(int[] h, int k) {
        Arrays.sort(h);
        int n = h.length;
        long ans = 0;
        for(int i=0;i<k;i++) h[n-i-1] = Math.max(0, h[n-i-1]-i);
        for(int i=0;i<k;i++) ans += h[n-i-1];
        return ans;
    }

    // Day 10: K-th Smallest Prime Fraction - Q786(Medium)
    /*
    Example 1:
    Input: arr = [1,2,3,5], k = 3
    Output: [2,5]
    Explanation: The fractions to be considered in sorted order are:
    1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
    The third fraction is 2/5.
    
    Example 2:
    Input: arr = [1,7], k = 1
    Output: [1,7]
    */
    static public int[] kthSmallestPrimeFraction(int[] arr, int k){
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        for (int i = 0; i < arr.length; i++) {
            pq.offer(new double[] {
                -1.0 * arr[i] / arr[arr.length - 1], 
                i, 
                arr.length - 1
            });
        }
        while (--k > 0) {
            double[] cur = pq.poll();
            int numeratorIndex = (int) cur[1];
            int denominatorIndex = (int) cur[2] - 1;
            if (denominatorIndex > numeratorIndex) {
                pq.offer(new double[] {
                        -1.0 * arr[numeratorIndex] / arr[denominatorIndex], 
                        numeratorIndex, 
                        denominatorIndex
                });
            }
        }
        double[] result = pq.poll();
        return new int[]{arr[(int) result[1]], arr[(int) result[2]]};
    }


    // Day 11: Minimum Cost to Hire K Workers - Q857(Hard)
    /*
    Example 1:
    Input: quality = [10,20,5], wage = [70,50,30], k = 2
    Output: 105.00000
    Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
    
    Example 2:
    Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
    Output: 30.66667
    Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
    */
    static public double minCostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i] = new double[]{(double) wage[i] / quality[i], (double) quality[i]};
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        double ans = Double.MAX_VALUE;
        double sum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>((a, b) -> Double.compare(b, a));
        for (double[] worker : workers) {
            sum += worker[1];
            pq.offer(worker[1]);
            if (pq.size() > k) {
                sum -= pq.poll();
            }
            if (pq.size() == k) {
                ans = Math.min(ans, sum * worker[0]);
            }
        }
        return ans;
    }

    // Day 12: Largest Local Values in a Matrix - Q2373(Easy)
    /*
    Example 1:
    Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    Output: [[9,9],[8,6]]
    Explanation: The diagram above shows the original matrix and the generated matrix.
    Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
    
    
    Example 2:
    Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
    Output: [[2,2,2],[2,2,2],[2,2,2]]
    Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
    */
    static public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] res = new int[n - 2][n - 2];

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = Math.max(temp, grid[k][l]);
                    }
                }

                res[i - 1][j - 1] = temp;
            }
        }

        return res;
    }



    // Day 13: Score After Flipping Matrix - Q861(Medium)
    /*
    Example 1:
    Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: grid = [[0]]
    Output: 1
    */
    static public int matrixScore(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += grid[i][j];
            }
            res += Math.max(cnt, n - cnt) * (1 << (m - j - 1));
        }
        return res;
    }

    // Day 14: Path with Maximum Gold - Q1219(Medium)
    /*
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
    */
    static final int[] DIRECTIONS = new int[] { 0, 1, 0, -1, 0 };

    static public int getMaximumGold(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int maxGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxGold = Math.max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
            }
        }
        return maxGold;
    }

    static private int dfsBacktrack(int[][] grid, int rows, int cols, int row, int col){
        if (row < 0 || col < 0 || row == rows || col == cols || grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;
        int originalVal = grid[row][col];
        grid[row][col] = 0;
        for (int direction = 0; direction < 4; direction++) {
            maxGold = Math.max(maxGold,
                    dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row,DIRECTIONS[direction + 1] + col));
        }
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }


    // Day 15: Find the Safest Path in a Grid - Q2812(Medium)
    /*
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
    */
    static final int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    static public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] mat = new int[n][n];
        Queue<int[]> multiSourceQueue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    multiSourceQueue.add(new int[]{i, j});
                    mat[i][j] = 0;
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        while (!multiSourceQueue.isEmpty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                int[] curr = multiSourceQueue.poll();
                for (int[] d : dir) {
                    int di = curr[0] + d[0];
                    int dj = curr[1] + d[1];
                    int val = mat[curr[0]][curr[1]];
                    if (isValidCell(mat, di, dj) && mat[di][dj] == -1) {
                        mat[di][dj] = val + 1;
                        multiSourceQueue.add(new int[]{di, dj});
                    }
                }
            }
        }
        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                end = Math.max(end, mat[i][j]);
            }
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(mat, mid)) {
                res = mid; 
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }

    static private boolean isValidSafeness(int[][] grid, int minSafeness) {
        int n = grid.length;
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        Queue<int[]> traversalQueue = new LinkedList<>();
        traversalQueue.add(new int[]{0, 0});
        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;
        while (!traversalQueue.isEmpty()) {
            int[] curr = traversalQueue.poll();
            if (curr[0] == n - 1 && curr[1] == n - 1) {
                return true;
            }
            for (int[] d : dir) {
                int di = curr[0] + d[0];
                int dj = curr[1] + d[1];
                if (isValidCell(grid, di, dj) && !visited[di][dj] && grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.add(new int[]{di, dj});
                }
            }
        }

        return false;
    }

    static private boolean isValidCell(int[][] mat, int i, int j) {
        int n = mat.length;
        return i >= 0 && j >= 0 && i < n && j < n;
    }


    // Day 16: Evaluate Boolean Binary Tree - Q2331(Easy)
    /*
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
    */
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public static void buildTree(Scanner scanner, TreeNode node) {
        System.out.println("Does " + node.val + " have a left child? (y/n)");
        String choice = scanner.next();
        if (choice.equals("y")) {
            System.out.println("Enter the value for the left child of " + node.val + ":");
            int leftValue = scanner.nextInt();
            node.left = new TreeNode(leftValue);
            buildTree(scanner, node.left);
        }
        System.out.println("Does " + node.val + " have a right child? (y/n)");
        choice = scanner.next();
        if (choice.equals("y")) {
            System.out.println("Enter the value for the right child of " + node.val + ":");
            int rightValue = scanner.nextInt();
            node.right = new TreeNode(rightValue);
            buildTree(scanner, node.right);
        }
    }
    static public boolean evaluateTree(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root.val != 0;
        }
        boolean evaluateLeftSubtree = evaluateTree(root.left);
        boolean evaluateRightSubtree = evaluateTree(root.right);
        boolean evaluateRoot;
        if (root.val == 2) {
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        } else {
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        }

        return evaluateRoot;
    }



    // Day 17: Delete Leaves With a Given Value - Q1325(Medium)
    /*
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
    */
    public static void printTree(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.print(root.val + " ");
        printTree(root.left);
        printTree(root.right);
    }
    static public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) return null;
        root.left = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);
        if (root.left == null && root.right == null && root.val == target) {
            return null;
        }
        return root;
    }



    // Day 18: Distribute Coins in Binary Tree - Q979(Medium)
    /*
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
    */
    static int moves;

    static public int distributeCoins(TreeNode root) {
        moves = 0;
        dfsDay18(root);
        return moves;
    }

    static public int dfsDay18(TreeNode current) {
        if (current == null)
            return 0;

        // Calculate the coins each subtree has available to exchange
        int leftCoins = dfsDay18(current.left);
        int rightCoins = dfsDay18(current.right);

        // Add the total number of exchanges to moves
        moves += Math.abs(leftCoins) + Math.abs(rightCoins);

        // The number of coins current has available to exchange
        return (current.val - 1) + leftCoins + rightCoins;
    }



    // Day 19: Find the Maximum Sum of Node Values - Q3068(Hard)
    /*
    There exists an undirected tree with n nodes numbered 0 to n - 1. 
    You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. 
    You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

    Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

    Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
    nums[u] = nums[u] XOR k
    nums[v] = nums[v] XOR k
    Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
    */
    static public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long[][] memo = new long[nums.length][2];
        for (long[] row : memo) {
            Arrays.fill(row, -1);
        }
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

    static private long maxSumOfNodes(int index, int isEven, int[] nums, int k,
            long[][] memo) {
        if (index == nums.length) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : Integer.MIN_VALUE;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long xorDone = (nums[index] ^ k) +
                maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = Math.max(xorDone, noXorDone);
    }


    // Day 20: Sum of All Subset XOR Totals - Q1863(Easy)
    /*
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums. 

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
    */
    static public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xor = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    xor ^= nums[j];
                }
            }
            sum += xor;
        }
        return sum;
    }


    // Day 21: Subsets - Q78(Medium)
    /*
        Given an integer array nums of unique elements, return all possible subsets(the power set).
        The solution set must not contain duplicate subsets. Return the solution in any order.
        Example 1:
        Input: nums = [1,2,3]
        Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

        Example 2:

        Input: nums = [0]
        Output: [[],[0]]
    */
    static public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        for (int num : nums) {
            int size = res.size();
            for (int i = 0; i < size; i++) {
                List<Integer> subset = new ArrayList<>(res.get(i));
                subset.add(num);
                res.add(subset);
            }
        }
        return res;
    }


    // Day 22: Palindrome Partitoning - Q131(Medium)
    /*
        Given a string s, partition s such that every substring of the partition is a palindrome
        Return all possible palindrome partitioning of s.

        Example 1:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]
        
        Example 2:
        Input: s = "a"
        Output: [["a"]]
    */
    static public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        backtrack(res, new ArrayList<>(), s, 0);
        return res;
    }
    static public void backtrack(List<List<String>> res, List<String> temp, String s, int start) {
        if (start == s.length()) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                temp.add(s.substring(start, i + 1));
                backtrack(res, temp, s, i + 1);
                temp.remove(temp.size() - 1);
            }
        }
    }
    static public boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) {
                return false;
            }
        }
        return true;
    }


    // Day 23: The Number of Beautiful Subsets - Q2597(Medium)
    /*
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
    */
    static public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;
        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();
        for (int num : nums) {
            int remainder = num % k;
        freqMap.computeIfAbsent(remainder, x -> new TreeMap<>())
            .merge(num, 1, Integer::sum);
        }
        for (Map.Entry<Integer, Map<Integer, Integer>> entry : freqMap.entrySet()) {
            int n = entry.getValue().size();

            List<Map.Entry<Integer, Integer>> subsets = new ArrayList<>(entry.getValue().entrySet());
            
            int[] counts = new int[n + 1];
            counts[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                int skip = counts[i + 1];
                int take = (1 << subsets.get(i).getValue()) - 1;
                if (i + 1 < n && subsets.get(i + 1).getKey()
                        - subsets.get(i).getKey() == k) {
                    take *= counts[i + 2];
                } else {
                    take *= counts[i + 1];
                }
                counts[i] = skip + take; 
            }

            totalCount *= counts[0];
        }

        return totalCount - 1;
    }


    // Day 24: Maximum Score Words Formed by Letters - Q1255(Hard)
    /*
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
    */
    static public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] freq = new int[26];
        for (char letter : letters) {
            freq[letter - 'a']++;
        }
        int n = words.length;
        int[] wordScores = new int[n];
        for (int i = 0; i < n; i++) {
            for (char ch : words[i].toCharArray()) {
                wordScores[i] += score[ch - 'a'];
            }
        }
        return backtrack(words, freq, wordScores, score, 0);
    }
    static private int backtrack(String[] words, int[] freq, int[] wordScores, int[] score, int index) {
        if (index == words.length) {
            return 0;
        }
        int maxScore = 0;
        int[] newFreq = Arrays.copyOf(freq, freq.length);
        boolean isValid = true;
        for (char ch : words[index].toCharArray()) {
            newFreq[ch - 'a']--;
            if (newFreq[ch - 'a'] < 0) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            maxScore = Math.max(maxScore, wordScores[index] + backtrack(words, newFreq, wordScores, score, index + 1));
        }
        maxScore = Math.max(maxScore, backtrack(words, freq, wordScores, score, index + 1));
        return maxScore;
    }


    // Day 25: Word Break II - Q14(Hard)
    /*
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
    */
    static public List<String> wordBreak(String s, List<String> wordDict) {
        MayDailyProblems.Trie trie = new MayDailyProblems().new Trie();
        for (String word : wordDict) {
            trie.insert(word);
        }
        Map<Integer, List<String>> dp = new HashMap<>();
        for (int startIdx = s.length(); startIdx >= 0; startIdx--) {
            List<String> validSentences = new ArrayList<>();
            TrieNode currentNode = trie.root;
            for (int endIdx = startIdx; endIdx < s.length(); endIdx++) {
                char c = s.charAt(endIdx);
                int index = c - 'a';
                if (currentNode.children[index] == null) {
                    break;
                }
                currentNode = currentNode.children[index];
                if (currentNode.isEnd) {
                    String currentWord = s.substring(startIdx, endIdx + 1);
                    if (endIdx == s.length() - 1) {
                        validSentences.add(currentWord);
                    } else {
                        List<String> sentencesFromNextIndex = dp.get(
                            endIdx + 1
                        );
                        if (sentencesFromNextIndex != null) {
                            for (String sentence : sentencesFromNextIndex) {
                                validSentences.add(
                                    currentWord + " " + sentence
                                );
                            }
                        }
                    }
                }
            }
            dp.put(startIdx, validSentences);
        }
        return dp.getOrDefault(0, new ArrayList<>());
    }


    // Day 26: Student Attendance Record II - Q552(Hard)
    /*
        An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

        'A': Absent.
        'L': Late.
        'P': Present.
        Any student is eligible for an attendance award if they meet both of the following criteria:

        The student was absent ('A') for strictly fewer than 2 days total.
        The student was never late ('L') for 3 or more consecutive days.
        Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

        Example 1:
        Input: n = 2
        Output: 8
        Explanation: There are 8 records with length 2 that are eligible for an award:
        "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
        Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
        
        Example 2:
        Input: n = 1
        Output: 3

        Example 3:
        Input: n = 10101
        Output: 183236316
        

        Constraints:
        1 <= n <= 10^5
    */
    static List<List<List<Integer>>> comb;
    static public int checkRecord(int n){
        comb = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            List<List<Integer>> list2D = new ArrayList<>(2);
            for (int j = 0; j < 2; j++) {
                List<Integer> list1D = new ArrayList<>(3);
                for (int k = 0; k < 3; k++) {
                    list1D.add(-1);
                }
                list2D.add(list1D);
            }
            comb.add(list2D);
        }
        return checkCombinations(n, 0, 0);
    }
    static public int checkCombinations(int n, int a, int l) {
        if (a >= 2 || l >= 3) return 0;
        if (n == 0) return 1;
        if (comb.get(n).get(a).get(l) != -1) return comb.get(n).get(a).get(l);
        int c = 0;
        c = checkCombinations(n - 1, a, 0); // "P" case
        c = (c + checkCombinations(n - 1, a + 1, 0)) % 1000000007; // "A" case
        c = (c + checkCombinations(n - 1, a, l + 1)) % 1000000007; // "L" case
        comb.get(n).get(a).set(l, c);
        return c;
    }


    // Day 27: Special Array With X Elements Greater Than or Equal X - Q1608(Easy)
    /*
        You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

        Notice that x does not have to be an element in nums.

        Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

        Example 1:
        Input: nums = [3,5]
        Output: 2
        Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
        
        Example 2:
        Input: nums = [0,0]
        Output: -1
        Explanation: No numbers fit the criteria for x.
        If x = 0, there should be 0 numbers >= x, but there are 2.
        If x = 1, there should be 1 number >= x, but there are 0.
        If x = 2, there should be 2 numbers >= x, but there are 0.
        x cannot be greater since there are only 2 numbers in nums.
        
        Example 3:
        Input: nums = [0,4,3,0,4]
        Output: 3
        Explanation: There are 3 values that are greater than or equal to 3.
        

        Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 1000
    */
    static public int specialArray(int[] nums) {
        int n = nums.length;
        int[] count = new int[n + 1];
        for (int num : nums) {
            count[Math.min(num, n)]++;
        }
        int sum = 0;
        for (int i = n; i >= 0; i--) {
            sum += count[i];
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }


    // Day 28: Get Equal Substrings Within Budget - Q1208(Medium)
    /*
        You are given two strings s and t of the same length and an integer maxCost.

        You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]|
        (i.e., the absolute difference between the ASCII values of the characters).

        Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t,
        with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

        Example 1:
        Input: s = "abcd", t = "bcdf", maxCost = 3
        Output: 3
        Explanation: "abc" of s can change to "bcd".
        That costs 3, so the maximum length is 3.
        
        Example 2:
        Input: s = "abcd", t = "cdef", maxCost = 3
        Output: 1
        Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
        
        Example 3:
        Input: s = "abcd", t = "acde", maxCost = 0
        Output: 1
        Explanation: You cannot make any change, so the maximum length is 1.
        

        Constraints:
        1 <= s.length <= 105
        t.length == s.length
        0 <= maxCost <= 106
        s and t consist of only lowercase English letters.

    */
    static public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int[] cost = new int[n];
        for (int i = 0; i < n; i++) {
            cost[i] = Math.abs(s.charAt(i) - t.charAt(i));
        }
        int maxLength = 0;
        int start = 0;
        int end = 0;
        int currentCost = 0;
        while (end < n) {
            currentCost += cost[end];
            while (currentCost > maxCost) {
                currentCost -= cost[start];
                start++;
            }
            maxLength = Math.max(maxLength, end - start + 1);
            end++;
        }
        return maxLength;
    }
}
