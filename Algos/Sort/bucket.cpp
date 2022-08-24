#include<bits/stdc++.h>
using namespace std;

void bucketSort(int a[],int n){
    int bucket[n];
    for(int i=0;i<n;i++) bucket[i] = 0;
    for(int i=0;i<n;i++) bucket[a[i]]++;
    int cnt = 0;
    for(int i=0;i<n;i++) cnt += bucket[i];
    int b[cnt];
    for(int i=0;i<n;i++) b[i] = 0;
    for(int i=0;i<n;i++) b[bucket[a[i]]-1] = a[i];
    for(int i=0;i<cnt;i++) a[i] = b[i];
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bucketSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}