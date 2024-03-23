#include<bits/stdc++.h>
using namespace std;


//Double Circular Linked List
public class CDLLNode{
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

CDLLNode* insertNodeWithLast(CDLLNode* h, CDLLNode* l, int x){
    if(h == nullptr){
        h = new CDLLNode(x);
        h->prev = h -> next = h;
        l = h;
    }
    CDLLNode* nn = new CDLLNode(x);
    l -> next = nn;
    nn -> prev = l;
    nn -> next = h;
    h -> prev = nn;
    l = nn;
    return h;
}

CDLLNode* sortedInsert(CDLLNode* h,int x){
    CDLLNode* nn = new CDLLNode(x);
    CDLLNode *p = nullptr, *c = h;
    while(c){
        if(c.getD() > c) break;
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

void display(CDLLNode* h){
    if(h == nullptr) return;
    CDLLNode* t = h;
    while(t){
        cout<<t->d<<" ";
        if(t -> next == h) break;
        t = t -> next;
    }
    cout<<'\n';
}

CDLLNode* deleteNode(CDLLNode* h, int x){
    if(h == nullptr) return nullptr;
    if(h -> d == x){
        CDLLNode* t = h;
        h = h -> next;
        h -> prev = t -> prev;
        t -> prev -> next = h;
        delete t;
        return h;
    }
    CDLLNode *p = nullptr, *c = h;
    while(c){
        if(c -> d == x) break;
        p = c;
        c = c -> next;
    }
    if(c == nullptr){
        cout<<"Element not found\n";
        return h;
    }
    p -> next = c -> next;
    c -> next -> prev = p;
    delete c;
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
    CDLLNode *h=nullptr;
    CDLLNode *l=nullptr;
    do{
        cout<<"Welcome to Circular Double Linked List\n";
        cout<<"1. Insert Node\n";
        cout<<"2. Insert Node with Last\n";
        cout<<"3. Sorted Insert\n";
        cout<<"4. Display\n";
        cout<<"5. Delete\n";
        cout<<"6. Size\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        int ch; cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the element to insert: ";
                int x; cin>>x;
                h = insertNode(h,x);
                break;
            case 2:
                cout<<"Enter the element to insert: ";
                cin>>x;
                h = insertNodeWithLast(h,l,x);
                break;
            case 3:
                cout<<"Enter the element to insert: ";
                int x; cin>>x;
                h = sortedInsert(h,x);
                break;
            case 4:
                display(h);
                break;
            case 5:
                cout<<"Enter the element to delete: ";
                int x; cin>>x;
                h = deleteNode(h,x);
                break;
            case 6:
                cout<<"Size of the list is: "<<size(h)<<'\n';
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice\nPlease enter a valid choice\n";
        }
    }while(true);
    return 0;
}