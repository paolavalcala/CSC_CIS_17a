
/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Validate and Reverse
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <limits>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char digits[],unsigned short &unShort);//Output true,unsigned or false
bool  reverse(unsigned short unShort,signed short &snShort);//Output true,short or false
short subtrct(signed short snShort,int lrgst);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort, 999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

// Write a function that inputs numerical digits in the range of an unsigned short.
bool inRange(const char digits[], unsigned short &unShort) {
    int len = strlen(digits);
    unShort = 0;
    
    // Loop through digits to validate 
    for (int i = 0; i < len; ++i) {
        if (digits[i] >= '0' && digits[i] <= '9') {
            unShort = unShort * 10 + (digits[i] - '0');
        } else {
            return false; // Not a numerical digit
        }
    }
    
    // if the number is in range of an unsigned short
    if (unShort > numeric_limits<unsigned short>::max()) {
        return false;
    }
    
    return true;
}


bool reverse(unsigned short unShort, signed short &snShort) {
    signed short rvrsd = 0;
    unsigned short temp = unShort; // Temporary variable to hold unShort
    
    // Extract and reverse the digits
    while (temp > 0) {
        unsigned short digit = temp % 10; // Extract the least significant digit
        rvrsd = rvrsd * 10 + digit; // Append the digit to the reversed number
        temp /= 10; // Move to the next digit
    }
    
    // Convert the reversed number back to a signed short
    snShort = rvrsd;
    
    // Check if the reversed number is in the range of a signed short
    if (snShort > numeric_limits<signed short>::max() || snShort < numeric_limits<signed short>::min()) {
        return false; // Out of range
    }
    
    return true;
}


short subtrct(signed short snShort, int lrgst){
    // Only subtract the largest 3 digit number from the reverse if the result is not negative.

    if (snShort >= 0){
        return snShort;
    }else{
        return snShort - lrgst;
    }
 
    
}