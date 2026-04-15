#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// XOR Encryption Function
string xorEncryptDecrypt(const string& data, const string& key) {
    string result = data;
    for (size_t i = 0; i < data.size(); i++) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    return result;
}

// Read file
string readFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Error opening input file.");
    }
    return string((istreambuf_iterator<char>(file)),
                  istreambuf_iterator<char>());
}

// Write file
void writeFile(const string& filename, const string& data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Error opening output file.");
    }
    file.write(data.c_str(), data.size());
}

int main() {
    int choice;
    string inputFile, outputFile, key;

    cout << "1. Encrypt File\n2. Decrypt File\nChoice: ";
    cin >> choice;

    cout << "Enter input file: ";
    cin >> inputFile;

    cout << "Enter output file: ";
    cin >> outputFile;

    cout << "Enter key: ";
    cin >> key;

    try {
        string data = readFile(inputFile);
        string processed = xorEncryptDecrypt(data, key);
        writeFile(outputFile, processed);

        cout << "Operation completed successfully.\n";
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}