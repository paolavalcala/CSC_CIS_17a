
/* 
 * File:   Structures.h
 * Author: Paola Alcala
 *
 * Created on October 24, 2024, 4:46 PM
 */

/*Dynamic structure for a customer that will determine 
 if he/she has exceeded his/her checking account ballance.
 
 Account number (5 digits only)
 Name
 Address
 Balance at the beginning of each month
 Record all checks written by the customer this month; 
 loop until customer is done entering checks.
 Record all deposits and loop until done*/


#ifndef STRUCTURES_H
#define STRUCTURES_H

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

#endif /* STRUCTURES_H */

