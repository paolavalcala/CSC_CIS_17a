/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 16, 2024
 * Purpose: Sentence Filter
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <fstream>
#include <cctype>
#include <string>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
   //declare variables
    bool upCase = true;
    string iFileName;
    string oFileName;
    char ch;
    ifstream inFile;
    ofstream outFile;
    
    //open file for output
    cout << "Enter an output file name:" << endl;
    cin >> oFileName;
   
    //open file for input
    cout << "Enter an input file name:" << endl;
    cin >> iFileName;
    
    inFile.open(iFileName);
    
    outFile.open(oFileName);
    
    
    //if input file opened successfully
    if(inFile){
        
        inFile.get(ch);
        
        while(inFile){
            if (upCase && isalpha(ch)){
                outFile.put(toupper(ch));
                upCase = false;
            } else {
                outFile.put(tolower(ch));
            }
            if (ch == '.'){
                upCase = true;
            }
            inFile.get(ch);
        }
        
        inFile.close();
        outFile.close();
        cout << "File conversions done. \n";
    }else{
        cout << "Cannot open" << iFileName << endl;
    }
    
    
    
    //Display the output
    
    //Exit the program
    return 0;
}



/* To read and write from a file
 * 1. Create a text editor file 
 * 2. add text file to project saved on your computer
 * 3. ifstream to read 
 */