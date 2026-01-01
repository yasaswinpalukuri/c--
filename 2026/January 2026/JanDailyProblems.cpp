#include<bits/stdc++.h>
using namespace std;

//Class containing the solutions of the Daily Problems of May 2024
class Solutions{
    public:
    class ListNode {
        public:
        int val;
        ListNode* next;
        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };
    class TrieNode {
    public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    class Trie {
    public:
        TrieNode* root;

        Trie() { root = new TrieNode(); }

        void insert(string word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isEnd = true;
        }
    };

    // class TreeNode{
    //     public:
    //     int val;
    //     TreeNode* left;
    //     TreeNode* right;
    //     TreeNode(){
    //         this->val = 0;
    //         this->left = nullptr;
    //         this->right = nullptr;
    //     }
    //     TreeNode(int val) {
    //         this->val = val;
    //         this->left = nullptr;
    //         this->right = nullptr;
    //     }
    //     TreeNode(int val, TreeNode* left, TreeNode* right) {
    //         this->val = val;
    //         this->left = left;
    //         this->right = right;
    //     }
    // };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    //Function prototypes for all the daily problems of Jan 2026
    /*
    66. Plus One
    Easy
    Topics
    premium lock icon
    Companies
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

    Increment the large integer by one and return the resulting array of digits.

    

    Example 1:

    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.
    Incrementing by one gives 123 + 1 = 124.
    Thus, the result should be [1,2,4].
    Example 2:

    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
    Incrementing by one gives 4321 + 1 = 4322.
    Thus, the result should be [4,3,2,2].
    Example 3:

    Input: digits = [9]
    Output: [1,0]
    Explanation: The array represents the integer 9.
    Incrementing by one gives 9 + 1 = 10.
    Thus, the result should be [1,0].
    

    Constraints:

    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.
    */
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    cout << "Welcome to Jan Daily Leetcode Problems\n";
    cout << "This is Yasaswin Palukuri, with solutions to the Daily Problems of Jan 2026\n";
    cout << "So, without any further ado, let's get started\n";

    do{
        cout << "Enter the day of the problem you want the answer for or 88 to Exit:\n";
        cout << "Day 1: Plus One(Problem: 66)\n";
        cout << "Day 2: \n";
        cout << "Day 3: \n";
        cout << "Day 4: \n";
        cout << "Day 5: \n";
        cout << "Day 6: \n";
        cout << "Day 7: \n";
        cout << "Day 8: \n";
        cout << "Day 9: \n";
        cout << "Day 10: \n";
        cout << "Day 11: \n";
        cout << "Day 12: \n";
        cout << "Day 13: \n";
        cout << "Day 14: \n";
        cout << "Day 15: \n";
        cout << "Day 16: \n";
        cout << "Day 17: \n";
        cout << "Day 18: \n";
        cout << "Day 19: \n";
        cout << "Day 20: \n";
        cout << "Day 21: \n";
        cout << "Day 22: \n";
        cout << "Day 23: \n";
        cout << "Day 24: \n";
        cout << "Day 25: \n";
        cout << "Day 26: \n";
        cout << "Day 27: \n";
        cout << "Day 28: \n";
        cout << "Day 29: \n";
        cout << "Day 30: \n";
        cout << "Day 31: \n";
        cout << "88: Exit" << '\n';
        int day; cin >> day;
        Solutions sol;
        switch(day){
            case 1: {
                cout << "Enter the digits of the large integer as an array:" << '\n';
                int n; cin >> n;
                vector<int> digits(n);
                for (int i = 0; i < n; i++) cin >> digits[i];
                vector<int> result = sol.plusOne(digits);
                cout << "The resulting array of digits after adding one is: ";
                for (int digit : result) cout << digit << " ";
                cout << '\n';
                break;
            }
            case 2: {
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                break;
            }
            case 9:{
                break;
            }
            case 10:{
                break;
            }
            case 11:{
                break;
            }
            case 12:{
                break;
            }
            case 13:{
                break;
            }
            case 14:{
                break;
            }
            case 15:{
                break;
            }
            case 16:{
                break;
            }
            case 17:{
                break;
            }
            case 18:{
                break;
            }
            case 19:{
                break;
            }
            case 20:{
                break;
            }
            case 21:{
                break;
            }
            case 22:{
                break;
            }
            case 23:{
                break;
            }
            case 24:{
                break;
            }
            case 25:{
                break;
            }
            case 26:{
                break;
            }
            case 27:{
                break;
            }
            case 28:{
                break;
            }
            case 29:{
                break;
            }
            case 30:{
                break;
            }
            case 31:{
                break;
            }
            case 88:
                cout << "Thank you for using the May Daily Leetcode Problems :)\n";
                return 0;
            default:
                cout << "Sorry, the problem for the day you entered is not available\n";
                break;
        }
    } while(true);
    return 0;
}