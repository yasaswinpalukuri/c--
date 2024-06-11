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