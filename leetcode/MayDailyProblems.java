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
        
    }
}
