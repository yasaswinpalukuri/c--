#include<bits/stdc++.h>
using namespace std;

void radixSort(int a[],int n){
    int max = a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max = a[i];
    int exp = 1;
    while(max/exp>0){
        int bucket[10] = {0};
        for(int i=0;i<n;i++) bucket[a[i]/exp%10]++;
        int cnt = 0;
        for(int i=0;i<10;i++) cnt += bucket[i];
        int b[cnt];
        for(int i=0;i<10;i++) b[i] = 0;
        for(int i=0;i<10;i++) b[bucket[i]-1] = i*exp;
        for(int i=0;i<n;i++) a[i] = b[a[i]/exp%10];
        exp *= 10;
    }
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    radixSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}