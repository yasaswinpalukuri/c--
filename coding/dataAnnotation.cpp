#include<bits/stdc++.h>
#include<fstream>
using namespace std;
// Hard coded by Yasaswin Palukuri

int main(){

    ifstream MyReadFile("coding_qual_input_new.txt");
    string read;
    int key; string value;
    map<int, string> m;
    int maxValue = 0;
    while (getline(MyReadFile, read)){
        stringstream iss(read);
        if (iss >> key >> value){
            // cout << "Key : " << key << ", Value:" << value << endl;
            m[key] = value;
        }
        maxValue = max(maxValue, key);
    }
    MyReadFile.close();

    // cout<<"Final Value in the pyramid is:"<<maxValue<<"\n";

    /*
        => 1. print right view of the pyramid
        => 2. find pattern of the right most element
        => 3. Print in proper format

        16

                1
            2       3
        4       5       6
    7       8       9       10
    11      12      13      14      15
    16    

    i = 0 -> pow(2,0) + i = 1 
    i = 1 -> pow(2,1) + i = 3 -> 1+2
    i = 2 -> pow(2,2) + i = 6 -> 3+3
    i = 3 -> pow(2,3) + i = 11 => wrong approach => 10 -> 6+4
    i = 4 -> pow(2,4) + i = 16 => wrong approach => 15 -> 10+5

    So, the appoach is add the number to next consecutive number
    
    j=1;
    i=1;
    while(i <= maxValue){
        ss += m[i] + " ";
        i += ++j;
    }

    */
    
    string ss = "";
    int i=1;
    int j=1;
    while(i <= maxValue){
        // cout<<"i="<<i<<"\n";
        ss += m[i] + " ";
        i += ++j;
    }

    cout<<ss;
    // cout<<"j="<<j<<"\n";
    return 0;
}