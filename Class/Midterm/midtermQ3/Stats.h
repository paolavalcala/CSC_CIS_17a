/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   stats.h
 * Author: paolaalcala
 *
 * Created on October 30, 2024, 5:10 PM
 */

#include "Array.h"

#ifndef STATS_H
#define STATS_H

struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

#endif /* STATS_H */

