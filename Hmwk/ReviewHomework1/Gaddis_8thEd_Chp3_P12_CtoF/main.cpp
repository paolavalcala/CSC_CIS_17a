/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on August 28, 2024, 2:51 PM
 * Purpose: Celsius to Fahrenheit Problem
 */

//System Libraries
#include <iostream> //Input-Output Library 
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    int C;//number of Celsius degrees
    int F;//number of Fahrenheit degrees 
    
    //Initialize all variables
    
    //Process or Map Solutions
    cout << "Enter a number to represent degrees in Celsius: " << endl;
    cin >> C;
    
    F = C * 9/5 + 32;
    //Display the output
    cout << C << " degrees Celsius is " << F << " degrees Fahrenheit." << endl;
    
    //Exit the program
    return 0;
}
