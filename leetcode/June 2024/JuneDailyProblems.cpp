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