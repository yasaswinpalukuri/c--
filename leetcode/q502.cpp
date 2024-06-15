#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of projects: ";
    int n; cin>>n;
    vector<int> profits(n), capital(n);
    cout<<"Enter the profits: ";
    for(int i=0; i<n; i++) cin>>profits[i];
    cout<<"Enter the capital: ";
    for(int i=0; i<n; i++) cin>>capital[i];
    cout<<"Enter the initial capital: ";
    int w; cin>>w;
    cout<<"Enter the number of projects that can be done before IPO: ";
    int k; cin>>k;
    priority_queue<int> pq;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) v.push_back({capital[i], profits[i]});
    sort(v.begin(), v.end());
    int i=0;
    for(int j=0; j<k; j++){
        while(i<n && v[i].first<=w){
            pq.push(v[i].second);
            i++;
        }
        if(pq.empty()) break;
        w+=pq.top();
        pq.pop();
    }
    cout<<w<<endl;
    cout<<"Enter anything to exit";
    char c; cin>>c;
    return 0;
}