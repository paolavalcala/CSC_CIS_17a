
/* 
 * File:   Customer.h
 * Author: paolaalcala
 *
 * Created on October 30, 2024, 11:39 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

const int SIZE = 100; //max size for account number

struct Customer 
{
    string accountNum;  //5 digit account num
    char name[SIZE]; //customer name
    char address[SIZE]; // customer address
    float startBalance; // balance at the beginning of each month
    float *checks; //all recorded checks written this month
    float *deposits; // all recorded deposits this month
    int ttlChecks; // counter for total amount of checks
    int ttlDeposits; //counter total amount of deposits
    
    
};

#endif /* CUSTOMER_H */

