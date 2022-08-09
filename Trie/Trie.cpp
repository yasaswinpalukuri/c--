#include<bits/stdc++.h>
using namespace std;

class Trie
{
public:
    bool isEOW;
    Trie* next[26];
    Trie(){
        isEOW = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

void insertWord(Trie* r,string s){
    Trie* t = r;
    for(char c:s){
        int i = c -'a';
        if(t->next[i] == nullptr) t->next[i] = new Trie();
        t = t->next[i]; 
    }
    t->isEOW = true;
    
}

bool search(Trie* r,string s){
    if(r == nullptr) return false;
    Trie* t = r;
    for(char c:s){
        int i = c -'a';
        if(!t->next[i]) return false;
        t = t->next[i];
    }
    return t->isEOW;
}

bool isEmpty(Trie* r){
    for(int i=0;i<26;i++) if(r->next[i]) return false;
    return true;
}

Trie* deleteWord(Trie* r, string s, int d = 0){
    if (!r) return nullptr;
    if (d == s.size()) {
        if (r->isEOW) r->isEOW=false;
        if (isEmpty(r)) {
            delete(r);
            r = nullptr;
        }
        return r;
    }
    int i = s[d] - 'a';
    r->next[i] = deleteWord(r->next[i], s, d+1);
    if (isEmpty(r) && r->isEOW == false) {
        delete(r);
        r = nullptr;
    }
    return r;
}

void display(Trie* r, char str[], int l){
    if (r->isEOW){
        str[l] = '\0';
        cout << str << "\n";
    }
    for(int i = 0; i < 26; i++){
        if (r->next[i]){
            str[l] = i + 'a';
            display(r->next[i], str, l + 1);
        }
    }
}


int main(){
    Trie* r = new Trie();
    do{
        cout<<"----MENU----\n";
        cout<<"1. Insert\n";
        cout<<"2. Search\n";
        cout<<"3. Display\n";
        cout<<"4. Delete\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice:";
        int ch; cin>>ch;
        switch(ch){
            case 1:{
                cout<<"Enter word to insert:";
                string s; cin>>s;
                transform(s.begin(),s.end(),s.begin(),::tolower);
                cout << s << " is inserted\n";
                insertWord(r,s);
                break; 
            }
            case 2:{
                cout<<"Enter word to search:";
                string s; cin>>s;
                cout<<s<<" is "<<((search(r,s))?"":"not ")<<"there\n";
                break;
            }
            case 3: {
                cout<<"Trie elements:-\n";
                char str[100];
                display(r,str,0); 
                cout<<"\n\n";
                break;
            }
            case 4:{
                cout<<"Enter word to delete:";
                string s; cin>>s;
                deleteWord(r,s);
                break;
            }
            case 5: cout<<"Thank you :)";exit(0);
            default: cout<<"Invalid input!!!\n"; break;
        }
    }while(true);
}