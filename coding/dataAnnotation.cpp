#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main(){

    ifstream MyReadFile("dataAnnotationTextFile.txt");
    string read;
    int key; string value;
    while (getline(MyReadFile, read)){
        stringstream iss(read);
        if (iss >> key >> value) cout << "Key : " << key << ", Value:" << value << endl;
    }
    MyReadFile.close();

    int n = 24;
    cout<<n;
    return 0;
}