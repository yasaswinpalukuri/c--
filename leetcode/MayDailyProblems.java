package leetcode;
import java.util.*;

// This File consists of all the problems solved in May Daily Leetcode Challenge 2024
public class MayDailyProblems {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Welcome to May Daily Leetcode Problems");
        System.out.println("This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024");
        System.out.println("So, without any further ado, let's get started");
        do{
            System.out.println("Enter the day of the problem you want the answer for or 88 to Exit:");
            System.out.println("Day 1: Reverse Prefix of Word");
            System.out.println("Day 2: Largest Positive Integer That Exists With Its Negative");
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
                case 88:
                    System.out.println("Thank you for using the May Daily Leetcode Problems");
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

}
