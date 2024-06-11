import java.util.*;

public class JuneDailyProblems extends Solution {
    static Scanner scan = new Scanner(System.in);
    public JuneDailyProblems() {
        System.out.println("Welcome to June Daily Leetcode Problems");
        System.out.println("This is Yasaswin Palukuri, with solutions to the Daily Problems of June 2024");
        System.out.println("So, without any further ado, let's get started");
        solutions();
    }

    public static void solutions() {
        Solution s = new Solution();
        while (true) {
            System.out.println("Enter the day of the problem you want the answer for or 88 to Exit:");
            System.out.println("Day 1: Score of the String");
            System.out.println("Day 2: Reverse String");
            System.out.println("Day 3: Append Characters to String to Make Subsequence");
            System.out.println("Day 4: Longest Palindrome");
            System.out.println("Day 5: Find Common Characters");
            System.out.println("Day 6: Hand of Straights");
            System.out.println("Day 7: Replace Words");
            System.out.println("Day 8: Continuous Subarray Sum");
            System.out.println("Day 9: Subarray Sums Divisible by K");
            System.out.println("Day 10: Height Checker");
            System.out.println("Day 11: Relative Sort Array");
            System.out.println("88: Exit");
            System.out.print("Enter the day of the problem you want the answer for:");
            int day = scan.nextInt();
            switch (day) {
                case 1: {
                    System.out.println("Enter the word");
                    String word = scan.next();
                    System.out.println("The score of the word " + word + " is: " + s.scoreOfString(word));
                    break;
                }
                case 2:{
                    System.out.println("Enter the word");
                    String word = scan.next();
                    char[] le = word.toCharArray();
                    s.reverseString(le);
                    System.out.println("The reversed word is: " + Arrays.toString(le));
                    break;
                }
                case 3: {
                    System.out.println("Enter the first word");
                    String word1 = scan.next();
                    System.out.println("Enter the second word");
                    String word2 = scan.next();
                    System.out.println("The minimum number of characters that need to be appended to the end of " + word1 + " so that " + word2 + " becomes a subsequence of " + word1 + " is: " + s.appendCharacters(word1, word2));
                    break;
                }
                case 4: {
                    System.out.println("Enter the word");
                    String word = scan.next();
                    System.out.println("The length of the longest palindrome that can be built with the word " + word + " is: " + s.longestPalindrome(word));
                    break;
                }
                case 5:{
                    System.out.println("Enter the number of words");
                    int n = scan.nextInt();
                    String[] words = new String[n];
                    System.out.println("Enter the words");
                    for(int i = 0; i < n; i++) words[i] = scan.next();
                    System.out.println("The common characters in the words are: " + s.commonChars(words));
                    break;
                }
                case 6:{
                    System.out.println("Enter the number of cards");
                    int n = scan.nextInt();
                    int[] cards = new int[n];
                    System.out.println("Enter the cards");
                    for(int i = 0; i < n; i++) cards[i] = scan.nextInt();
                    System.out.println("Enter the group size");
                    int groupSize = scan.nextInt();
                    System.out.println("Can the cards be rearranged into groups of " + groupSize + ": " + s.isNStraightHand(cards, groupSize));
                    break;
                }
                case 7:{
                    System.out.println("Enter the number of words in the dictionary");
                    int n = scan.nextInt();
                    List<String> dictionary = new ArrayList<>();
                    System.out.println("Enter the words in the dictionary");
                    String[] words = scan.next().split(" ");
                    for(int i = 0; i < n; i++) dictionary.add(words[i]);
                    System.out.println("Enter the sentence");
                    String sentence = scan.nextLine();
                    System.out.println("The sentence after the replacement is: " + s.replaceWords(dictionary, sentence));
                    break;
                }
                case 8:{
                    System.out.println("Enter the number of elements in the array");
                    int n = scan.nextInt();
                    int[] nums = new int[n];
                    System.out.println("Enter the elements of the array");
                    for(int i = 0; i < n; i++) nums[i] = scan.nextInt();
                    System.out.println("Enter the value of k");
                    int k = scan.nextInt();
                    System.out.println("Is there a good subarray: " + s.checkSubarraySum(nums, k));
                    break;
                }
                case 9:{
                    System.out.println("Enter the number of elements in the array");
                    int n = scan.nextInt();
                    int[] nums = new int[n];
                    System.out.println("Enter the elements of the array");
                    for(int i = 0; i < n; i++) nums[i] = scan.nextInt();
                    System.out.println("Enter the value of k");
                    int k = scan.nextInt();
                    System.out.println("The number of non-empty subarrays that have a sum divisible by k is: " + s.subarraysDivByK(nums, k));
                    break;
                }
                case 10:{
                    System.out.println("Enter the number of students");
                    int n = scan.nextInt();
                    int[] heights = new int[n];
                    System.out.println("Enter the heights of the students");
                    for(int i = 0; i < n; i++) heights[i] = scan.nextInt();
                    System.out.println("The number of indices where heights[i] != expected[i] is: " + s.heightChecker(heights));
                    break;
                }
                case 11:{
                    System.out.println("Enter the number of elements in the first array");
                    int n = scan.nextInt();
                    int[] arr1 = new int[n];
                    System.out.println("Enter the elements of the first array");
                    for(int i = 0; i < n; i++) arr1[i] = scan.nextInt();
                    System.out.println("Enter the number of elements in the second array");
                    int m = scan.nextInt();
                    int[] arr2 = new int[m];
                    System.out.println("Enter the elements of the second array");
                    for(int i = 0; i < m; i++) arr2[i] = scan.nextInt();
                    System.out.println("The relative sort array is: " + Arrays.toString(s.relativeSortArray(arr1, arr2)));
                    break;
                }
                case 88: {
                    System.out.println("Thank you for using the June Daily Leetcode Problems");
                    System.out.println("Hope you had a great time solving the problems");
                    System.out.println("Have a great day ahead");
                    return;
                }
                default:
                    System.out.println("Sorry, the problem for the day you entered is not available");
            }
        }
    }

    public static void main(String[] args) {
        new JuneDailyProblems();
    }
}
class Solution {
    // Day 1: Score of a String - Q3110(Easy)
    /*
        You are given a string s. 
        The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
        Return the score of s.

        Example 1:
        Input: s = "hello"
        Output: 13
        Explanation:
        The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111.
        So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

        Example 2:
        Input: s = "zaz"
        Output: 50
        Explanation:
        The ASCII values of the characters in s are: 'z' = 122, 'a' = 97.
        So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.

        Constraints:
        2 <= s.length <= 100
        s consists only of lowercase English letters.
    */
    public int scoreOfString(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            ans += Math.abs(s.charAt(i) - s.charAt(i - 1));
        }
        return ans;
    }


    // Day 2: Reverse String - Q344(Easy)
    /*
        Write a function that reverses a string. The input string is given as an array of characters s.

        Example 1:
        Input: s = ["h","e","l","l","o"]
        Output: ["o","l","l","e","h"]

        Example 2:
        Input: s = ["H","a","n","n","a","h"]
        Output: ["h","a","n","n","a","H"]

        Constraints:
        1 <= s.length <= 10^5
        s[i] is a printable ascii character.
    
    */
    public void reverseString(char[] s) {
        int l = 0;
        int r = s.length - 1;
        for(l = 0; l < r; l++, r--) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    }


    // Day 3: Append Characters to String to Make Subsequence - Q2468(Medium)
    /*
        You are given two strings s and t consisting of only lowercase English letters.

        Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
        A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

        Example 1:
        Input: s = "coaching", t = "coding"
        Output: 4
        Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
        Now, t is a subsequence of s ("coachingding").
        It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
        
        Example 2:
        Input: s = "abcde", t = "a"
        Output: 0
        Explanation: t is already a subsequence of s ("abcde").
        
        Example 3:
        Input: s = "z", t = "abcde"
        Output: 5
        Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
        Now, t is a subsequence of s ("zabcde").
        It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
        

        Constraints:
        1 <= s.length, t.length <= 10^5
        s and t consist only of lowercase English letters.
    */
    public int appendCharacters(String s, String t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s.charAt(i) == t.charAt(j)) {
                j++;
            }
            i++;
        }
        return t.length() - j;
    }

    // Day 4: Longest Palindrome - Q409(Easy)
    /*
        Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

        Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

        Example 1:
        Input: s = "abccccdd"
        Output: 7
        Explanation:
        One longest palindrome that can be built is "dccaccd", whose length is 7.

        Example 2:
        Input: s = "a"
        Output: 1

        Example 3:
        Input: s = "bb"
        Output: 2

        Constraints:
        1 <= s.length <= 2000
        s consists of lowercase and/or uppercase English letters only.
    */
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        for(char c : s.toCharArray()) {
            count[c]++;
        }
        int ans = 0;
        for(int v : count) {
            ans += v / 2 * 2;
            if(ans % 2 == 0 && v % 2 == 1) {
                ans++;
            }
        }
        return ans;
    }



    // Day 5: Find Common Characters - Q1002(Easy)
    /*
        Given an array words of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates). 
        For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

        You may return the answer in any order.

        Example 1:
        Input: words = ["bella","label","roller"]
        Output: ["e","l","l"]
        
        Example 2:
        Input: words = ["cool","lock","cook"]
        Output: ["c","o"]
        

        Constraints:
        1 <= words.length <= 100
        1 <= words[i].length <= 100
        words[i] consists of lowercase English letters.
    */
    public List<String> commonChars(String[] words) {
        List<String> ans = new ArrayList<>();
        int[] minCount = new int[26];
        Arrays.fill(minCount, Integer.MAX_VALUE);
        for(String word : words) {
            int[] count = new int[26];
            for(char c : word.toCharArray()) {
                count[c - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                minCount[i] = Math.min(minCount[i], count[i]);
            }
        }
        for(int i = 0; i < 26; i++) {
            while(minCount[i]-- > 0) {
                ans.add("" + (char)(i + 'a'));
            }
        }
        return ans;
    }


    // Day 6: Hand of Straights - Q846(Medium)
    /*
        Alice has a hand of cards, given as an array of integers.

        Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

        Return true if and only if she can.

        Example 1:
        Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
        Output: true
        Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

        Example 2:
        Input: hand = [1,2,3,4,5], W = 4
        Output: false
        Explanation: Alice's hand can't be rearranged into groups of 4.

        Constraints:
        1 <= hand.length <= 10000
        0 <= hand[i] <= 10^9
        1 <= W <= hand.length
    */
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize != 0) return false;
        Map<Integer, Integer> count = new HashMap<>();
        for (int card : hand) {
            count.put(card, count.getOrDefault(card, 0) + 1);
        }
        int[] sortedKeys = new int[count.size()];
        int index = 0;
        for (int key : count.keySet()) {
            sortedKeys[index++] = key;
        }
        Arrays.sort(sortedKeys);
        for (int key : sortedKeys) {
            if (count.get(key) > 0) {
                int startCount = count.get(key);
                for (int i = key; i < key + groupSize; i++) {
                    if (count.getOrDefault(i, 0) < startCount) {
                        return false;
                    }
                    count.put(i, count.get(i) - startCount);
                }
            }
        }
        return true;
    }



    // Day 7: Replace Words - Q648(Medium)
    /*
        In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
        For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

        Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. 
        If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

        Return the sentence after the replacement.

        Example 1:
        Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
        Output: "the cat was rat by the bat"
        
        Example 2:
        Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
        Output: "a a b c"
        
        Example 3:
        Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
        Output: "a a a a a a a a bbb baba a"
        
        Example 4:
        Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
        Output: "the cat was rat by the bat"
        
        Example 5:
        Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
        Output: "it is ab that this solution is ac"
        

        Constraints:
        1 <= dictionary.length <= 1000
        1 <= dictionary[i].length <= 100
        dictionary[i] consists of only lower-case letters.
        1 <= sentence.length <= 10^6
        sentence consists of only lower-case letters and spaces.
        The number of words in sentence is in the range [1, 1000]
        The length of each word in sentence is in the range [1, 1000]
        Each two consecutive words in sentence will be separated by exactly one space.
        sentence does not have leading or trailing spaces.
    */
    public String replaceWords(List<String> dictionary, String sentence) {
        String[] wordArray = sentence.split(" ");
        Set<String> dictSet = new HashSet<>(dictionary);
        for (int i = 0; i < wordArray.length; i++) {
            wordArray[i] = shortestRoot(wordArray[i], dictSet);
        }

        return String.join(" ", wordArray);
    }

    public String shortestRoot(String word, Set<String> dictSet) {
        for (int i = 1; i <= word.length(); i++) {
            String root = word.substring(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        return word;
    }


    // Day 8: Continuous Subarray Sum - Q523(Medium)
    /*
        Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

        A good subarray is a subarray where:

        its length is at least two, and
        the sum of the elements of the subarray is a multiple of k.
        Note that:

        A subarray is a contiguous part of the array.
        An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
        

        Example 1:

        Input: nums = [23,2,4,6,7], k = 6
        Output: true
        Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
        Example 2:

        Input: nums = [23,2,6,4,7], k = 6
        Output: true
        Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
        42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
        Example 3:

        Input: nums = [23,2,6,4,7], k = 13
        Output: false
        

        Constraints:

        1 <= nums.length <= 10^5
        0 <= nums[i] <= 10^9
        0 <= sum(nums[i]) <= 23^1 - 1
        1 <= k <= 23^1 - 1
    */
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (map.containsKey(sum)) {
                if (i - map.get(sum) > 1) {
                    return true;
                }
            } else {
                map.put(sum, i);
            }
        }
        return false;
    }



    // Day 9: Subarray Sums Divisible by K - Q974(Medium)
    /*
        Given an integer array nums and an integer k,
        return the number of non-empty subarrays that have a sum divisible by k.
        A subarray is a contiguous part of an array.

        Example 1:
        Input: nums = [4,5,0,-2,-3,1], k = 5
        Output: 7
        Explanation: There are 7 subarrays with a sum divisible by k = 5:
        [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
        
        
        Example 2:
        Input: nums = [5], k = 9
        Output: 0
        
        Constraints:
        1 <= nums.length <= 3 * 104
        -104 <= nums[i] <= 104
        2 <= k <= 104
    */
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum = (sum + num) % k;
            if (sum < 0) {
                sum += k;
            }
            count += map.getOrDefault(sum, 0);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }


    // Day 10: Height Checker - Q1051(Easy)
    /*
        A school is trying to take an annual photo of all the students. 
        The students are asked to stand in a single file line in non-decreasing order by height. 
        Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
        You are given an integer array heights representing the current order that the students are standing in. 
        Each heights[i] is the height of the ith student in line (0-indexed).
        Return the number of indices where heights[i] != expected[i].

        Example 1:
        Input: heights = [1,1,4,2,1,3]
        Output: 3
        Explanation: 
        heights:  [1,1,4,2,1,3]
        expected: [1,1,1,2,3,4]
        Indices 2, 4, and 5 do not match.
        
        Example 2:
        Input: heights = [5,1,2,3,4]
        Output: 5
        Explanation:
        heights:  [5,1,2,3,4]
        expected: [1,2,3,4,5]
        All indices do not match.
        
        Example 3:
        Input: heights = [1,2,3,4,5]
        Output: 0
        Explanation:
        heights:  [1,2,3,4,5]
        expected: [1,2,3,4,5]
        All indices match.
        

        Constraints:
        1 <= heights.length <= 100
        1 <= heights[i] <= 100
    */
    public int heightChecker(int[] heights) {
        int[] expected = Arrays.copyOf(heights, heights.length);
        Arrays.sort(expected);
        int count = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        return count;
    }


    // Day 11: Relative Sort Array - Q1122(Easy)
    /*
        Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

        Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
        Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

        Example 1:
        Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
        Output: [2,2,2,1,4,3,3,9,6,7,19]
        
        Constraints:
        1 <= arr1.length, arr2.length <= 1000
        0 <= arr1[i], arr2[i] <= 1000
        All the elements of arr2 are distinct.
        Each arr2[i] is in arr1.
    */
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // HashMap<Integer,Integer> hm = new HashMap<>();
        // for (int j : arr1) {
        //     if (hm.containsKey(j)) {
        //         hm.put(j, hm.get(j) + 1);
        //     } else {
        //         hm.put(j, 1);
        //     }
        // }
        // int[] ans = new int[arr1.length];
        // int cnt=0;
        // for (int j : arr2) {
        //     while (hm.get(j) > 0) {
        //         ans[cnt] = j;
        //         cnt++;
        //         hm.put(j, hm.get(j) - 1);
        //     }
        //     hm.remove(j);
        // }
        // int[] remaining = new int[arr1.length-cnt];
        // int index = 0;
        // for (int j : arr1) {
        //     if (hm.containsKey(j)) {
        //         while (hm.get(j) > 0) {
        //             remaining[index] = j;
        //             index++;
        //             hm.put(j, hm.get(j) - 1);
        //         }
        //         hm.remove(j);
        //     }
        // }
        // Arrays.sort(remaining);
        // for (int j : remaining) {
        //     ans[cnt] = j;
        //     cnt++;
        // }
        // return ans;
    }
}


