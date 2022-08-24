#include <bits/stdc++.h>
using namespace std;


/*
               3
              / \
             1   4
            /  / \
           3  1   5

        **A node X in the tree is named good when in the path from root to X there are no nodes whose value is greater than X. 
        Here good nodes are: 3(root), 3(left leaf),4 and 5.
        
        To solve this, we will follow these steps −
        Define a function dfs(), this will take node, val,

        if node is null, then −

        return

        ret := ret + (1 when val <= val of node, otherwise 0)

        dfs(left of node, maximum of val and val of node)

        dfs(right of node, maximum of val and val of node)

        From the main method do the following −

        ret := 0

        dfs(root, -inf)

        return ret
*/
class TreeNode{
public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data){
      val = data;
      left = NULL;
      right = NULL;
   }
};

void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }else{
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != NULL)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
         return;
      }else{
         q.push(temp->right);
      }
   }
}

TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}

class Solution {
public:
   int ret;
   void dfs(TreeNode* node, int val){
      if (!node)
         return;
      ret += val <= node->val;
      dfs(node->left, max(val, node->val));
      dfs(node->right, max(val, node->val));
   }
   int goodNodes(TreeNode* root){
      ret = 0;
      dfs(root, INT_MIN);
      return ret;
   }
};


int main(){
   Solution ob;
   vector<int> v = {3,1,4,3,NULL,1,5};
   TreeNode *root = make_tree(v);
   cout << (ob.goodNodes(root));
}

//Thank you TutorialPoint for the code.