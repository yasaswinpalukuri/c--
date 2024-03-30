#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main(){

    ifstream MyReadFile("dataAnnotationTextFile.txt");
    string read;
    int key; string value;
    while (getline(MyReadFile, read)){
        // if (sscanf(read.c_str(), "%d %s", &key, &value[0]) == 2) cout << "Key : " << key << ", Value: " << value << endl;
        // cout << read << "\n";

        stringstream iss(read);
        if (iss >> key >> value) {
            // Printing in the desired format
            cout << "Key : " << key << ", Value:" << value << endl;
        } else {
            cerr << "Error: Invalid line format" << endl;
        }
    }
    MyReadFile.close();

    int n = 24;
    cout<<n;
    return 0;
}