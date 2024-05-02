#include<bits/stdc++.h>
using namespace std;

// Function predefined for the problems
string reversePrefix(string word, char ch);
int findMaxK(vector<int>& nums);
int findMaxKSorting(vector<int>& nums);
int findMaxK2Pointers(vector<int>& nums);

int main() {
    cout << "Welcome to May Daily Leetcode Problems" << '\n';
    cout << "This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024" << '\n';
    cout << "So, without any further ado, let's get started" << '\n';

    do{
        cout << "Enter the day of the problem you want the answer for or 88 to Exit:" << '\n';
        cout << "Day 1: Reverse Prefix of Word" << '\n';
        cout << "Day 2: Largest Positive Integer That Exists With Its Negative" << '\n';
        cout << "88: Exit" << '\n';
        int day; cin >> day;
        switch(day){
            case 1: {
                cout << "Enter the word and the character you want to reverse the prefix of:" << '\n';
                string word; char ch;
                cin >> word >> ch;
                cout << "The word after reversing the prefix of the character is: " << reversePrefix(word, ch) << '\n';
                break;
            }
            case 2: {
                cout << "Enter the number of elements in the array:" << '\n';
                int n; cin >> n;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "The largest positive integer that exists with its negative is(Using HashSet): " << findMaxK(nums) << '\n';
                cout << "The largest positive integer that exists with its negative is(Using Arrays.sort and Arrays.binarySearch): " << findMaxKSorting(nums) << '\n';
                cout << "The largest positive integer that exists with its negative is(Using Two Pointer Technique): " << findMaxK2Pointers(nums) << "\n";
                break;
            }
            case 88:
                cout << "Thank you for using the May Daily Leetcode Problems\n";
                return 0;
            default:
                cout << "Sorry, the problem for the day you entered is not available\n";
                break;
        }
    } while(true);
    return 0;
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
string reversePrefix(string word, char ch) {
    int index = word.find(ch);
    if(index != string::npos) {
        reverse(word.begin(), word.begin() + index + 1);
    }
    return word;
}


int findMaxK(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int maxK = INT_MIN;
    for (int num : nums) {
        if (set.count(-num)) {
            maxK = max(maxK, num);
        }
    }
    return maxK != INT_MIN ? maxK : -1;
}


int findMaxKSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxK = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (binary_search(nums.begin(), nums.end(), -nums[i])) {
            maxK = max(maxK, nums[i]);
        }
    }
    return maxK != INT_MIN ? maxK : -1;
}


int findMaxK2Pointers(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int maxK = INT_MIN;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == 0) {
            maxK = max(maxK, nums[right]);
            left++;
            right--;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    return maxK != INT_MIN ? maxK : -1;
}
