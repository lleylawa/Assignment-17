#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void RunLengthEnc(const string& str, ofstream& outputFile) {
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            ++count;
            ++i;
        }
        outputFile << str[i] << count;
    }
}

void RunLengthDecr(const string& str, ofstream& outputFile) {
    int n = str.size();
    for (int i = 0; i < n; i += 2) {
        int repetition = (str[i + 1] - '0');
        if (i + 2 < n && isdigit(str[i + 2])) {
            repetition = repetition * 10 + (str[i + 2] - '0');
            ++i; // Skip the next digit
        }
        for (int j = 0; j < repetition; ++j) {
            outputFile << str[i];
        }
    }
}

int main() {
    ifstream inputFile("inputfile.txt");
    ofstream outputFile("outputfile.txt");

    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }

    int choice;
    cout << "This is Run-Length Encoding" << endl;
    cout << "Enter 1 for Compression or 2 for Decompression: ";
    cin >> choice;

    string line;
    if (choice == 1) {
        while (getline(inputFile, line)) {
            RunLengthEnc(line, outputFile);
        }
    } else if (choice == 2) {
        while (getline(inputFile, line)) {
            RunLengthDecr(line, outputFile);
        }
    } else {
        cerr << "Invalid choice. Please enter 1 or 2." << endl;
        return 1;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
