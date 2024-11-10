/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on Oct 29, 2024, 12:44 PM
 * Purpose: Midterm Question 7
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include "structure.h"
#include <cmath> // For sqrt
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 



bool isPrime(int); //Determine if the number is Prime
int power(int,int &); //What power is this factor and remove from n
int nPrimes(int); //How many Primes
Primes *factor(int); //Factor the number into it’s Primes
void prtPrms(const Primes *); //Print the prime factors
void cleanUp(Primes *); //Clean it all up



//Program Execution Begins Here
int main(int argc, char** argv) {
   
    int number;
    
    cout << "Enter a number between 2 and 65000: ";
    cin >> number;
    
    if (number < 2 || number > 65000){
        cout << "Invalid input";
        return 1;
    }
    
    Primes* primes = factor(number);
    prtPrms(primes);
    cleanUp(primes);
    
    //Exit the program
    return 0;
}



bool isPrime(int num){
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6){
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}


int power(int prime, int &n){
    int count = 0;
    while(n % prime == 0){
        n /= prime;
        count++;
    }
    return count;
}


int nPrimes(int n){
    int count = 0;
    for (int i = 2; i <= n; i++){
        if (isPrime(i) && n % 1 == 0){
            count++;
            while(n % i == 0) n /= i;
        }
    }
    return count;
}


Primes* factor(int n) {
    Primes* primesStruct = new Primes;
    primesStruct->n = n;
    primesStruct->nPrimes = nPrimes(n);
    primesStruct->pStrAry = new Prime[primesStruct->nPrimes];

    int index = 0;
    for (int i = 2; i <= n && index < primesStruct->nPrimes; i++) {
        if (isPrime(i) && n % i == 0) {
            primesStruct->pStrAry[index].prime = i;
            primesStruct->pStrAry[index].power = power(i, n);
            index++;
        }
    }
    return primesStruct;
}



void prtPrms(const Primes* primes) {
    cout << primes->n << " = ";
    for (int i = 0; i < primes->nPrimes; i++) {
        cout << primes->pStrAry[i].prime << "^" << static_cast<int>(primes->pStrAry[i].power);
        if (i < primes->nPrimes - 1) cout << " * ";
    }
    cout << endl;
}


void cleanUp(Primes* primes) {
    delete[] primes->pStrAry;
    delete primes;
}