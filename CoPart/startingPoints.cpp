#include<bits/stdc++.h>
using namespace std;
struct  Result{
    Result() : 
    output1(){};
    int output1[100];      
    
};  
Result startingPoint(int input1, int input2[]) {         
    int n = input1; 
    
    Result ans;                   
    
    for(int i=0;i<n;i++) ans.output1[i] = input2[i];                  

    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){     
            ans.output1[j-1] -= ans.output1[i-1];             
        }         
    }        

    return ans; 
} 
int main() {
    
    int n ; cin>>n;

    int arr[n];

    for (int i = 0; i < n; ++i) cin>>arr[i];            

    Result ans;          

    ans = startingPoint(n, arr);     

    for( int j=0; j<n; j++) cout<<ans.output1[j]<<" ";       

    cout<<endl; 
} 