#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform Run-Length Encoding
void RunLengthEnc(const string& str, ofstream& outputFile) {
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        int count = 1;
        // Count the number of consecutive occurrences of the current character
        while (i < n - 1 && str[i] == str[i + 1]) {
            ++count;
            ++i;
        }
        // Write the encoded character and its count to the output file
        outputFile << str[i] << count;
    }
}

void RunLengthDecr(const string& str, ofstream& outputFile) {
    int n = str.size();
    for (int i = 0; i < n; i += 2) {
        int repetition = (str[i + 1] - '0');
        // If there are more than one digit for repetition count, combine them
        if (i + 2 < n && isdigit(str[i + 2])) {
            repetition = repetition * 10 + (str[i + 2] - '0');
            ++i; // Skip the next digit
        }
        // Write the decoded character repetition times to the output file
        for (int j = 0; j < repetition; ++j) {
            outputFile << str[i];
        }
    }
}

int main() {
    // Open input and output files
    ifstream inputFile("inputfile.txt");
    ofstream outputFile("outputfile.txt");

    // Check if files are successfully opened
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

    // Close input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
