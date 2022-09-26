#include <bits/stdc++.h>
using namespace std;

bool isCoPrime(int a,int b){
    if(__gcd(a,b) == 1) return true;
    else return false;
}

class Node{
    public:
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
    Node() {}
    Node(int x){ 
        data = x;
    }
};

int NodeCountCoPrime(Node *r,int k){
    if(r == nullptr) return 0;
    return NodeCountCoPrime(r->right,k)+NodeCountCoPrime(r->left,k)+(isCoPrime(r->data,k))?1:0;
}

Node* createTree(int parent[], int val[],int n){
    vector<Node*> ref;
    int ans[n];
    Node* root = new Node();
    for (int i = 0; i < n; i++) {
        Node* temp = new Node(val[i]);
        ref.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        if (parent[i] == -1){
            root = ref[i];
        }
        else{
            ans[i] = isCoPrime(val[parent[i]],ref[parent[i]]->data);
            if (ref[parent[i]]->left == NULL) ref[parent[i]]->left = ref[i];
            else ref[parent[i]]->right = ref[i];
        }
    }
    return root;
}

int main() {
    // int n; cin>>n;
    // int p[n],val[n];
    // vector<int> ans(n);
    // p[0] = -1;
    //for(int i=1;i<n-1;i++) cin>>p[i];
    // for(int i=0;i<n;i++){
    //     cin>>val[i];
    //     if(i != 0) ans[i] = (isCoPrime(val[0],val[i]))?1:0;
    // }
    int p[]={-1,1,1,3,3};
    int val[]={1,2,3,4,5};
    // Node* r = createTree(p,val,n);
    Node* r = createTree(p,val,5);

    return 0;
}