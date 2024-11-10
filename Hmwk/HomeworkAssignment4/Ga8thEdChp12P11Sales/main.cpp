/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 22, 2024, 10:35 PM
 * Purpose: Corporate Sales Data Output Problem
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

struct Divisions 
{
    string divisionName;
    int quarter;
    int sales; 
};

//Function Prototypes 
// function to read data from a file
void readData(ifstream &file);
//function to display data 
void displayData(const Divisions &d);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    // open the input file holding the sales data
    ifstream inFile("data.txt");
    
    //error handle 
    if (!inFile){
        cout << "Error opening file" << endl;
        return 1;
    }
    
    //Declare all variables for each division
    //read data from file
    readData(inFile);
    
    //close file
    inFile.close();

    //Initialize all variables
    
    //Process or Map Solutions
    
    
    //Exit the program
    return 0;
}

void readData(ifstream &file) {
    Divisions d;  // Variable to hold data from the file
    
    // Read the data line by line from the file
    while (file >> d.divisionName >> d.quarter >> d.sales) {
        // Display the sales data for the division
        displayData(d);
    }
}

void displayData(const Divisions &d) {
    cout << d.divisionName << " Division, Quarter " << d.quarter 
         << ": $" << d.sales << endl;
}