/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on September 4, 2024, 3:55 PM
 * Purpose: Binary String Search Problem 
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <string>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 
int binarySearch(const string array[], int size, string value);
void bubbleSort(string array[], int size);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    const int NUM_NAMES = 20;
        string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth" }; // Insert your code to complete this program
    
    //Initialize all variables
    
    //Process or Map Solutions
    bubbleSort(names, NUM_NAMES);
    
    cout << "Sorted Names:\n";
    for (int i = 0; i < NUM_NAMES; i++){
        cout << names[i] << endl;
    }
    
    
    string searchName;
    cout << "\nEnter a name to search for (Last, First): ";
    getline(cin, searchName);

    // Call the binarySearch function
    int result = binarySearch(names, NUM_NAMES, searchName);

    // Display the result of the search
    if (result != -1) {
        cout << searchName << " found at index " << result << endl;
    } else {
        cout << searchName << " not found in the list." << endl;
    }
    
    //Display the output
    
    //Exit the program
    return 0;
}

int binarySearch(const string array[], int size, string value){
    int first = 0, last = size - 1, middle, position = -1;
    bool found =  false;
    
    while (!found && first <= last){
        middle = (first + last) / 2;
        
        if (array[middle] == value){
            found = true;
            position = middle;
        } else if (array[middle] > value){
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return position;
}


void bubbleSort(string array[], int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; i++){
            if (array[i] > array[i + 1]){
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}