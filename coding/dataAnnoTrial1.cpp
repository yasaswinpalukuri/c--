#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct WordInfo {
    string word;
    int number;
};

bool compareWordInfo(const WordInfo &a, const WordInfo &b) {
    return a.number < b.number;
}

int main() {
    ifstream inputFile("coding_qual_input_new.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<WordInfo> words;
    string word;
    int number;
    while (inputFile >> number >> word) {
        words.push_back({word, number});
    }

    sort(words.begin(), words.end(), compareWordInfo);

    int numRows = 0;
    int count = 0;
    while (count < words.size()) {
        numRows++;
        count += numRows;
    }

    vector<string> messageWords;
    int currentIndex = 0;
    for (int row = 1; row <= numRows; ++row) {
        currentIndex += row - 1;
        messageWords.push_back(words[currentIndex].word);
    }

    cout << "Decoded message:" << endl;
    for (const string &word : messageWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
