
/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Find the Max, Min, and Sum of an integer array.
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int array[],int sizeIn);
int  stat(const int array[],int sizeIn,int &max,int &min);
void print(const int array[],int sizeIn,int sum,int max,int min);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}


void read(int array[],int sizeIn){
    for (int i = 0; i < sizeIn; i++){
        cin >> array[i];
    }
}

int  stat(const int array[],int sizeIn,int &max,int &min){
    max = array[0]; //array to hold max 
    min = array[0]; //arrat to hold min 
    
    int sum = 0;
    
    for (int i = 0; i < sizeIn; i++){
        // update max array
        if (array[i] > max){
            max = array[i];
        }
        
        //updacte min Array
        if (array[i] < min){
            min = array[i];
        }
        sum += array[i];
    }
    return sum;
}

void print(const int array[],int sizeIn,int sum,int max,int min){
    for (int i = 0; i < sizeIn; i++){
        cout << "a[" << i << "] = " << array[i] << endl;
    }
    cout << "Min  = " << min <<endl;
    cout << "Max  = " << max << endl;
    cout << "Sum  = " << sum << endl;
}
