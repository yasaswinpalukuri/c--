#include<bits/stdc++.h>
using namespace std;

void combSort(int a[],int n){
    int gap = n;
    bool swapped = true;
    while(gap>1 || swapped){
        if(gap>1){
            gap = (int)(gap/1.3);
        }
        swapped = false;
        for(int i=0;i<n-gap;i++){
            if(a[i]>a[i+gap]){
                int temp = a[i];
                a[i] = a[i+gap];
                a[i+gap] = temp;
                swapped = true;
            }
        }
    }
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    combSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}