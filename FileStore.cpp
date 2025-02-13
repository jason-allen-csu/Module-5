#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse file content
void reverseFileContent(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error opening input file!" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    reverse(content.begin(), content.end());

    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening output file!" << endl;
        return;
    }

    outFile << content;
    outFile.close();
}

int main() {
    string filename = "CSC450_CT5_mod5.txt";
    string reverseFilename = "CSC450-mod5-reverse.txt";
    string userInput;

    // Get user input
    cout << "Enter text to append to the file: ";
    getline(cin, userInput);

    // Append user input to file
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << userInput << endl;
    outFile.close();

    // Reverse file content
    reverseFileContent(filename, reverseFilename);

    cout << "Data appended and file content reversed successfully!" << endl;
    return 0;
}
