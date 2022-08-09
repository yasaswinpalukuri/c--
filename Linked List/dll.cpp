#include<bits/stdc++.h>
using namespace std;

class DLLNode{
    public:
    int d;
    DLLNode *next,*prev;
    DLLNode(){}
    DLLNode(int d){
        this->d = d;
        next = prev = nullptr;
    }
};

DLLNode *h = nullptr,*l = nullptr;

DLLNode* insertNode(int x){
    DLLNode *n = new DLLNode(x);
    if(h == nullptr){
        h = l = n;
        return n;
    }
    l->next = n;
    n->prev = l;
    l = n;
    return h;
}

DLLNode* sortedInsert(int x){
    DLLNode* nn = new DLLNode(x);
    DLLNode *p = nullptr, *c = h;
    while(c){
        if(c -> d > x) break;
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

void display(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    DLLNode* t=h;
    while(t != nullptr){
        cout<<t->d<<" ";
        t = t->next;
    }
    cout<<"\n";
}

void search(int x){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    DLLNode* t=h;
    int p = 0;
    while(t != nullptr){
        if(t->d == x) break;
        p++;
        t = t->next;
    }
    if(t == nullptr) cout<<"Element not found\n";
    else cout<<"Element found at position "<<p<<"\n";
}

DLLNode* deleteNode(int x){
    if(h == nullptr){
        cout<<"List is empty\n";
        return h;
    }
    DLLNode* t=h;
    while(t != nullptr){
        if(t->d == x) break;
        t = t->next;
    }
    if(t == nullptr){
        cout<<"Element not found\n";
        return h;
    }
    if(t == h && t == l){
        h = l = nullptr;
        return h;
    }
    if(t == h){
        h = h->next;
        h->prev = nullptr;
        return h;
    }
    if(t == l){
        l = l->prev;
        l->next = nullptr;
        return h;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    return h;
}

void reverse(){
    if(h == nullptr || h->next == nullptr){
        cout<<"List has only one element\n";
        return;
    }
    DLLNode* t = h;
    DLLNode* p = nullptr;
    while(t != nullptr){
        DLLNode* n = t->next;
        t->next = p;
        p = t;
        t = n;
    }
    h = p;
}

void middle(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    DLLNode* t = h;
    int p = 0;
    while(t != nullptr){
        p++;
        t = t->next;
    }
    t = h;
    for(int i = 0;i < p/2;i++) t = t->next;
    cout<<"Middle of List:"<<t->d<<"\n";
}

void middleSFP(){
    DLLNode* fast=h;
    DLLNode* slow=h;
    if(h != nullptr){
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<"Middle of List:"<<slow->d<<"\n";
    } else cout<<"Empty List\n";
}

void reverseUStack(){
    stack<int> st;
    DLLNode* temp = h;
    while (temp != NULL) {
        st.push(temp->d);
        temp = temp->next;
    }

    temp = h;
    while (temp != NULL) {
        temp->d = st.top();
        st.pop();
        temp = temp->next;
    }
}


int main(){
    do{
        cout<<"-----MENU-----\n";
        cout<<"1.Insert Node\n";
        cout<<"2.Sorted Insert\n";
        cout<<"3.Display\n";
        cout<<"4.Delete\n";
        cout<<"5.Search\n";
        cout<<"6.Middle\n";
        cout<<"7.Middle(Slow Fast Pointers)\n";
        cout<<"8.Reverse\n";
        cout<<"9.Reverse(Using Stack)\n";
        cout<<"10.Exit\n";
        cout<<"Enter your choice:";
        int ch; cin>>ch;
        switch(ch){
            case 1:{
                int x; 
                cout<<"Enter Node :"; cin>>x;
                h = insertNode(x);
                break;
            }

            case 2:{
                int x; 
                cout<<"Enter Node :"; cin>>x;
                h = sortedInsert(x);
                break;
            }
            
            case 3: display(); break;

            case 4:{
                int x; cout<<"Enter Node to Delete:"; cin>>x;
                h = deleteNode(x);
                break;
            }

            case 5:{
                int x; cout<<"Enter the element you wanna search:"; cin>>x;
                search(x);
                break;
            }

            case 6:{
                middle();
                break;
            }

            case 7:{
                middleSFP();
                break;
            }

            case 8:{
                reverse();
                break;
            }

            case 9:{
                reverseUStack();
                break;
            }
            
            case 10: cout<<"Thank you :)"; exit(0);
            default: cout<<"Invalid Input!!!!\n"; break;
        }
    }while(true);
    return 0;
}