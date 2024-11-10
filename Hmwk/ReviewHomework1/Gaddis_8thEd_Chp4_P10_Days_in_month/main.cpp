/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on August 28, 2024, 4:51 PM
 * Purpose: Days in a Month Problem
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
    int month, year;
    
    //Initialize all variables
    
    //Process or Map Solutions
    cout << "Enter a Month represented by an integer (1 - 12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    
    //if month input == 4, 5, 6, 9, 11 then output 30 days
    //if month input == 1, 3, 7, 8, 10, 12 then output 31 days
    
    //if month input == 2 then check to see if the year input is a leap year
    // bool leapyear = false
    //else if year % 100 = 0 then go to next line 
    //if year % 400 = 0 then year = leap year true  
    // else if year % 100 = 0 now check if year % 4 = 0 
    // then year == leap year true
    //if month input == 2 and leap year = true then output 29 days
    //if month input == 2 and leap year = false then output 28 days
    
    if (month==4 || month==5 || month==6 || month==9 || month==11) 
        cout << "has 30 days";
    else if (month==1 || month==3 || month==7 || month==8 || month==10 || month==12)
        cout << "has 31 days";
    else if (month==2) 
    {
        bool isLpYr = false;
        if (year % 100 == 0){
            if(year % 400 == 0) {
                isLpYr = true;
            }
        } else {
            if (year % 4 == 0) {
                isLpYr = true;
            }
        }
    
        if (isLpYr) {
            cout << "has 29 days";
        } else {
            cout << "has 28 days";
        }
    }
    //Display the output
    
    //Exit the program
    return 0;
}

