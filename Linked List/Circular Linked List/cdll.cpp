#include<bits/stdc++.h>
using namespace std;


//Double Circular Linked List
class CDLLNode{
    int d;
    CDLLNode *next,*prev;
    CDLLNode(){}
    CDLLNode(int d){
        this->d = d;
        next = prev = nullptr;
    }
}

CDLLNode* insertNode(CDLLNode* h, int x){
    if(h == nullptr){
        h = new CDLLNode(x);
        h->prev = h -> next = h;
    }
    CDLLNode* nn = new CDLLNode(x);
    CDLLNode* p = h -> prev;
    p -> next = nn;
    nn -> prev = p;
    nn -> next = h;
    h -> prev = nn;
    return h;
}
CDLLNode* sortedInsert(CDLLNode* h,int x){
    CDLLNode* nn = new CDLLNode(x);
    CDLLNode *p = nullptr, *c = h;
    while(c){
        if(c -> d > c) break;
        p = c;
        c = c -> next;
    }
    if(p == nullptr){
        nn -> next = h;
        h -> prev = nn;
        return nn;
    }
    if(c == nullptr){
        p -> next = nn;
        nn -> prev = p;
        return h;
    }
    p -> next = nn;
    nn -> next = c;
    c -> prev = nn;
    nn->prev = p;
    return h;
}


int size(CDLLNode* h){
    if(h == NULL) return 0;
    int size = 1;
    CDLLNode* t = h;
    while(t){
        if(t -> next == h) break;
        size++;
        t = t -> next;
    }
    return size;
}


int main(){
    
    return 0;
}