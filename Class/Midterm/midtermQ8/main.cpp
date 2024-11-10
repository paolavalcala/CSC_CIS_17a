/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on Oct 29, 2024, 12:44 PM
 * Purpose: Midterm Question 8
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <iomanip>
#include <cmath>
#include <string>
#include "Customer.h"
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 
void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
void problem4();
void problem5();
void problem6();
void problem7();

// Problem 1
void getData(Customer &c);// get input  
void printData(const Customer &c);//output contents of the structure

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    int inN;
    
    //Loop on each problem
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            default:   def(inN);
	}
    }while(inN<7);
    
    
    //Exit the program
    return 0;
}


void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1"<<endl;
    cout<<"Type 2 to execute Problem 2"<<endl;
    cout<<"Type 4 to execute Problem 4"<<endl;
    cout<<"Type 5 to execute Problem 5"<<endl;
    cout<<"Type 6 to execute Problem 6"<<endl;
    cout<<"Type 7 to execute Problem 7"<<endl;
    cout<<"Type anything else to exit."<<endl<<endl;
}

int  getN(){
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}


void problem1(){
        //Declare all variables
    Customer c;
    
    // Get customer data
    getData(c);
    
    // Display the output
    printData(c);

    delete[] c.checks;
    delete[] c.deposits;
}


void problem2(){
    
}


void problem4(){
    
}


void problem5(){
    
}


void problem6(){
    
    
}


void problem7(){
    
}


//problem 1
// Function to print customer data
void printData(const Customer &c){
    //calculate final balance 
    float newBalance = c.startBalance - c.ttlChecks + c.ttlDeposits;
    
    cout << "Account Number: " << c.accountNum << endl;
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.address << endl;
    cout << "Starting Balance: $" << c.startBalance << endl;
    cout << "New balance: $" << newBalance << endl;
    
    // Display checks
    //cout << "Checks Written: ";
   
    cout << endl;
    
    // Display deposits
    //cout << "Deposits Made: ";
    
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