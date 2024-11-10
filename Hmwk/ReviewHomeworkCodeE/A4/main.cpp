
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 * Created on September 9th 2024 
 * Purpose:  Sort using a 2-Dimension Array of characters
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char array[][COLMAX],int &rowDet);//Outputs row and columns detected from input
void sort(char array[][COLMAX],int rowIn,int colIn);//Sort by row
void print(const char array[][COLMAX],int rowIn,int colIn);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}


//Outputs row and columns detected from input
int  read(char array[][COLMAX],int &rowDet){
    cin.ignore();
    int colDet = 0;
    for (int i = 0; i < rowDet; i ++){
        cin.getline(array[i], COLMAX);
        int len = strlen(array[i]);
        if (len > colDet)
        colDet = len;
    }
    return colDet;
}

//Sort by row
void sort(char array[][COLMAX],int rowIn,int colIn){
    for(int i = 0; i < rowIn - 1; i++){
        for(int j = 0; j < rowIn - i - 1; j++){
            if (strcmp(array[j], array[j + 1]) > 0){
                swap(array[j], array[j + 1]);
            }
        }
    }
}

//Print the sorted 2-D array
void print(const char array[][COLMAX],int rowIn,int colIn){
    for (int i = 0; i < rowIn; i++){
        cout << array[i] << endl;
    }
}