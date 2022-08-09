#include<bits/stdc++.h>
using namespace std;

void mergeSort(int array[], int begin, int end){
    if(begin < end){
        int mid = (begin + end) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}

void merge(int array[], int left, int mid,int right){
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    while(i <= mid && j <= right){
        if(array[i] < array[j]){
            temp[k] = array[i];
            i++;
        }
        else{
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = array[i];
        i++;
        k++;
    }
    while(j <= right){
        temp[k] = array[j];
        j++;
        k++;
    }
    for(int i = 0; i < right - left + 1; i++){
        array[left + i] = temp[i];
    }
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    mergeSort(a, 0, n - 1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}