#include<bits/stdc++.h>
using namespace std;

//Singly Circular Linked list
class CLLNode{
    int d;
    CLLNode *next;
    CLLNode(int d){
        this.d = d;
        next = nullptr;
    }
};

CLLNode* h = nullptr;
CLLNode* l = nullptr;

CLLNode* insert(CLLNode* h,int x){
    if(h == nullptr){
        h = l = new CLLNode(x);
        h -> next = h;
    }
    CLLNode nn = new CLLNode(x);
    l->next = nn;
    nn -> next = h;
    l = nn;
    return h;
}


int main(){
    do{
        
    }while(true);
}