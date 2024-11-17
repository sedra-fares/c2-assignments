#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main() {
    const int maxW = 1000;
    const int maxLen = 100;
    char wordList[maxW][maxLen];
    int numWords = 0;

    ofstream fileOut("somethingg.txt");
    if (fileOut) {
        fileOut << "This is the first line of the text file.\n"
            << "Here is the second line.\n"
            << "This file contains multiple lies of text.\n"
            << "The getline function will read each lie separately.\n"
            << "Finally, this is the last line.";
        fileOut.close();
    }
    else {
        cout << "File write error!" << endl;
        return 1;
    }

    ifstream fileIn("somethingg.txt");
    if (!fileIn) {
        cout << "File read error!" << endl;
        return 1;
    }

    while (fileIn >> wordList[numWords] && numWords < maxW) {
        numWords++;
    }
    fileIn.close();

    char* longest = wordList[0];
    int tionCount = 0;
    int ieCount = 0;
    int isCount = 0;

    for (int i = 0; i < numWords; i++) {
        int len = strlen(wordList[i]);

        if (len > strlen(longest)) {
            longest = wordList[i];
        }
        if (len >= 4 && strcmp(&wordList[i][len - 4], "tion") == 0) {
            tionCount++;
        }
        if (strstr(wordList[i], "ie") != nullptr) {
            ieCount++;
        }
        if (strcmp(wordList[i], "is") == 0) {
            isCount++;
        }
        _strupr_s(wordList[i]);
    }

    ofstream resultOut("resultss.txt");
    if (resultOut) {
        resultOut << "Longest word: " << longest << endl;
        resultOut << "Words ending in 'tion': " << tionCount << endl;
        resultOut << "Words with 'ie': " << ieCount << endl;
        resultOut << "'is' count: " << isCount << endl;
        resultOut << "\nUppercase words:\n";
        for (int i = 0; i < numWords; i++) {
            resultOut << wordList[i] << " ";
        }
        resultOut.close();
        cout << "Results saved to results.txt" << endl;
    }
    else {
        cout << "File write error!" << endl;
    }

    return 0;
}
