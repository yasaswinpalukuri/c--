#include<bits/stdc++.h>
using namespace std;

int factors(int n){
    int c = 2;
    for(int i=2;i<=n/2;i++) if(n%i == 0) c++;
    return c;
}

int main(){
    cout<<"Enter numbers, \'-1\' to end\n";
    int k;
    vector<int> v;
    while(cin>>k){
        if(k == -1) break;
        v.push_back(k);
    }
    map<int,vector<int>> m;
    vector<int> fact(v.size());
    for(int i=0;i<v.size();i++){
        fact[i] = factors(v[i]);
        m[fact[i]].push_back(v[i]);
    }
    // for(auto it:m){
    //     cout<<"factor count:"<<it.first<<"\n";
    //     for(int i:it.second) cout<<i<<" ";
    //     cout<<"\n";
    // }
    sort(fact.begin(),fact.end(),greater<int>());
    for(int f:fact){
        for(int i:m[f]) cout<<i<<" ";
        m.erase(f);
    }
    return 0;
}