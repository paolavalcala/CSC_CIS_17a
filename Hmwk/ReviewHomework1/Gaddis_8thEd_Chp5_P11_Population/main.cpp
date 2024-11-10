/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on August 31, 2024, 2:29 PM
 * Purpose: Population Problem
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
    int strtPpln, days; //starting population and days 
    float dlyIncrease, size; //daily population increase and size of poplation
    
    //Initialize all variables
    
    //Process or Map Solutions  
    
    do {
        cout << "Input a number greater than 2: ";
        cin >> strtPpln; 
        if (strtPpln < 2){
            cout << "Number should be greater than 2!" << endl; 
        }
    }while (strtPpln < 2);

    do {
        cout << "Input a percentage greater than 0: ";
        cin >> dlyIncrease;  
        if (dlyIncrease < 0){
            cout << "Percentage should be greater than 0!" << endl;
        }
    }while (dlyIncrease < 0);
    
    do{
        cout << "Input a number greater than 1: ";
        cin >> days;
        if (days < 1){
            cout << "Number should be greater than 1!" << endl;
        }
    } while (days <1);
    
    size = strtPpln;
    
    //Display the output
    for(int i = 1; i <= days; i++){
        size += size * (dlyIncrease / 100);
    }
    
    cout << fixed << setprecision(2) <<"The population grew to " << size << " in " << days << " days." <<endl;
    
    //Exit the program
    return 0;
}


