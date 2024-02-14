#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    ifstream fin("D:\\labs\\oap1.2\\lab3Files\\task1\\FILE1.txt");
    ofstream fo("D:\\labs\\oap1.2\\lab3Files\\task1\\FILE2.txt");

    if (!fin.is_open()) {
        cout << "(((" << endl;
        return 1;
    }

    while (getline(fin, line)) {
        stringstream oneWord(line);

        string word;
        vector<string> words; 

        bool foundRep = false;

        while (oneWord >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[i] == words[j]) {
                    foundRep = true; 
                    break;
                }
            }
            if (foundRep) {
                break;
            }
        }

        if (foundRep) {
            fo << line;
            fo << endl;
        }
        
    }

    fin.close();
    fo.close();

    ifstream FILE2read("D:\\labs\\oap1.2\\lab3Files\\task1\\FILE2.txt");
    string buff;
    if (!FILE2read.is_open()) {
        cout << "(((" << endl;
        return 1;
    }
    else {
        int i = 0;
        int maxA = 0;
        int counterA = 0;
        int countWordA = 0;
        int countNumberWordA = 0;
        while(FILE2read >> buff)
        {
            countWordA++;
            i = 0;
            counterA = 0;
            while (buff[i] != '\0') {
                if (buff[i] == 'a')
                    counterA++;
                i++;
            }
            if (counterA > maxA) {
                maxA = counterA;
                countNumberWordA = countWordA;
            }

        }
        cout << countNumberWordA;
    }


    FILE2read.close();
    return 0;
}
