/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 22, 2024, 5:31 PM
 * Purpose: Array/File Functions
 */

//System Libraries
#include <iostream>   //Input-Output Library 
#include <fstream>    //File Stream Library
using namespace std;

//Function Prototypes
void arrayToFile(const string &filename, int *arr, int size);
void fileToArray(const string &filename, int *arr, int size);

//Program Execution Begins Here
int main() {
    //Declare variables
    const int SIZE = 5;
    int array[SIZE] = {10, 20, 30, 40, 50};  // Example data
    int readArray[SIZE];  // Array to hold the data read from the file
    string filename;      // One file name for both writing and reading

    // Prompt user for file name
    cout << "Enter a file name:" << endl;
    cin >> filename;

    // Write the array to the specified file
    arrayToFile(filename, array, SIZE);

    // Read the array from the same file
    fileToArray(filename, readArray, SIZE);

    // Display the contents of the array read from the file
    cout << "Array contents read from the file: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << readArray[i] << " ";
    }
    cout << endl;

    // Exit the program
    return 0;
}

//Function to write the array to a binary file
void arrayToFile(const string &filename, int *arr, int size) {
    ofstream outFile(filename, ios::binary);  // Open the file in binary mode
    if (outFile) {
        // Write the array to the file
        outFile.write(reinterpret_cast<char*>(arr), size * sizeof(int));
        outFile.close();  // Close the file
        cout << "Array written to " << filename << endl;
    } else {
        cout << "Error opening file " << filename << endl;
    }
}

//Function to read the array from a binary file
void fileToArray(const string &filename, int *arr, int size) {
    ifstream inFile(filename, ios::binary);  // Open the file in binary mode
    if (inFile) {
        // Read the contents into the array
        inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));
        inFile.close();  // Close the file
        cout << "Array read from " << filename << endl;
    } else {
        cout << "Error opening file " << filename << endl;
    }
}
