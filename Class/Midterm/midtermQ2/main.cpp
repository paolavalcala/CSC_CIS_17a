/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on October 24, 2024, 11:22 PM
 * Purpose: Midterm Question 3
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <iomanip>
#include <string>
#include "structure.h"

using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

// function to loop and input the employee information
void getData(Employee *e, int numEmploy);  

//calculate gross pay for a single employee
float calculatePay(const Employee &e);

// converts numerical value to english
string cnvrtToEng(int num);

//function to populate Paycheck structure
void fillPaycheck(const Employee &e, Paycheck &p, const string &company, const string &address);

// function to output the information in paycheck format
void printData(const Paycheck *p, int numEmploy);

 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    int numEmploy;
    string nameCmpny;
    string cmpnyAddress;
    
    // Set company and address information
    cout << "Enter the name of the company: " << endl;
    getline(cin, nameCmpny);
    
    cout << "Enter the company address: " << endl;
    getline(cin, cmpnyAddress);
    
    //ask for the number of employees
    cout << "Enter the number of employees: " << endl;
    cin >> numEmploy;
    
    
    //array of employee structures
    Employee *e = new Employee[numEmploy];
    //array of paycheck structures
    Paycheck *p = new Paycheck[numEmploy];
    

    
    //Get data for each employee
    getData(e, numEmploy);
    
    //populate paycheck information based on the employee data
    for (int i = 0; i < numEmploy; i++){
        fillPaycheck(e[i], p[i], nameCmpny, cmpnyAddress);
    }
    

    printData(p, numEmploy);
    
    // Clean up
    delete[] e;
    delete[] p;
    
    //Exit the program
    return 0;
}

void getData(Employee *e, int numEmploy){   
    for (int i = 0; i < numEmploy; i++){
        cin.ignore();
        cout << "\nEmployee " << (i + 1) << " Information:\n";
        
        cout << "Enter employee name: ";
        cin.getline(e[i].name, 100);
        
        cout << "Enter the amount of hours worked: ";
        cin >> e[i].hrsWorkd;
        while (e[i].hrsWorkd < 0){
            cout << "Invalid entry! Hours worked can not be negative. Please re-enter: ";
            cin >> e[i].hrsWorkd;
        }
        
        cout << "Enter hourly pay rate: ";
        cin >> e[i].ratePay;
        while(e[i].ratePay < 0){
            cout << "Invalid entry! Pay rate cannot be negative. Re-enter: ";
            cin >> e[i].ratePay;
        }   
    }
}


float calculatePay(const Employee &e){
    float grossPay = 0.0;
    
    if (e.hrsWorkd <= 20){
        grossPay = e.hrsWorkd * e.ratePay;
    }else if (e.hrsWorkd <= 40){
            grossPay = (20 * e.ratePay) + ((e.hrsWorkd - 20) * e.ratePay * 2);
        
    } else {
        grossPay = (20 * e.ratePay) + (20 * e.ratePay * 2) + ((e.hrsWorkd - 40) * e.ratePay * 3);
    }
    
    return grossPay;
}

string cnvrtToEng(int num){
    //digits 1- 9 represents i + 1
    const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    //digits 11 - 19 represents i + 10
    const string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    //digits 10 - 90 represents (i+1) * 10
    const string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result; //result string
    
    //Calculate the 1000's, 100's, 10's and 1's
    
    if (num >= 1000) { //if num falls in 1000s
        result += ones[num / 1000] + " Thousand "; //find first digit and look up in ones array and append to result string
        num %= 1000; //remove 1000 place from num to handle remaining digits
    }

    if (num >= 100) { //if num falls in 100s
        result += ones[num / 100] + " Hundred "; //find first digit and look up in one array and append to result string
        num %= 100; //remove 100 place from num to handle remaining digits
    }

    if (num >= 20) { //if num falls in tens is true
        result += tens[num / 10] + " "; //find digit and look up english name in tens array 
        num %= 10; //remove 10 place from num 
    } else if (num >= 11) {  //if false num falls in teens
        result += teens[num - 10] + " "; //find digit and look up in teens array
        num = 0;  // Skip the ones place
    }

    if (num > 0) {
        result += ones[num] + " ";
    }

    return result;
}

void fillPaycheck(const Employee &e, Paycheck &p, const string &company, const string &address) {
    //set company and address information
    strncpy(p.company, company.c_str(), sizeof(p.company) -1);
    p.company[sizeof(p.company) - 1] = '\0';
    strncpy(p.address, address.c_str(), sizeof(p.address) -1);
    p.address[sizeof(p.address) - 1] = '\0';
    
    // Copy employee name
    strncpy(p.name, e.name, sizeof(p.name) - 1);
    p.name[sizeof(p.name) - 1] = '\0'; // Ensure null termination

    // Calculate and set the numeric gross pay
    p.amount = static_cast<int>(calculatePay(e));  // Store the numeric amount

    // Convert the numeric amount to words and store in amountStr
    string amountInWords = cnvrtToEng(p.amount);
    strncpy(p.amountStr, amountInWords.c_str(), sizeof(p.amountStr) - 1);
    p.amountStr[sizeof(p.amountStr) - 1] = '\0';  // Ensure null termination

}


void printData(const Paycheck *p, int numEmploy){
    cout <<"Paychecks";
    cout << fixed << setprecision(2);
    
    for(int i = 0; i < numEmploy; i++){
        cout << "\n-----------------------------------\n";
        cout << "Employee " << (i + 1) << endl;
        cout << "Company: " << p[i].company << endl;
        cout << "Address: " << p[i].address << endl;
        cout << "Employee Name: " << p[i].name << endl;
        cout << "Gross Pay (Numeric): $" << p[i].amount << endl;
        cout << "Gross Pay (In Words): " << p[i].amountStr << endl;
        cout << "Signature: " << p[i].signature << endl;
        
    }
}