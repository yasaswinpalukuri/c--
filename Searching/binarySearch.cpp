#include<bits/stdc++.h>
using namespace std;

int key;

int binarySearch(int arr[], int l, int r){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) return binarySearch(arr, l, mid - 1);
        return binarySearch(arr, mid + 1, r);
    }
    return -1;
}

int main(){
    cout<<"Enter the number of elements: ";
    int n; cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<< "Enter the key: "; cin>>key;
    int index = binarySearch(a,0,n-1);
    if(index == -1) cout<<"Not Found";
    else cout<<"Found at "<<index;
    return 0;
}