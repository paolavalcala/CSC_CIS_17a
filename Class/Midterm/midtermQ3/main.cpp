/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on Oct 29, 2024, 12:44 PM
 * Purpose: Midterm Question 3
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    //calculate mode
    
    //sort array using mark sort
    int *srtdArry = copy(array->data, array->size);
    mrkSort(srtdArry, array->size);
    
    //loop and count frequency
    int maxFreq = 1, crrntFreq = 1, nModes = 0;
    
    for (int i = 1; i < array->size; i++){
        if(srtdArry[i] == srtdArry[i - 1]){
            crrntFreq++;
        }else{
            if (crrntFreq > maxFreq){
                maxFreq = crrntFreq;
                nModes = 1;
            }else if(crrntFreq == maxFreq){
                nModes++;
            }
            crrntFreq = 1;
        }
    }
    
    //loop and count how many
    if (crrntFreq > maxFreq){
        maxFreq = crrntFreq;
        nModes = 1;
    } else if (crrntFreq == maxFreq){
        nModes++;
    }
    
    stats->modFreq = maxFreq;
    stats->mode->size = nModes;
    
    //fill mode array
    if(maxFreq > 1){
        stats->mode->data = new int[nModes];
        crrntFreq = 1;
        int modeIndex = 0;
        
        for (int i = 1; i < array->size; i++) {
            if (srtdArry[i] == srtdArry[i - 1]) {
                crrntFreq++;
            } else {
                if (crrntFreq == maxFreq) {
                    stats->mode->data[modeIndex++] = srtdArry[i - 1];
                }
                crrntFreq = 1;
            }
        }
        if (crrntFreq == maxFreq) {
            stats->mode->data[modeIndex] = srtdArry[array->size - 1];
        }
    } else {
        stats->mode->size = 0;
        stats->mode->data = nullptr;
    }
    
    //calculate median
    //check to see if array has even or odd amount of numbers
    if (array->size % 2 == 1){
    //if odd median is a center of sorted array
        stats->median = srtdArry[array->size / 2];
    }else{
     //if even median takes two middle ints of sorted array and divides by 2   
        stats->median = (srtdArry[(array->size / 2 )- 1] + srtdArry[array->size / 2]) / 2.0;
    }
    
    
    // Calculate Average
    float sum = 0;
    for (int i = 0; i < array->size; i++) {
        sum += array->data[i];
    }
    stats->avg = sum / array->size;
    
    // Clean up the copied sorted array
    delete[] srtdArry;
    
    // Return the populated Stats object
    return stats;
    
    
}