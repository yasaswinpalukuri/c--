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
    ListNode* doubleNumber(ListNode* head) {
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


    // Day 8: Relative Ranks - Q506(Easy)
    /*
    Example 1:
    Input: score = [5,4,3,2,1]
    Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
    Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

    Example 2:
    Input: score = [10,3,8,9,4]
    Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
    */
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> ranks;
        for (int i = 0; i < score.size(); i++) {
            ranks.push_back({score[i], i});
        }
        sort(ranks.begin(), ranks.end(), greater<pair<int, int>>());
        vector<string> res(score.size());
        for (int i = 0; i < ranks.size(); i++) {
            if (i == 0) {
                res[ranks[i].second] = "Gold Medal";
            } else if (i == 1) {
                res[ranks[i].second] = "Silver Medal";
            } else if (i == 2) {
                res[ranks[i].second] = "Bronze Medal";
            } else {
                res[ranks[i].second] = to_string(i + 1);
            }
        }
        return res;
    }

    // Day 9: Maximize Happiness of Selected Children - Q3075(Medium)
    /*
    Example 1:
    Input: happiness = [1,2,3], k = 2
    Output: 4
    Explanation: We can pick 2 children in the following way:
    - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
    - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
    The sum of the happiness values of the selected children is 3 + 1 = 4.

    Example 2:
    Input: happiness = [1,2,3,4], k = 2
    Output: 6
    Explanation: We can pick 2 children in the following way:
    - Pick the child with the happiness value == 4. The happiness value of the remaining children becomes [0,1,2].
    - Pick the child with the happiness value == 2. The happiness value of the remaining children becomes [0,1].
    The sum of the happiness values of the selected children is 4 + 2 = 6.
    */
    int maximizeHappiness(vector<int>& h, int k) {
        /*
            [1,4,5,3,6,7] => happiness 
            n = 6
            k = 1,2,3

            k = 1
            Max happiness = 7 => [1-1,3-1,4-1,5-1,6-1] => [0,2,3,4,5] 

            k = 2
            Max happiness = 7 => [1-1,3-1,4-1,5-1,6-1] => [0,2,3,4,5]
                            +
                            5 => [0-1,2-1,3-1,4-1] => [-1,1,2,3] => [0,1,2,3]
                           ---
                            12

            k = 3
            Max happiness = 7 => [1-1,3-1,4-1,5-1,6-1] => [0,2,3,4,5]
                            +
                            5 => [0-1,2-1,3-1,4-1] => [-1,1,2,3] => [0,1,2,3]
                            +
                            3 => [0-1,1-1,2-1] => [-1,0,1] => [0,0,1]
                           ---
                            15


            [1,2,3] => n =3
            k = 2

            k = 1 => [1,2,3] -> ans = 3 => [1-1,2-1] => [0,1]
            k = 2 => [0,1] -> ans = 3 + 1 => [0-1] => [0]

            ans = 4
        */
        int n = h.size();
        sort(h.begin(), h.end());
        for(int i=0;i<k;i++) h[n-i-1] = max(0,h[n-i-1]-i);
        return accumulate(h.end()-k,h.end(),0);
    }


    // Day 10: K-th Smallest Prime Fraction - Q786(Medium)
    /*
    Example 1:
    Input: arr = [1,2,3,5], k = 3
    Output: [2,5]
    Explanation: The fractions to be considered in sorted order are:
    1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
    The third fraction is 2/5.
    
    Example 2:
    Input: arr = [1,7], k = 1
    Output: [1,7]
    */
   vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < arr.size(); i++) pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second],{cur.first, cur.second}});
        }
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }


    // Day 11: Minimum Cost to Hire K Workers - Q857(Hard)
    /*
    Example 1:
    Input: quality = [10,20,5], wage = [70,50,30], k = 2
    Output: 105.00000
    Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
    
    Example 2:
    Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
    Output: 30.66667
    Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
    */
    double minCostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        double res = DBL_MAX;
        int sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            sum += workers[i].second;
            pq.push(workers[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = min(res, sum * workers[i].first);
            }
        }
        return res;
    }

    // Day 12: Largest Local Values in a Matrix - Q2373(Easy)
    /*
    Example 1:
    Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    Output: [[9,9],[8,6]]
    Explanation: The diagram above shows the original matrix and the generated matrix.
    Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
    
    
    Example 2:
    Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
    Output: [[2,2,2],[2,2,2],[2,2,2]]
    Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
    */
    int findMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> maxLocal(N - 2, vector<int>(N - 2, 0));
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 2; j++) {
                maxLocal[i][j] = findMax(grid, i, j);
            }
        }
        
        return maxLocal;
    }


    // Day 13: Score After Flipping Matrix - Q861(Medium)
    /*
    Example 1:
    Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: grid = [[0]]
    Output: 1
    */
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int score = (1 << (n - 1)) * m;
        for (int j = 1; j < n; j++) {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }
            countSameBits = max(countSameBits, m - countSameBits);
            int columnScore = (1 << (n - j - 1)) * countSameBits;
            score += columnScore;
        }
        return score;
    }


    // Day 14: Path with Maximum Gold - Q1219(Medium)
    /*
    Example 1:
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    Explanation:
    [[0,6,0],
    [5,8,7],
    [0,9,0]]
    Path to get the maximum gold, 9 -> 8 -> 7.
    
    Example 2:
    Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    Output: 28
    Explanation:
    [[1,0,7],
    [2,0,6],
    [3,4,5],
    [0,3,0],
    [9,0,20]]
    Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
    */
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) maxGold = max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
        }
        return maxGold;
    }
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};
    int dfsBacktrack(vector<vector<int>>& grid, int rows, int cols, int row,int col){
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;
        int originalVal = grid[row][col];
        grid[row][col] = 0;
        for (int direction = 0; direction < 4; direction++) {
            maxGold =
                max(maxGold,dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row,DIRECTIONS[direction + 1] + col));
        }
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }

    // Day 15: Find the Safest Path in a Grid - Q2812(Medium)
    /*
    Example 1:
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 0
    Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
    
    
    Example 2:
    Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
    Output: 2
    Explanation: The path depicted in the picture above has a safeness factor of 2 since:
    - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
    It can be shown that there are no other paths with a higher safeness factor.
    

    Example 3:
    Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
    Output: 2
    Explanation: The path depicted in the picture above has a safeness factor of 2 since:
    - The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
    - The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
    It can be shown that there are no other paths with a higher safeness factor.
    */
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSourceQueue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1){
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1){
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }
        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                end = max(end, grid[i][j]);
            }
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(grid, mid)){
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return res;
    }
    
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValidCell(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        int n = grid.size();
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        queue<pair<int, int>> traversalQueue;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        traversalQueue.push({0, 0});
        visited[0][0] = true;
        while (!traversalQueue.empty()) {
            auto curr = traversalQueue.front();
            traversalQueue.pop();
            if (curr.first == n - 1 && curr.second == n - 1) {
                return true;
            }
            for (auto& d : dir) {
                int di = curr.first + d[0];
                int dj = curr.second + d[1];
                if (isValidCell(grid, di, dj) && !visited[di][dj] &&
                    grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.push({di, dj});
                }
            }
        }
        return false;
    }


    // Day 16: Evaluate Boolean Binary Tree - Q2331(Easy)
    /*
    You are given the root of a full binary tree with the following properties:
    * Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
    * on-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
     
    The evaluation of a node is as follows:
    if the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
    Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
        
    Return the boolean result of evaluating the root node.

    A full binary tree is a binary tree where each node has either 0 or 2 children.

    A leaf node is a node that has zero children.

    Example 1:
    Input: root = [2,1,3,null,null,0,1]
    Output: true
    Explanation: The above diagram illustrates the evaluation process.
    The AND node evaluates to False AND True = False.
    The OR node evaluates to True OR False = True.
    The root node evaluates to True, so we return true.


    Example 2:
    Input: root = [0]
    Output: false
    Explanation: The root node is a leaf node and it evaluates to false, so we return false.
    */
    bool evaluateTree(TreeNode* root){
            if (root->left == nullptr and root->right == nullptr) return root->val;
            bool evaluateLeftSubtree = evaluateTree(root->left);
            bool evaluateRightSubtree = evaluateTree(root->right);
            bool evaluateRoot;
            if (root->val == 2) {
                evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
            } else {
                evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
            }

            return evaluateRoot;
    }
    

    // Day 17: Delete Leaves With a Given Value - Q1325(Medium)
    /*
    Given a binary tree root and an integer target, delete all the leaf nodes with value target.
    Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
    it should also be deleted (you need to continue doing that until you cannot).

    Example 1:
    Input: root = [1,2,3,2,null,2,4], target = 2
    Output: [1,null,3,null,4]
    Explanation: Leaf nodes in green with value (target = 2) are removed.
    After removing, new nodes become leaf nodes with value (target = 2).
    
    Example 2:
    Input: root = [1,3,3,3,2], target = 3
    Output: [1,3,null,null,2]
    */
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }

    // Day 18: Distribute Coins in Binary Tree - Q979(Medium)
    /*
    You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

    In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

    Return the minimum number of moves required to make every node have exactly one coin.

    Example 1:
    Input: root = [3,0,0]
    Output: 2
    Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

    Example 2:
    Input: root = [0,3,0]
    Output: 3
    Explanation: From the root of the tree, we move one coin to the root's right child, and two coins to the root's left child.
    */
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }

    int moves;
    int dfs(TreeNode* current) {
        if (current == nullptr) return 0;

        // Calculate the coins each subtree has available to exchange
        int leftCoins = dfs(current->left);
        int rightCoins = dfs(current->right);

        // Add the total number of exchanges to moves
        moves += abs(leftCoins) + abs(rightCoins);

        // The number of coins current has available to exchange
        return (current->val - 1) + leftCoins + rightCoins;
    }

    // Day 19: Find the Maximum Sum of Node Values - Q3068(Hard)
    /*
    There exists an undirected tree with n nodes numbered 0 to n - 1. 
    You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. 
    You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

    Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

    Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
    nums[u] = nums[u] XOR k
    nums[v] = nums[v] XOR k
    Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
    */
    long long maximumValueSum(vector<int>& nums, int k,vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                            vector<vector<long long>>& memo) {
        if (index == nums.size()) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        long long noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        long long xorDone = (nums[index] ^ k) +
                            maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        return memo[index][isEven] = max(xorDone, noXorDone);
    }


    // Day 20: Sum of All Subset XOR Totals - Q1863(Easy)
    /*
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums. 

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
    */
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xorSum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    xorSum ^= nums[j];
                }
            }
            total += xorSum;
        }
        return total;
    }


    // Day 21: Subsets - Q78(Medium)
    /*
        Given an integer array nums of unique elements, return all possible subsets(the power set).
        The solution set must not contain duplicate subsets. Return the solution in any order.
        Example 1:
        Input: nums = [1,2,3]
        Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

        Example 2:

        Input: nums = [0]
        Output: [[],[0]]
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, subset, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }


    // Day 22: Palindrome Partitoning - Q131(Medium)
    /*
        Given a string s, partition s such that every substring of the partition is a palindrome
        Return all possible palindrome partitioning of s.

        Example 1:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]
        
        Example 2:
        Input: s = "a"
        Output: [["a"]]
    */
    vector<vector<string>> partition(string s){
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right){
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    // Day 23: The Number of Beautiful Subsets - Q2597(Medium)
    /*
        You are given an array nums of positive integers and a positive integer k.
        A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
        Return the number of non-empty beautiful subsets of the array nums.
        A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums.
        Two subsets are different if and only if the chosen indices to delete are different.

        Example 1:
        Input: nums = [2,4,6], k = 2
        Output: 4
        Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
        It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
        
        Example 2:
        Input: nums = [1], k = 1
        Output: 1
        Explanation: The beautiful subset of the array nums is [1].
        It can be proved that there is only 1 beautiful subset in the array [1].
    */
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }
        for (auto& fr : freqMap) {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            totalCount *= countBeautifulSubsets(subsets, subsets.size(), k, 0);
        }

        return totalCount - 1;
    }

    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,int difference, int i){
        if (i == numSubsets) {
            return 1;
        }
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        int take = (1 << subsets[i].second) - 1;
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 2);
        } else {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        }

        return skip + take;
    }


    // Day 24: Maximum Score Words Formed by Letters - Q1255(Hard)
    /*
        Given a list of words, list of  single letters (might be repeating) and score of every character.

        Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

        It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

        

        Example 1:
        Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
        Output: 23
        Explanation:
        Score  a=1, c=9, d=5, g=3, o=2
        Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
        Words "dad" and "dog" only get a score of 21.
        
        Example 2:
        Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
        Output: 27
        Explanation:
        Score  a=4, b=4, c=4, x=5, z=10
        Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
        Word "xxxz" only get a score of 25.
        
        Example 3:
        Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
        Output: 0
        Explanation:
        Letter "e" can only be used once.
    */
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> subsetLetters = vector<int>(26, 0);
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, subsetLetters, 0);
        return maxScore;
    }
    int maxScore;
    vector<int> freq;
    bool isValidWord(vector<int>& subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score, vector<int>& subsetLetters, int totalScore) {
        if (w == -1) {
            maxScore = max(maxScore, totalScore);
            return;
        }
        check(w - 1, words, score, subsetLetters, totalScore);
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) check(w - 1, words, score, subsetLetters, totalScore);
        
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }


    // Day 25: Word Break II - Q14(Hard)
    /*
        Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

        Note that the same word in the dictionary may be reused multiple times in the segmentation.

        Example 1:
        Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
        Output: ["cats and dog","cat sand dog"]
        
        Example 2:
        Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
        Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        Explanation: Note that you are allowed to reuse a dictionary word.
        
        Example 3:
        Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        Output: []

        Constraints:
        1 <= s.length <= 20
        1 <= wordDict.length <= 1000
        1 <= wordDict[i].length <= 10
        s and wordDict[i] consist of only lowercase English letters.
        All the strings of wordDict are unique.
        Input is generated in a way that the length of the answer doesn't exceed 10^5.
    */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }
        unordered_map<int, vector<string>> dp;
        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {
            vector<string> validSentences;
            TrieNode* currentNode = trie.root;
            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
                char c = s[endIdx];
                int index = c - 'a';
                if (!currentNode->children[index]) {
                    break;
                }
                currentNode = currentNode->children[index];
                if (currentNode->isEnd) {
                    string currentWord =
                        s.substr(startIdx, endIdx - startIdx + 1);
                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {
                        for (string sentence : dp[endIdx + 1]) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }
            dp[startIdx] = validSentences;
        }
        return dp[0];
    }


    // Day 26: Student Attendance Record II - Q552(Hard)
    /*
        An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

        'A': Absent.
        'L': Late.
        'P': Present.
        Any student is eligible for an attendance award if they meet both of the following criteria:

        The student was absent ('A') for strictly fewer than 2 days total.
        The student was never late ('L') for 3 or more consecutive days.
        Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

        Example 1:
        Input: n = 2
        Output: 8
        Explanation: There are 8 records with length 2 that are eligible for an award:
        "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
        Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
        
        Example 2:
        Input: n = 1
        Output: 3

        Example 3:
        Input: n = 10101
        Output: 183236316
        

        Constraints:
        1 <= n <= 10^5
    */
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> comb;
    int checkRecords(int n){
        comb = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return checkCombinations(n, 0, 0);
    }
    int checkCombinations(int n, int a, int l){
        if(a >= 2 || l >= 3) return 0; // Not selected if there are 2 or more absences or 3 or more consecutive late days
        if(n == 0) return 1;
        if(comb[n][a][l] != -1) return comb[n][a][l];
        int c = 0;
        c = checkCombinations(n-1,a,0); // "P" case
        c = (c + checkCombinations(n-1,a+1,0))%1000000007; // "A" case;
        c = (c + checkCombinations(n-1,a,l+1))%1000000007; // "L" case
        return comb[n][a][l] = c;
    }


    // Day 27: Special Array With X Elements Greater Than or Equal X - Q1608(Easy)
    /*
        You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

        Notice that x does not have to be an element in nums.

        Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

        Example 1:
        Input: nums = [3,5]
        Output: 2
        Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
        
        Example 2:
        Input: nums = [0,0]
        Output: -1
        Explanation: No numbers fit the criteria for x.
        If x = 0, there should be 0 numbers >= x, but there are 2.
        If x = 1, there should be 1 number >= x, but there are 0.
        If x = 2, there should be 2 numbers >= x, but there are 0.
        x cannot be greater since there are only 2 numbers in nums.
        
        Example 3:
        Input: nums = [0,4,3,0,4]
        Output: 3
        Explanation: There are 3 values that are greater than or equal to 3.
        

        Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 1000
    */
    int specialArray(vector<int>& nums) {
        // int n = nums.size();
        // for (int x = 0; x <= n; x++) {
        //     int count = 0;
        //     for (int num : nums) {
        //         if (num >= x) {
        //             count++;
        //         }
        //     }
        //     if (count == x) {
        //         return x;
        //     }
        // }
        // return -1;
    }
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
        cout << "Day 8: Relative Ranks\n";
        cout << "Day 9: Maximize Happiness of Selected Children\n";
        cout << "Day 10: K-th Smallest Prime Fraction\n";
        cout << "Day 11: Minimum Cost to Hire K Workers\n";
        cout << "Day 12: Largest Local Values in a Matrix\n";
        cout << "Day 13: Score After Flipping Matrix\n";
        cout << "Day 14: Path with Maximum Gold\n";
        cout << "Day 15: Find the Safest Path in a Grid\n";
        cout << "Day 16: Evaluate Boolean Binary Tree\n";
        cout << "Day 17: Delete Leaves With a Given Value\n";
        cout << "Day 18: Distribute Coins in Binary Tree\n";
        cout << "Day 19: Find the Maximum Sum of Node Values\n";
        cout << "Day 20: Sum of All Subset XOR Totals\n";
        cout << "Day 21: Subsets\n";
        cout << "Day 22: Palindrome Partitoning\n";
        cout << "Day 23: The Number of Beautiful Subsets\n";
        cout << "Day 24: Maximum Score Words Formed by Letters\n";
        cout << "Day 25: Word Break II\n";
        cout << "Day 26: Student Attendance Record II\n";
        cout << "Day 27: Special Array With X Elements Greater Than or Equal X\n";
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
                Solutions::ListNode* newHead = sol.doubleNumber(head);
                cout << "The linked list after doubling the number is: ";
                while (newHead != nullptr) {
                    cout << newHead->val << " ";
                    newHead = newHead->next;
                }
                cout << '\n';
                break;
            }
            case 8:{
                cout << "Enter the number of scores:" << '\n';
                int n; cin >> n;
                vector<int> scores(n);
                cout << "Enter the scores of the players:" << '\n';
                for (int i = 0; i < n; i++) cin >> scores[i];
                vector<string> ranks = sol.findRelativeRanks(scores);
                cout << "Scores of the players: ";
                for (int i = 0; i < n; i++) cout << scores[i] << " ";
                cout << "\nThe relative ranks of the players are: ";
                for (string rank : ranks) cout << rank << " ";
                cout << '\n';
                break;
            }
            case 9:{
                cout << "Enter the number of children and the value of k:" << '\n';
                int n, k; cin >> n >> k;
                vector<int> happiness(n);
                cout << "Enter the happiness values of the children:" << '\n';
                for (int i = 0; i < n; i++) cin >> happiness[i];
                cout << "The maximum happiness of the selected children is: " << sol.maximizeHappiness(happiness, k) << '\n';
                break;
            }
            case 10:{
                cout << "Enter the number of elements in the array and the value of k:" << '\n';
                int n, k; cin >> n >> k;
                vector<int> arr(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> arr[i];
                vector<int> fraction = sol.kthSmallestPrimeFraction(arr, k);
                cout << "The k-th smallest prime fraction is: " << fraction[0] << "/" << fraction[1] << '\n';
                break;
            }
            case 11:{
                cout << "Enter the number of workers and the value of k:" << '\n';
                int n, k; cin >> n >> k;
                vector<int> quality(n), wage(n);
                cout << "Enter the quality of the workers:" << '\n';
                for (int i = 0; i < n; i++) cin >> quality[i];
                cout << "Enter the wage of the workers:" << '\n';
                for (int i = 0; i < n; i++) cin >> wage[i];
                cout << "The minimum cost to hire k workers is: " << sol.minCostToHireWorkers(quality, wage, k) << '\n';
                break;
            }
            case 12:{
                cout << "Enter the number of rows and columns in the matrix:" << '\n';
                int n; cin >> n;
                vector<vector<int>> grid(n, vector<int>(n));
                cout << "Enter the elements of the matrix:" << '\n';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> grid[i][j];
                    }
                }
                vector<vector<int>> maxLocal = sol.largestLocal(grid);
                cout << "The largest local values in the matrix are:" << '\n';
                for (int i = 0; i < n - 2; i++) {
                    for (int j = 0; j < n - 2; j++) {
                        cout << maxLocal[i][j] << " ";
                    }
                    cout << '\n';
                }
                break;
            }
            case 13:{
                cout << "Enter the number of rows and columns in the matrix:" << '\n';
                int n; cin >> n;
                vector<vector<int>> grid(n, vector<int>(n));
                cout << "Enter the elements of the matrix:" << '\n';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> grid[i][j];
                    }
                }
                cout << "The score after flipping the matrix is: " << sol.matrixScore(grid) << '\n';
                break;
            }
            case 14:{
                cout << "Enter the number of rows in the matrix:" << '\n';
                int n; cin >> n;
                cout << "Enter the number of columns in the matrix:" << '\n';
                int m; cin >> m;
                vector<vector<int>> grid(n, vector<int>(m));
                cout << "Enter the elements of the matrix:" << '\n';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cin >> grid[i][j];
                    }
                }
                cout << "The maximum gold that can be obtained is: " << sol.getMaximumGold(grid) << '\n';
                break;
            }
            case 15:{
                cout << "Enter the number of rows in the matrix:" << '\n';
                int n; cin >> n;
                vector<vector<int>> grid(n, vector<int>(n));
                cout << "Enter the elements of the matrix:" << '\n';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> grid[i][j];
                    }
                }
                cout << "The safest path in the grid is: " << sol.maximumSafenessFactor(grid) << '\n';
                break;
            }
            case 16:{
                cout << "Enter the number of nodes in the binary tree:" << '\n';
                int n; cin >> n;
                cout << "Enter the values of the nodes in the binary tree:" << '\n';
                vector<int> nodes(n);
                for (int i = 0; i < n; i++) cin >> nodes[i];
                Solutions::TreeNode* root = new Solutions::TreeNode(nodes[0]);
                queue<Solutions::TreeNode*> q;
                q.push(root);
                int i = 1;
                while (!q.empty() && i < n) {
                    Solutions::TreeNode* node = q.front();
                    q.pop();
                    if (nodes[i] != -1) {
                        node->left = new Solutions::TreeNode(nodes[i]);
                        q.push(node->left);
                    }
                    i++;
                    if (i < n && nodes[i] != -1) {
                        node->right = new Solutions::TreeNode(nodes[i]);
                        q.push(node->right);
                    }
                    i++;
                }
                cout << "The boolean result of evaluating the root node is: " << sol.evaluateTree(root) << '\n';
                break;
            }
            case 17:{
                cout << "Enter the number of nodes in the binary tree:" << '\n';
                int n; cin >> n;
                cout << "Enter the values of the nodes in the binary tree:" << '\n';
                vector<int> nodes(n);
                for (int i = 0; i < n; i++) cin >> nodes[i];
                Solutions::TreeNode* root = new Solutions::TreeNode(nodes[0]);
                queue<Solutions::TreeNode*> q;
                q.push(root);
                int i = 1;
                while (!q.empty() && i < n) {
                    Solutions::TreeNode* node = q.front();
                    q.pop();
                    if (nodes[i] != -1) {
                        node->left = new Solutions::TreeNode(nodes[i]);
                        q.push(node->left);
                    }
                    i++;
                    if (i < n && nodes[i] != -1) {
                        node->right = new Solutions::TreeNode(nodes[i]);
                        q.push(node->right);
                    }
                    i++;
                }
                cout << "Enter the value of the target node:" << '\n';
                int target; cin >> target;
                Solutions::TreeNode* newRoot = sol.removeLeafNodes(root, target);
                cout << "The binary tree after deleting the leaf nodes with value target is: ";
                queue<Solutions::TreeNode*> q1;
                q1.push(newRoot);
                while (!q1.empty()) {
                    Solutions::TreeNode* node = q1.front();
                    q1.pop();
                    if (node != nullptr) {
                        cout << node->val << " ";
                        q1.push(node->left);
                        q1.push(node->right);
                    }
                }
                cout << '\n';
                break;
            }
            case 18:{
                cout << "Enter the number of nodes in the binary tree:" << '\n';
                int n; cin >> n;
                cout << "Enter the values of the nodes in the binary tree:" << '\n';
                vector<int> nodes(n);
                for (int i = 0; i < n; i++) cin >> nodes[i];
                Solutions::TreeNode* root = new Solutions::TreeNode(nodes[0]);
                queue<Solutions::TreeNode*> q;
                q.push(root);
                int i = 1;
                while (!q.empty() && i < n) {
                    Solutions::TreeNode* node = q.front();
                    q.pop();
                    if (nodes[i] != -1) {
                        node->left = new Solutions::TreeNode(nodes[i]);
                        q.push(node->left);
                    }
                    i++;
                    if (i < n && nodes[i] != -1) {
                        node->right = new Solutions::TreeNode(nodes[i]);
                        q.push(node->right);
                    }
                    i++;
                }
                cout << "The minimum number of moves required to make every node have exactly one coin is: " << sol.distributeCoins(root) << '\n';
                break;
            }
            case 19:{
                cout << "Enter the number of nodes in the binary tree:" << '\n';
                int n; cin >> n;
                cout << "Enter the values of the nodes in the binary tree:" << '\n';
                vector<int> nodes(n);
                for (int i = 0; i < n; i++) cin >> nodes[i];
                cout << "Enter the value of k:" << '\n';
                int k; cin >> k;
                cout << "Enter the number of edges in the tree:" << '\n';
                int m; cin >> m;
                vector<vector<int>> edges(m, vector<int>(2));
                cout << "Enter the edges of the tree:" << '\n';
                for (int i = 0; i < m; i++) {
                    cin >> edges[i][0] >> edges[i][1];
                }
                cout << "The maximum sum of node values is: " << sol.maximumValueSum(nodes, k, edges) << '\n';
                break;
            }
            case 20:{
                cout << "Enter the number of elements in the array:" << '\n';
                int n; cin >> n;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "The sum of all XOR totals for every subset of nums is: " << sol.subsetXORSum(nums) << '\n';
                break;
            }
            case 21:{
                cout << "Enter the number of elements in the array:" << '\n';
                int n; cin >> n;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                vector<vector<int>> subsets = sol.subsets(nums);
                cout << "The subsets of the array are:" << "\n[";
                for (vector<int> subset : subsets) {
                    cout << "[";
                    for (int num : subset) cout << num << ",";
                    cout << "\b]\n";
                }
                cout << '\n';
                break;
            }
            case 22:{
                cout << "Enter the string:" << '\n';
                string s; cin >> s;
                vector<vector<string>> partitions = sol.partition(s);
                cout << "The palindrome partitioning of the string is:" << '\n';
                for (vector<string> partition : partitions) {
                    cout << "[";
                    for (string str : partition) cout << str << ",";
                    cout << "\b]\n";
                }
                break;
            }
            case 23:{
                cout << "Enter the number of elements in the array and the value of k:" << '\n';
                int n, k; cin >> n >> k;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "The number of non-empty beautiful subsets of the array nums is: " << sol.beautifulSubsets(nums, k) << '\n';
                break;
            }
            case 24:{
                cout << "Enter the number of words in the list:" << '\n';
                int n; cin >> n;
                vector<string> words(n);
                cout << "Enter the words in the list:" << '\n';
                for (int i = 0; i < n; i++) cin >> words[i];
                cout << "Enter the number of letters in the list:" << '\n';
                int m; cin >> m;
                vector<char> letters(m);
                cout << "Enter the letters in the list:" << '\n';
                for (int i = 0; i < m; i++) cin >> letters[i];
                cout << "Enter the number of scores:" << '\n';
                vector<int> scores(26);
                for (int i = 0; i < 26; i++) cin >> scores[i];
                cout << "The maximum score of any valid set of words formed by using the given letters is: " << sol.maxScoreWords(words, letters, scores) << '\n';
                break;
            }
            case 25:{
                cout << "Enter the string:" << '\n';
                string s; cin >> s;
                cout << "Enter the number of words in the dictionary:" << '\n';
                int n; cin >> n;
                vector<string> wordDict(n);
                cout << "Enter the words in the dictionary:" << '\n';
                for (int i = 0; i < n; i++) cin >> wordDict[i];
                vector<string> sentences = sol.wordBreak(s, wordDict);
                cout << "The possible sentences formed by adding spaces in s are:" << '\n';
                for (string sentence : sentences) cout << sentence << '\n';
                break;
            }
            case 26:{
                cout << "Enter the number of days:" << '\n';
                int n; cin >> n;
                cout << "The number of possible attendance records of length n that make a student eligible for an attendance award is: " << sol.checkRecords(n) << '\n';
                break;
            }
            case 27:{
                cout << "Enter the number of elements in the array:" << '\n';
                int n; cin >> n;
                vector<int> nums(n);
                cout << "Enter the elements of the array:" << '\n';
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "The value of x if the array is special is: " << sol.specialArray(nums) << '\n';
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