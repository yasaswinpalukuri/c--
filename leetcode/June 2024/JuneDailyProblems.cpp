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