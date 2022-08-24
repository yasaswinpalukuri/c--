#include<bits/stdc++.h>
using namespace std;

class BSTNode{
  public:
  int d;
  BSTNode *left,*right;
  BSTNode(){}
  BSTNode(int d){
      this->d = d;
      left = right = nullptr;
  }
};

void preOrder(struct BSTNode* root){
    //root -> left -> right
    cout<<root->d<<" ";
    if(root->left != NULL) preOrder(root->left);
    if(root->right != NULL) preOrder(root->right);
}

void inOrder(struct BSTNode* root){
    //left -> root -> right
    if(root->left != NULL) inOrder(root->left);
    cout<<root->d<<" ";
    if(root->right != NULL) inOrder(root->right);
}

void postOrder(struct BSTNode* root){
    //left -> right -> root
    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    cout<<root->d<<" ";
}

BSTNode* insertNode(BSTNode* r,int k){
    if(r == nullptr) return new BSTNode(k);
    if(r->d > k) r->left = insertNode(r->left,k);
    if(r->d < k) r->right = insertNode(r->right,k);
    return r;
}

bool search(BSTNode* r,int k){
    bool ans=false;
    if(r->d == k) ans = true;
    if(r->d > k) ans = search(r->left,k);
    if(r->d < k) ans = search(r->right,k);
    return ans;
}

BSTNode* deleteNode(BSTNode* r,int k){
    if(r == nullptr) return nullptr;
    if(r->d > k) r->left = deleteNode(r->left,k);
    if(r->d < k) r->right = deleteNode(r->right,k);
    if(r->d == k){
        if(r->left == nullptr && r->right == nullptr){
            delete(r);
            return nullptr;
        }
        if(r->left == nullptr){
            BSTNode* temp = r->right;
            delete(r);
            return temp;
        }
        if(r->right == nullptr){
            BSTNode* temp = r->left;
            delete(r);
            return temp;
        }
        BSTNode* temp = r->right;
        while(temp->left != nullptr) temp = temp->left;
        r->d = temp->d;
        r->right = deleteNode(r->right,temp->d);
    }
    return r;
}

int BSTNodeCount(BSTNode *r){
    if(r == nullptr) return 0;
    return BSTNodeCount(r->right)+BSTNodeCount(r->left)+1;
}

int BSTNodesSum(BSTNode *r){
    if(r == nullptr) return 0;
    return BSTNodesSum(r->right)+BSTNodesSum(r->left)+(r->d);
}

int BSTMaxNode(BSTNode *r){
    while(r->right != nullptr) r = r->right;
    return r->d;
}

int BSTMinNode(BSTNode *r){
    while(r->left != nullptr) r = r -> left;
    return r->d;
}

int countLeafNodes(BSTNode *r){
	if(r == nullptr) return 0;
	if(r->left == nullptr && r->right == nullptr) return 1;
	return countLeafNodes(r->right)+countLeafNodes(r->left);
}

int sumOfLeafs(BSTNode *r){
	if(r == nullptr) return 0;
	if(r->left == nullptr && r->right == nullptr) return r->d;
	return countLeafNodes(r->right)+countLeafNodes(r->left);
}

int depth(BSTNode* r,int k,int d){
    if(r == nullptr) return -1;
    if(r->d == k) return d;
    if(r->d < k) return depth(r->right,k,d+1);
    if(r->d > k) return depth(r->left,k,d+1);
    return -1;
}

int depthOfBinaryTreeNode(BSTNode* r,int k,int d){
    if(r == nullptr) return -1;
    cout<<"r->d="<<r->d<<"\n";
    if(r->d == k) return d;
    else{
        int l,ri;
        if(r->left != nullptr) l = depthOfBinaryTreeNode(r->left,k,d+1);
        if(l >= 0) d = l;
        if(r->right != nullptr) ri = depthOfBinaryTreeNode(r->right,k,d+1);
        if(ri >= 0) d =ri;
    }
    return -1;
}

int d=-1;
void nodeDepth(BSTNode *r,int k,int c){
    if(r == nullptr) return;
    if(r->d == k) d = c;
    if(r->left != nullptr) nodeDepth(r->left,k,c+1);
    if(r->right != nullptr) nodeDepth(r->right,k,c+1);
}

int main(){
    BSTNode* r=new BSTNode();
    r = nullptr;
    /*
    // 72 9 5 8 10 3 4 22 6 11 73 74 75 76 77 78 79 30
    
                          72
                      /        \
                      9         73
                   /     \        \
                  5       10       74
               /     \      \       \ 
              3       8      22      75
               \     /       /  \     \
                4   6       11   30    76
                                        \ 
                                         77
                                          \
                                           78
                                            \ 
                                             79
    */
    r = insertNode(r,72);
    r = insertNode(r,9);
    r = insertNode(r,5);
    r = insertNode(r,8);
    r = insertNode(r,10);
    r = insertNode(r,3);
    r = insertNode(r,4);
    r = insertNode(r,22);
    r = insertNode(r,6);
    r = insertNode(r,11);
    r = insertNode(r,73);
    r = insertNode(r,74);
    r = insertNode(r,75);
    r = insertNode(r,76);
    r = insertNode(r,77);
    r = insertNode(r,78);
    r = insertNode(r,79);
    r = insertNode(r,30);
    cout<<"Depth of Binary Tree Node 11: "<<depthOfBinaryTreeNode(r,11,0)<<"\n";
    nodeDepth(r,11,0);
    cout<<"Depth of Binary Tree Node 11: "<<d<<"\n";
    do{
        cout<<"====Menu====\n";
        cout<<"1.Insert\n";
        cout<<"2.Search\n";
        cout<<"3.Delete\n";
        cout<<"4.In-Order\n";
        cout<<"5.Pre-Order\n";
        cout<<"6.Post-Order\n";
        cout<<"7.Node Count\n";
        cout<<"8.Nodes Sum\n";
        cout<<"9.Max Node\n";
        cout<<"10.Min Node\n";
        cout<<"11.Count Leaf Nodes\n";
        cout<<"12.Sum Leaf Nodes\n";
        cout<<"13. Depth of a Node\n";
        cout<<"14.Exit\n";
        cout<<"Enter your choice:";
        int ch; cin>>ch;
        switch(ch){
            case 1:{
                int k; cout<<"Enter value you wanna insert:"; cin>>k;
                r = insertNode(r,k);
                break;
            }
            case 2:{
                int k; cout<<"Enter value you wanna search:"; cin>>k;
                if(search(r,k)) cout<<"Yes,the Node exists in BST\n";
                else cout<<"No,the Node doesn't exist in BST\n";
                break;
            }
            case 3:{
                int k; cout<<"Enter value you wanna delete:"; cin>>k;
                r = deleteNode(r,k);
                break;
            }
            case 4:{
                cout<<"In-order : ";
                inOrder(r); cout<<"\n";
                break;
            }
            case 5:{
                cout<<"Pre-Order : ";
                preOrder(r); cout<<"\n";
                break;
            }
            case 6:{
                cout<<"Post-Order :";
                postOrder(r); cout<<"\n";
                break;
            }
            case 7: cout<<BSTNodeCount(r)<<"\n"; break;
            case 8: cout<<BSTNodesSum(r)<<"\n"; break;
            
            case 9: cout<<"Max Node : "<<BSTMaxNode(r)<<"\n"; break;
            case 10: cout<<"Min Node : "<<BSTMinNode(r)<<"\n"; break;
            
            case 11: cout<<"Number of Leafs : "<<countLeafNodes(r)<<"\n"; break;
            case 12: cout<<"Sum of Leafs : "<<sumOfLeafs(r)<<"\n"; break;
            
            case 13:{
                int k; cout<<"Enter Node to check the depth : "; cin>>k;
                d = -1;
                int ans = depth(r,k,0);
                if(ans == -1) cout<<"Node not found\n";
                else cout<<"Depth of node "<<k<<" is : "<<ans<<"\n";
                break;
            }
            default: cout<<"We shall take a leave, thank you for using :)"; exit(0);
        }
    }while(true);
}