#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
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
    int scoreOfString(string s){
        int ans = 0;
        for(int i=1;i<s.length();i++) ans += abs(s[i]-s[i-1]);
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
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0;i<n/2;i++) swap(s[i],s[n-i-1]);
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
    int appendCharacters(string s, string t) {
        int first = 0, longestPrefix = 0;
        while (first < s.length() && longestPrefix < t.length()) {
            if (s[first] == t[longestPrefix]) longestPrefix++;
            first++;
        }
        return t.length() - longestPrefix;
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
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto c:s) mp[c]++;
        int ans = 0;
        for(auto p:mp){
            ans += p.second/2*2;
            if(ans%2==0 && p.second%2==1) ans++;
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
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26,INT_MAX);
        for(auto word:words){
            vector<int> cnt1(26,0);
            for(auto c:word) cnt1[c-'a']++;
            for(int i=0;i<26;i++) cnt[i] = min(cnt[i],cnt1[i]);
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            for(int j=0;j<cnt[i];j++) ans.push_back(string(1,'a'+i));
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
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> mp;
        for(auto h:hand) mp[h]++;
        for(auto p:mp){
            if(mp[p.first]>0){
                for(int i=W-1;i>=0;i--){
                    if((mp[p.first+i]-=mp[p.first])<0) return false;
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        string word;
        string newSentence;
        while (getline(sStream, word, ' ')) newSentence += shortestRoot(word, dictSet) + " ";
        newSentence.pop_back();
        return newSentence;
    }

    string shortestRoot(string word, unordered_set<string> dictSet) {
        for (int i = 1; i <= word.length(); i++) {
            string root = word.substr(0, i);
            if (dictSet.find(root) != dictSet.end()) {
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(k!=0) sum %= k;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>1) return true;
            }else mp[sum] = i;
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
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0]%k==0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sum %= k;
            if(sum<0) sum += k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
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
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(),expected.end());
        int ans = 0;
        for(int i=0;i<heights.size();i++) if(heights[i]!=expected[i]) ans++;
        return ans;
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr2.size();i++) mp[arr2[i]] = i;
        sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(mp.find(a)!=mp.end() || mp.find(b)!=mp.end()) 
            return mp.find(a)!=mp.end() && mp.find(b)!=mp.end() ? mp[a]<mp[b] : mp.find(a)!=mp.end();
            return a<b;
        });
        return arr1;
    }


    // Day 12: Sort Colors - Q75(Medium)
    /*
        Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
        with the colors in the order red, white, and blue.
        We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

        You must solve this problem without using the library's sort function.

        Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]
        
        Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]
        
        Example 3:
        Input: nums = [0]
        Output: [0]
        
        Example 4:
        Input: nums = [1]
        Output: [1]
        

        Constraints:
        n == nums.length
        1 <= n <= 300
        nums[i] is 0, 1, or 2.
    */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        for(int i=0;i<=high;i++){
            if(nums[i]==0) swap(nums[i],nums[low++]);
            else if(nums[i]==2) swap(nums[i--],nums[high--]);
        }
    }


    // Day 13: Minimum Number of Moves to Seat Everyone - Q2037(Easy)
    /*
        There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. 
        You are also given the array students of length n, where students[j] is the position of the jth student.

        You may perform the following move any number of times:

        Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
        Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

        Note that there may be multiple seats or students in the same position at the beginning.

        Example 1:
        Input: seats = [3,1,5], students = [2,7,4]
        Output: 4
        Explanation: The students are moved as follows:
        - The first student is moved from from position 2 to position 1 using 1 move.
        - The second student is moved from from position 7 to position 5 using 2 moves.
        - The third student is moved from from position 4 to position 3 using 1 move.
        In total, 1 + 2 + 1 = 4 moves were used.
        
        Example 2:
        Input: seats = [4,1,5,9], students = [1,3,2,6]
        Output: 7
        Explanation: The students are moved as follows:
        - The first student is not moved.
        - The second student is moved from from position 3 to position 4 using 1 move.
        - The third student is moved from from position 2 to position 1 using 1 move.
        - The fourth student is moved from from position 6 to position 9 using 3 moves.
        In total, 0 + 1 + 1 + 3 = 5 moves were used.
        
        Example 3:
        Input: seats = [2,2,6], students = [1,3,2]
        Output: 4
        Explanation: The students are moved as follows:
        - The first student is moved from from position 1 to position 2 using 1 move.
        - The second student is not moved.
        - The third student is moved from from position 2 to position 6 using 3 moves.
    */
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans = 0;
        for(int i=0;i<seats.size();i++) ans += abs(seats[i]-students[i]);
        return ans;
    }


    // Day 14: Minimum Increment to Make Array Unique - Q945(Medium)
    /*
        You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

        Return the minimum number of moves to make every value in nums unique.

        The test cases are generated so that the answer fits in a 32-bit integer.

        

        Example 1:
        Input: nums = [1,2,2]
        Output: 1
        Explanation: After 1 move, the array could be [1, 2, 3].
        
        Example 2:
        Input: nums = [3,2,1,2,1,7]
        Output: 6
        Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
        It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
        

        Constraints:
        1 <= nums.length <= 105
        0 <= nums[i] <= 105
    */
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                ans += nums[i-1]-nums[i]+1;
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }


    // Day 15: IPO - Q502(Hard)
    /*
        Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. 
        Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

        You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

        Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

        Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

        The answer is guaranteed to fit in a 32-bit signed integer.

        Example 1:
        Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
        Output: 4
        Explanation: Since your initial capital is 0, you can only start the project indexed 0.
        After finishing it you will obtain profit 1 and your capital becomes 1.
        With capital 1, you can either start the project indexed 1 or the project indexed 2.
        Since you can choose at most 2 projects, you need to start the project indexed 2 to get the maximum capital.
        Therefore, the final capital is 0 + 1 + 3 = 4.
        
        Example 2:
        Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
        Output: 6
        

        Constraints:
        1 <= k <= 10^5
        0 <= w <= 10^9
        n == profits.length
        n == capital.length
        1 <= n <= 10^5
        0 <= profits[i] <= 10^4
        0 <= capital[i] <= 10^9
    */
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        for(int i=0;i<n;i++) projects.push_back({capital[i],profits[i]});
        sort(projects.begin(),projects.end());
        priority_queue<int> pq;
        int i = 0;
        for(int j=0;j<k;j++){
            while(i<n && projects[i].first<=w){
                pq.push(projects[i].second);
                i++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }else break;
        }
        return w;
    }


    // Day 16: Patching Array - Q330(Hard)
    /*
        Given a sorted integer array nums and an integer n, 
        add/patch elements to the array such that any number in the range [1, n] 
        inclusive can be formed by the sum of some elements in the array.
        Return the minimum number of patches required.

        Example 1:
        Input: nums = [1,3], n = 6
        Output: 1
        Explanation:
        Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
        Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
        Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
        So we only need 1 patch.
        
        Example 2:
        Input: nums = [1,5,10], n = 20
        Output: 2
        Explanation: The two patches can be [2, 4].
        
        Example 3:
        Input: nums = [1,2,2], n = 5
        Output: 0

        Constraints:
        1 <= nums.length <= 1000
        1 <= nums[i] <= 104
        nums is sorted in ascending order.
        1 <= n <= 231 - 1
    */
    int minPatches(vector<int>& nums, int n) {
        long missing = 1;
        int patches = 0;
        int index = 0;

        while (missing <= n) {
            if (index < nums.size() && nums[index] <= missing) {
                missing += nums[index];
                index++;
            } else {
                missing += missing;
                patches++;
            }
        }

        return patches;
    }


    // Day 17: Sum of Square Numbers - Q633(Medium)
    /*
        Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.
        Example 1:

        Input: c = 5
        Output: true
        Explanation: 1 * 1 + 2 * 2 = 5
        Example 2:

        Input: c = 3
        Output: false
        

        Constraints:

        0 <= c <= 2^31 - 1
    */
    bool judgeSquareSum(int c) {
        for (int divisor = 2; divisor * divisor <= c; divisor++) {
            if (c % divisor == 0) {
                int exponentCount = 0;
                while (c % divisor == 0) {
                    exponentCount++;
                    c /= divisor;
                }
                if (divisor % 4 == 3 && exponentCount % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }



    // Day 18: Most Profit Assigning Work - Q826(Meidum)
    /*
        You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
        difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
        worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
        Every worker can be assigned at most one job, but one job can be completed multiple times.

        For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
        Return the maximum profit we can achieve after assigning the workers to the jobs.

        

        Example 1:

        Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
        Output: 100
        Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
        Example 2:

        Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
        Output: 0
        

        Constraints:

        n == difficulty.length
        n == profit.length
        m == worker.length
        1 <= n, m <= 104
        1 <= difficulty[i], profit[i], worker[i] <= 105
    */
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfitUpToDifficulty(maxDifficulty + 1, 0);

        for (int i = 0; i < difficulty.size(); ++i) {
            maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);
        }

        for (int i = 1; i <= maxDifficulty; ++i) {
            maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);
        }

        int totalProfit = 0;
        for (int ability : worker) {
            if (ability > maxDifficulty) {
                totalProfit += maxProfitUpToDifficulty[maxDifficulty];
            } else {
                totalProfit += maxProfitUpToDifficulty[ability];
            }
        }

        return totalProfit;
    }


    // Day 19: Minimum Number of Days to Make m Bouquets - Q1482(Medium)
    /*
        You are given an integer array bloomDay, an integer m and an integer k.
        You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
        The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
        Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

        
        Example 1:
        Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
        Output: 3
        Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
        We need 3 bouquets each should contain 1 flower.
        After day 1: [x, _, _, _, _]   // we can only make one bouquet.
        After day 2: [x, _, _, _, x]   // we can only make two bouquets.
        After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
        
        Example 2:
        Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
        Output: -1
        Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
        
        Example 3:
        Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
        Output: 12
        Explanation: We need 2 bouquets each should have 3 flowers.
        Here is the garden after the 7 and 12 days:
        After day 7: [x, x, x, x, _, x, x]
        We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
        After day 12: [x, x, x, x, x, x, x]
        It is obvious that we can make two bouquets in different ways.
        
        Constraints:
        bloomDay.length == n
        1 <= n <= 105
        1 <= bloomDay[i] <= 109
        1 <= m <= 106
        1 <= k <= n
    */
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }


    // Day 20: Magnetic Force Between Two Balls - Q1552(Medium)
    /*
        In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
        Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
        Given the integer array position and the integer m. Return the required force.

        Example 1:
        Input: position = [1,2,3,4,7], m = 3
        Output: 3
        Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
        
        Example 2:
        Input: position = [5,4,3,2,1,1000000000], m = 2
        Output: 999999999
        Explanation: We can use baskets 1 and 1000000000.
        
        Constraints:
        n == position.length
        2 <= n <= 10^5
        1 <= position[i] <= 10^9
        All integers in position are distinct.
        2 <= m <= position.length
    */
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }


    // Day 21: Grumpy Bookstore Owner - Q1052(Medium)
    /*
        There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.
        On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.
        When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.
        The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.
        Return the maximum number of customers that can be satisfied throughout the day.

        Example 1:
        Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
        Output: 16
        Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
        The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
        
        Example 2:
        Input: customers = [1], grumpy = [0], minutes = 1
        Output: 1
        
        Constraints:
        n == customers.length == grumpy.length
        1 <= minutes <= n <= 2 * 104
        0 <= customers[i] <= 1000
        grumpy[i] is either 0 or 1.
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentWindowSatisfaction = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSatisfaction += customers[i];
            } else if (i < minutes) {
                currentWindowSatisfaction += customers[i];
            }
        }
        
        maxExtraSatisfaction = currentWindowSatisfaction;
        
        for (int i = minutes; i < customers.size(); ++i) {
            currentWindowSatisfaction += customers[i] * grumpy[i];
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentWindowSatisfaction);
        }
        
        return initialSatisfaction + maxExtraSatisfaction;   
    }
};

class JuneDailyProblems: public Solution{
    public:
    JuneDailyProblems(){
        cout << "Welcome to June Daily Leetcode Problems\n";
        cout << "This is Yasaswin Palukuri, with solutions to the Daily Problems of June 2024\n";
        cout << "So, without any further ado, let's get started\n";
        solutions();
    }
    void solutions(){
        Solution s;
        do{
            cout << "Enter the day of the problem you want the answer for or 88 to Exit:\n";
            cout << "Day 1: Score of the String\n";
            cout << "Day 2: Reverse String\n";
            cout << "Day 3: Append Characters to String to Make Subsequence\n";
            cout << "Day 4: Longest Palindrome\n";
            cout << "Day 5: Find Common Characters\n";
            cout << "Day 6: Hand of Straights\n";
            cout << "Day 7: Replace Words\n";
            cout << "Day 8: Continuous Subarray Sum\n";
            cout << "Day 9: Subarrays Divisible by K\n";
            cout << "Day 10: Height Checker\n";
            cout << "Day 11: Relative Sort Array\n";
            cout << "Day 12: Sort Colors\n";
            cout << "Day 13: Minimum Number of Moves to Seat Everyone\n";
            cout << "Day 14: Minimum Increment to Make Array Unique\n";
            cout << "Day 15: IPO\n";
            cout << "Day 16: Patching Array\n";
            cout << "Day 17: Sum of Square Numbers\n";
            cout << "Day 18: Most Profit Assigning Work\n";
            cout << "Day 19: Minimum Number of Days to Make m Bouquets\n";
            cout << "Day 20: Magnetic Force Between Two Balls\n";
            cout << "Day 21: Grumpy Bookstore Owner\n";
            cout << "88: Exit" << '\n';
            int day; cin >> day;
            switch(day){
                case 1:{
                    cout << "Enter the word \n";
                    string word; cin >> word;
                    cout << "The score of the word "<< word <<" is : " << s.scoreOfString(word) << '\n';
                    break;
                }
                case 2:{
                    cout << "Enter the word \n";
                    string word; cin >> word;
                    vector<char> le(word.begin(),word.end());
                    s.reverseString(le);
                    cout << "The reversed word is : ";
                    for(auto c:le) cout << c;
                    cout << '\n';
                    break;
                }
                case 3:{
                    cout << "Enter the two words\n";
                    string s1,s2; cin >> s1 >> s2;
                    cout << "The minimum number of characters that need to be appended to the end of " << s1 << " so that " << s2 << " becomes a subsequence of " << s1 << " is : " << s.appendCharacters(s1,s2) << '\n';
                    break;
                }
                case 4:{
                    cout << "Enter the word\n";
                    string word; cin >> word;
                    cout << "The length of the longest palindrome that can be built with the word " << word << " is : " << s.longestPalindrome(word) << '\n';
                    break;
                }
                case 5:{
                    cout << "Enter the number of words\n";
                    int n; cin >> n;
                    vector<string> words(n);
                    cout << "Enter the words\n";
                    for(int i=0;i<n;i++) cin >> words[i];
                    vector<string> ans = s.commonChars(words);
                    cout << "The common characters in the words are : ";
                    for(auto c:ans) cout << c << " ";
                    cout << '\n';
                    break;
                }
                case 6:{
                    cout << "Enter the number of cards\n";
                    int n; cin >> n;
                    vector<int> cards(n);
                    cout << "Enter the cards\n";
                    for(int i=0;i<n;i++) cin >> cards[i];
                    cout << "Enter the number of cards in each group\n";
                    int w; cin >> w;
                    cout << "Is it possible to rearrange the cards into groups of size " << w << " : " << (bool)s.isNStraightHand(cards,w) << '\n';
                    break;
                }
                case 7:{
                    cout << "Enter the number of words in the dictionary\n";
                    int n; cin >> n;
                    vector<string> dictionary(n);
                    cout << "Enter the words in the dictionary\n";
                    for(int i=0;i<n;i++) cin >> dictionary[i];
                    cout << "Enter the sentence\n";
                    string sentence; cin >> sentence;
                    cout << "The sentence after the replacement is : " << s.replaceWords(dictionary,sentence) << '\n';
                    break;
                }
                case 8:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> nums(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> nums[i];
                    cout << "Enter the value of k\n";
                    int k; cin >> k;
                    cout << "Is there a good subarray in the array : " << (bool)s.checkSubarraySum(nums,k) << '\n';
                    break;
                }
                case 9:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> nums(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> nums[i];
                    cout << "Enter the value of k\n";
                    int k; cin >> k;
                    cout << "The number of non-empty subarrays that have a sum divisible by " << k << " is : " << s.subarraysDivByK(nums,k) << '\n';
                    break;
                }
                case 10:{
                    cout << "Enter the number of students\n";
                    int n; cin >> n;
                    vector<int> heights(n);
                    cout << "Enter the heights of the students\n";
                    for(int i=0;i<n;i++) cin >> heights[i];
                    cout << "The number of indices where the heights do not match the expected heights is : " << s.heightChecker(heights) << '\n';
                    break;
                }
                case 11:{
                    cout << "Enter the number of elements in the first array\n";
                    int n; cin >> n;
                    vector<int> arr1(n);
                    cout << "Enter the elements of the first array\n";
                    for(int i=0;i<n;i++) cin >> arr1[i];
                    cout << "Enter the number of elements in the second array\n";
                    int m; cin >> m;
                    vector<int> arr2(m);
                    cout << "Enter the elements of the second array\n";
                    for(int i=0;i<m;i++) cin >> arr2[i];
                    vector<int> ans = s.relativeSortArray(arr1,arr2);
                    cout << "The relative sorted array is : ";
                    for(auto c:ans) cout << c << " ";
                    cout << '\n';
                    break;
                }
                case 12:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> nums(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> nums[i];
                    s.sortColors(nums);
                    cout << "The sorted array is : ";
                    for(auto c:nums) cout << c << " ";
                    cout << '\n';
                    break;
                }
                case 13:{
                    cout << "Enter the number of seats\n";
                    int n; cin >> n;
                    vector<int> seats(n);
                    cout << "Enter the positions of the seats\n";
                    for(int i=0;i<n;i++) cin >> seats[i];
                    cout << "Enter the number of students\n";
                    int m; cin >> m;
                    vector<int> students(m);
                    cout << "Enter the positions of the students\n";
                    for(int i=0;i<m;i++) cin >> students[i];
                    cout << "The minimum number of moves required to move each student to a seat such that no two students are in the same seat is : " << s.minMovesToSeat(seats,students) << '\n';
                    break;
                }
                case 14:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> nums(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> nums[i];
                    cout << "The minimum number of moves required to make every value in the array unique is : " << s.minIncrementForUnique(nums) << '\n';
                    break;
                }
                case 15:{
                    cout << "Enter the value of k\n";
                    int k; cin >> k;
                    cout << "Enter the value of w\n";
                    int w; cin >> w;
                    cout << "Enter the number of projects\n";
                    int n; cin >> n;
                    vector<int> profits(n), capital(n);
                    cout << "Enter the profits of the projects\n";
                    for(int i=0;i<n;i++) cin >> profits[i];
                    cout << "Enter the capital of the projects\n";
                    for(int i=0;i<n;i++) cin >> capital[i];
                    cout << "Enter the initial capital\n";
                    int c; cin >> c;
                    cout << "The final maximized capital is : " << s.findMaximizedCapital(k,c,profits,capital) << '\n';
                    break;
                }
                case 16:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> nums(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> nums[i];
                    cout << "Enter the value of n\n";
                    int m; cin >> m;
                    cout << "The minimum number of days you need to wait to be able to make " << m << " bouquets from the garden is : " << s.minDays(nums,m) << '\n';
                    break;
                }
                case 17:{
                    cout << "Enter the value of c\n";
                    int c; cin >> c;
                    cout << "Is there a pair of integers a and b such that a^2 + b^2 = " << c << " : " << (bool)s.judgeSquareSum(c) << '\n';
                    break;
                }
                case 18:{
                    cout << "Enter the number of jobs\n";
                    int n; cin >> n;
                    vector<int> difficulty(n), profit(n);
                    cout << "Enter the difficulties of the jobs\n";
                    for(int i=0;i<n;i++) cin >> difficulty[i];
                    cout << "Enter the profits of the jobs\n";
                    for(int i=0;i<n;i++) cin >> profit[i];
                    cout << "Enter the number of workers\n";
                    int m; cin >> m;
                    vector<int> worker(m);
                    cout << "Enter the abilities of the workers\n";
                    for(int i=0;i<m;i++) cin >> worker[i];
                    cout << "The maximum profit we can achieve after assigning the workers to the jobs is : " << s.maxProfitAssignment(difficulty,profit,worker) << '\n';
                    break;
                }
                case 19:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> bloomDay(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> bloomDay[i];
                    cout << "Enter the number of bouquets\n";
                    int m; cin >> m;
                    cout << "Enter the number of flowers in each bouquet\n";
                    int k; cin >> k;
                    cout << "The minimum number of days you need to wait to be able to make " << m << " bouquets from the garden is : " << s.minPatches(bloomDay,m,k) << '\n';
                    break;
                }
                case 20:{
                    cout << "Enter the number of elements in the array\n";
                    int n; cin >> n;
                    vector<int> position(n);
                    cout << "Enter the elements of the array\n";
                    for(int i=0;i<n;i++) cin >> position[i];
                    cout << "Enter the number of balls\n";
                    int m; cin >> m;
                    cout << "The maximum distance between the balls is : " << s.maxDistance(position,m) << '\n';
                    break;
                }
                case 21:{
                    cout << "Enter the number of minutes the store is open\n";
                    int n; cin >> n;
                    vector<int> customers(n), grumpy(n);
                    cout << "Enter the number of customers entering the store at the start of each minute\n";
                    for(int i=0;i<n;i++) cin >> customers[i];
                    cout << "Enter the grumpiness of the store owner during each minute\n";
                    for(int i=0;i<n;i++) cin >> grumpy[i];
                    cout << "Enter the number of minutes the store owner can keep themselves not grumpy\n";
                    int minutes; cin >> minutes;
                    cout << "The maximum number of customers that can be satisfied throughout the day is : " << s.maxSatisfied(customers,grumpy,minutes) << '\n';
                    break;
                }
                case 88:{
                    cout << "Thank you for using the June Daily Leetcode Problems\n";
                    cout << "Hope you had a great time solving the problems\n";
                    cout << "Have a great day ahead\n";
                    return;
                }
                default:
                    cout << "Sorry, the problem for the day you entered is not available\n";
            }
        }while(true);
    }
};


int main(){
    JuneDailyProblems j;
    return 0;
}