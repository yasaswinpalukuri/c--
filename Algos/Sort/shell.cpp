#include<bits/stdc++.h>
using namespace std;

void shellSort(int a[],int n){
    int gap = n/2;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int key = a[i];
            int j = i-gap;
            while(j>=0 && a[j]>key){
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
        }
    }
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    shellSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}