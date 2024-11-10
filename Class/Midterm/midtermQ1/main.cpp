/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 23, 2024, 5:45 PM
 * Purpose: Midterm Question 1
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <string>
using namespace std;

#include "Structures.h"


//Function Prototypes 
void getData(Customer &c);// get input  
void printData(const Customer &c);//output contents of the structure


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    Customer c;
    
    // Get customer data
    getData(c);
    
    // Display the output
    printData(c);

    delete[] c.checks;
    delete[] c.deposits;
    //Exit the program
    return 0;
}

// Function to get input data for the customer
void getData(Customer &c){
    // Get basic customer info
    cout << "Enter Account number (5 digits): ";
    cin >> c.accountNum;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(c.name, SIZE);
    cout << "Enter Address: ";
    cin.getline(c.address, SIZE);
    cout << "Enter starting balance: ";
    cin >> c.startBalance;
    
    //get total number of checks written
    cout << "How many checks were written this month?: " << endl;
    cin >> c.ttlChecks;
    c.checks = new float[c.ttlChecks];
        
    //input each check amount 
    for (int i = 0; i < c.ttlChecks; i++){
        cout << "Enter check amount #" << (i + 1) << ": ";
        cin >> c.checks[i];
    }
            
    //get number of deposits
    cout << "How many deposits were made this month?: " << endl;
    cin >> c.ttlDeposits;
    c.deposits = new float[c.ttlDeposits];
    
    //input each deposit amount 
    for (int i = 0; i < c.ttlDeposits; i++){
        cout << "Enter deposit amount #" << (i + 1) << ": ";
        cin >> c.deposits[i];
    }
    

    
}


// Function to print customer data
void printData(const Customer &c){
    
    // Calculate total of checks and deposits
    float totalChecks = 0, totalDeposits = 0;
    for (int i = 0; i < c.ttlChecks; i++) {
        totalChecks += c.checks[i];
    }
    for (int i = 0; i < c.ttlDeposits; i++) {
        totalDeposits += c.deposits[i];
    }
    
    //calculate final balance 
    float newBalance = c.startBalance - c.ttlChecks + c.ttlDeposits;
    
    cout << "Account Number: " << c.accountNum << endl;
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.address << endl;
    cout << "Starting Balance: $" << c.startBalance << endl;
    cout << "New balance: $" << newBalance << endl;
    
     //Display checks
    cout << "Checks Written: " << totalChecks << endl;
   
    cout << endl;
    
     //Display deposits
    cout << "Deposits Made: " << totalDeposits << endl;
    
    cout << endl;
    
    cout << "Total amount of checks: " << c.ttlChecks << endl;
    cout << "Total amount of deposits: " << c.ttlDeposits << endl;
    
     // Check if the account is overdrawn
    if (newBalance < 0) {
        cout << "Your account is overdrawn. A $35 fee has been applied." << endl;
        newBalance -= 35;
        cout << "Balance with fee: $" << newBalance << endl;
    }
}