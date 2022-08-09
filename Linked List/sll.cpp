#include<bits/stdc++.h>
using namespace std;

class SLLNode{
    public:
    int d;
    SLLNode *next;
    SLLNode(){}
    SLLNode(int d){
        this->d = d;
        next = nullptr;
    }
};

SLLNode *h = nullptr;
SLLNode *l = nullptr;
SLLNode *rl = nullptr;

SLLNode* insertNode(int x){
    if(h == nullptr){
        h = l = new SLLNode(x);
        return l;
    }
    SLLNode *n = new SLLNode(x);
    l->next = n;
    l = n;
    return h;
}

SLLNode* sortedInsert(int x){
    if(h == nullptr){
        h = l = new SLLNode(x);
        return l;
    }
    SLLNode *n = new SLLNode(x);
    if(x < h->d){
        n->next = h;
        h = n;
        return h;
    }
    SLLNode *t = h;
    while(t->next && t->next->d < x){
        t = t->next;
    }
    n->next = t->next;
    t->next = n;
    return h;
}

void display(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    SLLNode* t=h;
    while(t != nullptr){
        cout<<t->d<<" ";
        t = t->next;
    }
    cout<<"\n";
}

SLLNode* deleteNode(int x){
    if(h == nullptr){
        cout<<"List is empty\n";
        return nullptr;
    }
    if(h->d == x) return h->next;
    SLLNode *prev = h,*curr = h;
    while(curr){
        if(curr->d == x) break;
        prev = curr;
        curr = curr->next;
    }
    prev -> next = curr -> next;
    return h;
}

void search(int x){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    SLLNode* t=h;
    int p = 0;
    while(t->d != x){
        p++;
        t= t->next;
    }
    if(t == nullptr) cout<<"Not Present in the list";
    else cout<<"Present at "<<p<<" in the list";
}

void middle(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    int c=0;
    SLLNode* t=h;
    while(t!=nullptr){
        c++;
        t=t->next;
    }
    int i=0;
    t = h;
    while(i!=c/2){
        t = t->next;
        i++;
    }
    cout<<"Middle of List:"<<t->d<<"\n";
}

void middleSFP(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    SLLNode* fast=h;
    SLLNode* slow=h;
    if(h != nullptr){
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<"Middle of List:"<<slow->d<<"\n";
    } else cout<<"Empty List\n";
}

void reverse(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    stack<SLLNode*> s;
    SLLNode *temp = h;
    while (temp->next != NULL) {
        // Push all the nodes in to stack
        s.push(temp);
        temp = temp->next;
    }
    rl = temp; h =temp;
    while (! s.empty()) {
        // Store the top value of stack in list
        temp->next =  s.top();
        // Pop the value from stack
        s.pop();
        // update the next pointer in the in the list
        temp = temp->next;
    }
    temp->next = NULL;
}

void reverseU3P(){
    if(h == nullptr){
        cout<<"List is empty\n";
        return;
    }
    SLLNode* prev = NULL;
    SLLNode* current = h;
    SLLNode* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
    
        // Reverse current node's pointer
        current->next = prev;
    
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    rl = prev;
    h = prev;
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
        cout<<"9.Reverse(Using 3 pointers)\n";
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
                reverseU3P();
                break;
            }
            
            case 10: cout<<"Thank you :)"; exit(0);
            default: cout<<"Invalid Input!!!!\n"; break;
        }
    }while(true);
    return 0;
}