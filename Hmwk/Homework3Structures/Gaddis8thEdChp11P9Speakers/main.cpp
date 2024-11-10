/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 15, 2024, 10:35 PM
 * Purpose: Chp. 11 Problem 9 Speakers' Bureau 
 */

//System Libraries
#include <iostream> //Input-Output Library 
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

struct Speaker
{
    string Name;
    int TelNum;
    string Topic;
    float Fee;
};

//Function Prototypes 

void getData(Speaker[], int);
void printData(Speaker[], int);
void modifyData(Speaker[], int);
void displayMenu();

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    const int SPEAKERS = 3;
    Speaker data[SPEAKERS];
    int choice;
    
    
    //Initialize all variables
    
    //Process or Map Solutions
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                getData(data, SPEAKERS);  // Get input for all speakers
                break;
            case 2:
                modifyData(data, SPEAKERS);  // Modify a specific speaker's info
                break;
            case 3:
                printData(data, SPEAKERS);  // Display all speakers' information
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);
    
    //Display the output
    
    //Exit the program
    return 0;
}

void displayMenu() {
    cout << "\nSpeakers' Bureau Menu" << endl;
    cout << "1. Enter data for speakers" << endl;
    cout << "2. Modify data for a specific speaker" << endl;
    cout << "3. Display all speaker data" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void getData(Speaker data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for speaker: " << i + 1 << " ";
        getline(cin >> ws, data[i].Name);  // Use getline to handle spaces in names
        cout << "Enter the telephone number for the speakers: " << endl;
        cin >> data[i].TelNum;
        cout << "Enter the speaking topic: " << endl;
        getline(cin >> ws, data[i].Topic);
        cout << "Enter the paid Fee: " << endl;
        cin >> data[i].Fee;
        
    }
}


void printData(Speaker data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Speaker " << i + 1 << " name: " << data[i].Name << endl;
        cout << "Telephone Number: " << data[i].TelNum << endl;
        cout << "Speaking Topic: " << data[i].Topic << endl;
        cout << "Fee Paid: " << data[i].Fee << endl;
    }
}

// Function to modify a specific speaker's data
void modifyData(Speaker data[], int size) {
    int index;
    cout << "Enter the number of the speaker you want to modify (1-" << size << "): ";
    cin >> index;
    index--;  // Convert to 0-based index

    if (index >= 0 && index < size) {
        cout << "\nModifying data for speaker " << index + 1 << endl;

        // Modify Name
        cout << "Enter new Name (current: " << data[index].Name << "): ";
        getline(cin >> ws, data[index].Name);

        // Modify Telephone Number
        cout << "Enter new Telephone Number (current: " << data[index].TelNum << "): ";
        cin >> data[index].TelNum;

        // Modify Topic
        cout << "Enter new Speaking Topic (current: " << data[index].Topic << "): ";
        getline(cin >> ws, data[index].Topic);

        // Modify Fee
        do {
            cout << "Enter new Fee (current: $" << data[index].Fee << "): ";
            cin >> data[index].Fee;
            if (data[index].Fee < 0) {
                cout << "Fee cannot be negative. Please enter a valid fee." << endl;
            }
        } while (data[index].Fee < 0);  // Ensure fee is not negative
    } else {
        cout << "Invalid speaker number. Please try again." << endl;
    }
}