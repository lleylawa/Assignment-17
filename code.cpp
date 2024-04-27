#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform Run-Length Encoding
void RunLengthEnc(const string& str, ofstream& outputFile) {
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;    
        }
        cout << str[i] << count; // Output to console
        outputFile << str[i] << count; // Output to file
    }
}

// Function to perform Run-Length Decrypting
void RunLengthDecr(const string& str, ofstream& outputFile) {
    int n = str.size();
    for(int i = 0; i < n; i += 2) {
        int count = (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
        if(count == 0) // Handling count 0
            count = 1;
        for(int j = 0; j < count; j++) { 
            cout << str[i];
            outputFile << str[i];
        }
        i++; // Move to the next character
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
    cout << "Enter 1 for Encrypting or 2 for Decrypting: ";
    cin >> choice;

    string line;
    if (choice == 1) {
        // Encrypting
        while (getline(inputFile, line)) {
            RunLengthEnc(line, outputFile);
        }
    } else if (choice == 2) {
        // Decrypting
        while (getline(inputFile, line)) {
            RunLengthDecr(line, outputFile);
        }
    } else {
        cerr << "Invalid choice." << endl;
        return 1;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

