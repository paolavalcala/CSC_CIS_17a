
/* 
 * File:   structure.h
 * Author: paolaalcala
 *
 * Created on October 29, 2024, 2:48 PM
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Prime{
    unsigned char power; //Power associated with the prime number
    unsigned short prime;//Prime number factor
};

struct Primes{
    unsigned short n; //Number to factor into Primes
    unsigned char nPrimes; //Number of Primes
    Prime *pStrAry; //The Prime Structure Array
};


#endif /* STRUCTURE_H */

