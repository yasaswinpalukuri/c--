#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n; cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(i == 0 || j == 0 || i == m-1 || j == n-1) a[i][j] *= 2;
            else a[i][j] /= 2;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}