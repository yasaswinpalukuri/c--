#include<bits/stdc++.h>
using namespace std;

//Singly Circular Linked list
class CLLNode{
    public:
    int d;
    CLLNode *next;
    CLLNode(){
        next = nullptr;
    }
    CLLNode(int d){
        this -> d = d;
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
    CLLNode* nn = new CLLNode(x);
    l->next = nn;
    nn -> next = h;
    l = nn;
    return h;
}

CLLNode* insertAtFront(CLLNode* h,int x){
    if(h == nullptr){
        h = l = new CLLNode(x);
        h -> next = h;
    }
    CLLNode* nn = new CLLNode(x);
    nn -> next = h;
    l -> next = nn;
    h = nn;
    return h;
}

void findNode(CLLNode* h,int x){
    CLLNode* c = h;
    while(c){
        if(c->d == x){
            cout<<"Found"<<endl;
            return;
        }
        c = c -> next;
        if(c == h) break;
    }
    cout<<"Not Found"<<endl;
}

CLLNode* deleteNode(CLLNode* h,int x){
    CLLNode *p = nullptr, *c = h;
    while(c){
        if(c->d == x) break;
        p = c;
        c = c -> next;
        if(c == h) break;
    }
    if(c == nullptr){
        cout<<"Not Found"<<endl;
        return h;
    }
    if(p == nullptr){
        CLLNode* t = h;
        h = h -> next;
        l -> next = h;
        delete t;
        return h;
    }
    p -> next = c -> next;
    if(c == l){
        l = p;
    }
    delete c;
    return h;
}

void display(CLLNode* h){
    if(h == nullptr) return;
    CLLNode* t = h;
    cout<<t->d<<" ";
    t = t -> next;
    while(t != h){
        cout<<t->d<<" ";
        t = t -> next;
    }
    cout<<endl;
}

int main(){
    do{
        cout<<"Circular Linked List Operations\n";
        cout<<"1. Insert\n";
        cout<<"2. Insert at Front\n";
        cout<<"3. Find Node\n";
        cout<<"4. Delete Node\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n";
        int ch; cin>>ch;
        int x;
        switch(ch){
            case 1:
                cout<<"Enter the element to insert: ";
                cin>>x;
                h = insert(h,x);
                break;
            case 2:
                cout<<"Enter the element to insert: ";
                cin>>x;
                h = insertAtFront(h,x);
                break;
            case 3:
                cout<<"Enter the element to find: ";
                cin>>x;
                findNode(h,x);
                break;
            case 4:
                cout<<"Enter the element to delete: ";
                cin>>x;
                h = deleteNode(h,x);
                break;
            case 5:
                display(h);
                break;
            case 6:
                return 0;
            default:
                cout<<"Invalid Choice\n Please enter an valid choice\n";
        }
    }while(true);
}