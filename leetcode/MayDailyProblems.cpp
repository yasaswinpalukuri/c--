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
    // Day 1: Reverse Prefix of Word - Q2000(Easy)
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

    // Day 2: Largest Positive Integer That Exists With Its Negative - Q2441(Easy)
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

    // Method 2: Using Sorting
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

    // Method 3: Using Two Pointers
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

    int compareVersion(string& v1, string& v2) {
        const int n1=v1.size(), n2=v2.size();
        int x1=0, x2=0;
        for(int i=0, j=0; i<n1 || j<n2; i++, j++){
            while(i<n1 && v1[i]!='.') x1=10*x1+(v1[i++]-'0');
            while(j<n2 && v2[j]!='.') x2=10*x2+(v2[j++]-'0');
            if (x1<x2) return -1;
            else if (x1>x2) return 1;
            x1=0;
            x2=0;
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
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int l=0,ans=0,r=p.size()-1;
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
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
};

int main() {
    cout << "Welcome to May Daily Leetcode Problems\n";
    cout << "This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024\n";
    cout << "So, without any further ado, let's get started\n";

    do{
        cout << "Enter the day of the problem you want the answer for or 88 to Exit:\n";
        cout << "Day 1: Reverse Prefix of Word\n";
        cout << "Day 2: Largest Positive Integer That Exists With Its Negative\n";
        cout << "Day 3: Compare Version Numbers\n";
        cout << "Day 4: Boats to Save People\n";
        cout << "Day 5: Delete Node in a Linked List\n";
        cout << "Day 6: Remove Nodes From Linked List\n";
        cout << "Day 7: Double a Number Represented as a Linked List\n";
        cout << "88: Exit" << '\n';
        int day; cin >> day;
        Solutions sol;
        switch(day){
            case 1: {
                cout << "Enter the word and the character you want to reverse the prefix of:" << '\n';
                string word; char ch;
                cin >> word >> ch;
                cout << "The word after reversing the prefix of the character is: " << sol.reversePrefix(word, ch) << '\n';
                break;
            }
            case 2: {
                cout << "Enter the number of elements in the array:" << '\n';
                int n; cin >> n;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "The largest positive integer that exists with its negative is(Using HashSet): " << sol.findMaxK(nums) << '\n';
                cout << "The largest positive integer that exists with its negative is(Using Arrays.sort and Arrays.binarySearch): " << sol.findMaxKSorting(nums) << '\n';
                cout << "The largest positive integer that exists with its negative is(Using Two Pointer Technique): " << sol.findMaxK2Pointers(nums) << "\n";
                break;
            }
            case 3:{
                cout << "Enter the two version numbers:" << '\n';
                string version1, version2;
                cin >> version1 >> version2;
                cout << "The comparison of the two version numbers is: " << sol.compareVersion(version1, version2) << '\n';
                break;
            }
            case 4:{
                cout << "Enter the number of people and the limit of the boat:" << '\n';
                int n, limit; cin >> n >> limit;
                vector<int> people(n);
                cout << "Enter the weights of the people:" << '\n';
                for (int i = 0; i < n; i++) cin >> people[i];
                cout << "The number of boats required to save the people is: " << sol.numRescueBoats(people, limit) << '\n';
                break;
            }
            case 5:{
                cout << "Enter the number of elements in the linked list:" << '\n';
                int n; cin >> n;
                cout << "Enter the elements of the linked list:" << '\n';
                int val; cin >> val;
                Solutions::ListNode* head = new Solutions::ListNode(val);
                Solutions::ListNode* temp = head;
                for (int i = 1; i < n; i++) {
                    cin >> val;
                    temp->next = new Solutions::ListNode(val);
                    temp = temp->next;
                }
                cout << "Enter the value of the node you want to delete:" << '\n';
                int nodeVal; cin >> nodeVal;
                Solutions::ListNode* node = head;
                while (node->val != nodeVal) node = node->next;
                sol.deleteNode(node);
                cout << "The linked list after deleting the node is: ";
                while (head != nullptr) {
                    cout << head->val << " ";
                    head = head->next;
                }
                cout << '\n';
                break;
            }
            case 6:{
                cout << "Enter the number of elements in the linked list:" << '\n';
                int n; cin >> n;
                cout << "Enter the elements of the linked list:" << '\n';
                int val; cin >> val;
                Solutions::ListNode* head = new Solutions::ListNode(val);
                Solutions::ListNode* temp = head;
                for (int i = 1; i < n; i++) {
                    cin >> val;
                    temp->next = new Solutions::ListNode(val);
                    temp = temp->next;
                }
                Solutions::ListNode* newHead = sol.removeNodes(head);
                cout << "The linked list after removing the nodes is: ";
                while (newHead != nullptr) {
                    cout << newHead->val << " ";
                    newHead = newHead->next;
                }
                cout << '\n';
                break;
            }
            case 7:{
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