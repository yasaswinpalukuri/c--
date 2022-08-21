#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main(){
    //ifstream MyReadFile("yash.txt");
    FILE* fp = fopen("yash.txt","r");
    char str[10001];
    string read;
    // while (getline(MyReadFile, read)){
    //     cout <<"read=" << read << "\n";
    // }
    while(!feof(fp)){
        fscanf(fp,"%s",str);
        cout<<str;
        string s(str);
    }
    // MyReadFile.close();

    // ifstream myfile("yash.txt");
    // string mystring;
    // if ( myfile.is_open() ) {     
    //     while ( myfile.good() ) {
    //         myfile >> mystring;
    //         cout <<"mystring=" << mystring << "\n";
    //     }  
    //     myfile.close();     
    // }
    return 0;
}