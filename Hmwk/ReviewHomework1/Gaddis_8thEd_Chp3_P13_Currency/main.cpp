/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on August 28, 2024, 3:41 PM
 * Purpose: Currency Problem
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    float dllrToYn;//number to represent dollar to yen 
    float dllrToEro;//number to represent dollar to euro 
    float dllr = 1, euro = 0.74, yen = 98.93;
    
    //Initialize all variables
    
    //Process or Map Solutions
    cout << " Enter an amount to represent U.S. dollars: " <<endl;
    cin >> dllr; 
    
    dllrToYn = yen * dllr;
    dllrToEro = euro * dllr;
    
    
    //Display the output
    cout << setprecision(5) << dllr << " U.S. dollars are equal to  " << dllrToYn << " Japanese Yen." << endl;
    cout << setprecision(5) << dllr << " U.S. dollars are equal to " << dllrToEro << " Euros." << endl;
    
    //Exit the program
    return 0;
}