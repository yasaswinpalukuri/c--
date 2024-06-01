#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
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
    }
};

class JuneDailyProblems{
    JuneDailyProblems(){
        cout << "Welcome to June Daily Leetcode Problems\n";
        cout << "This is Yasaswin Palukuri, with solutions to the Daily Problems of June 2024\n";
        cout << "So, without any further ado, let's get started\n";
        solutions();
    }
    private:
    void solutions(){
        Solution s;
        do{
            cout << "Enter the day of the problem you want the answer for or 88 to Exit:\n";
            cout << "Day 1: Reverse Prefix of Word\n";
            cout << "88: Exit" << '\n';
            int day; cin >> day;
            switch(day){
                case 1:
                    cout << "Day 1: Reverse Prefix of Word\n";
                    cout << "Enter the word and the character to reverse the prefix of the word\n";
                    string word; char ch;
                    cin >> word >> ch;
                    cout << "The word after reversing the prefix is: " << s.reversePrefix(word, ch) << '\n';
                    break;
                case 88:
                    cout << "Thank you for using the June Daily Leetcode Problems\n";
                    cout << "Hope you had a great time solving the problems\n";
                    cout << "Have a great day ahead\n";
                    return;
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