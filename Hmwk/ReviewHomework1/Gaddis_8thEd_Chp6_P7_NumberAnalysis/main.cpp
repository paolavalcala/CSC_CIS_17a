/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on August 27, 2024, 3:19 PM
 * Purpose: Number Analysis Program
 */

//System Libraries
#include <iostream> //Input-Output Library 
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 
float frnhtToClsus(int fhrnht);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    
    //Initialize all variables
    
    //Process or Map Solutions
    cout << "Fahrenheit to Celsius conversion table:\n";
    cout << "Fahrenheit\tCelsius\n";
    
    for (int i = 0; i <= 20; i++){
       int clsus = frnhtToClsus(i);
       cout << i << "\t\t" << clsus << endl;
    }
    //Display the output
    
    //Exit the program
    return 0;
}

float frnhtToClsus (int fhrnht){
    return 5.0 / 9 * (fhrnht - 32);

}