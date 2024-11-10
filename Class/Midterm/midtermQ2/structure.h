
/* 
 * File:   structure.h
 * Author: Paola Alcala
 *
 * Created on October 24, 2024, 11:24 PM
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H

//array of structures created dynamically 

//ask upfront how many employees you are inputting
//the company pays straight time for the first 20 hours worked
//double time for hours worked over 20 hours but less than 40 hours

//Employee structure to determine the gross pay for any number of employees
struct Employee
{
    char name[100]; //employee name
    int hrsWorkd; //hours worked
    float ratePay; //rate of pay 
};

//output employee information in the form of a paycheck
struct Paycheck
{
    char company[100];
    char address[100];
    char name[100]; //employee name
    int amount; // amount numerical
    char amountStr[100]; //gross pay in english of numerical value
    char signature[100] = "Authorized Signature"; //signature line
};

#endif /* STRUCTURE_H */

