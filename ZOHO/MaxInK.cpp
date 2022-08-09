#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k; cin>>k;
    if(k<=n){
        deque<int> qq;
        for(int i=0;i<k;i++){
            if(qq.size()==0) qq.push_front(i);
            else if(a[qq.front()] < a[i]) qq.push_front(i);
            else qq.push_back(i);
        }
        cout<<a[qq.front()]<<" ";
        for(int i=k;i<n;i++){
            if(i < i-k) qq.pop_front();
            else if(a[qq.front()] < a[i]) qq.push_front(i);
            else qq.push_back(i);
            cout<<a[qq.front()]<<" ";
        }
    } else cout<<"n < k";
    return 0;
}