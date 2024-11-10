/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 23, 2024, 5:45 PM
 * Purpose: Midterm Question 6
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
    
    int width = 30;
    //positive version 
    
    //49.1875
    cout << left << setw(width) << "Number: 49.1875" << endl;
    cout << setw(width) << "Converted to Binary: 110001.0011" << endl;
    cout << setw(width) << "Converted to Octal: 61.14" << endl;
    cout << setw(width) << "Converted to hex: 31.3" << endl;
    cout << setw(width) << "Float representation: 62600006" << endl;
    cout << endl;
    
    //3.07421875
    cout << setw(width) << "Number: 3.07421875" << endl;
    cout << setw(width) << "Converted to Binary: 11.00010011" << endl;
    cout << setw(width) << "Converted to Octal: 3.046" << endl;
    cout << setw(width) << "Converted to hex: 3.13" << endl;
    cout << setw(width) << "Float representation: 62600002" << endl;
    cout << endl;
    
    //0.2
    cout << setw(width) << "Number: 0.2" << endl;
    cout << setw(width) << "Converted to Binary: 0.0011" << endl;
    cout << setw(width) << "Converted to Octal: 0.14" << endl;
    cout << setw(width) << "Converted to hex: 0.3" << endl;
    cout << setw(width) << "Float representation: 666666FE" << endl;
    cout << endl;
    
    //negative version 
    
    //49.1875
    cout << setw(width) << "Number: 49.1875" << endl;
    cout << setw(width) << "Negative float representation: 9DA0006" << endl;
    cout <<endl;
    //3.07421875
    cout << setw(width) << "Number: 3.07421875" << endl;
    cout << setw(width) << "Negative float representation: 9DA0002" << endl;
    cout <<endl;
    //0.2
    cout << setw(width) << "Number: 0.2" << endl;
    cout << setw(width) << "Negative float representation: 99999AFE" << endl;
    cout <<endl;
    
    //Convert the float representations to the decimal number
    //69999902 
    cout << setw(width) << "Float representation: 69999902" << endl;
    cout << setw(width) << "Converted to decimal number: 0.20624998" << endl;
    cout <<endl;
    //69999903
    cout << "Float representation: 69999903" << endl;
    cout << "Converted to decimal number: 0.10312499" << endl;
    cout <<endl;
    //966667FF
    cout << setw(width) << "Float representation: 966667FF" << endl;
    cout << setw(width) << "Converted to decimal number: 1.64999986" << endl;
    cout <<endl;
    //Exit the program
    return 0;
}
