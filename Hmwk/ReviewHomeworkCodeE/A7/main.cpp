
/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Augment a table with row/column/grand sums
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int array[][COLMAX],int &row,int &col);//Prompt for size then table
void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]);//Sum rows,col,grand total
void print(const int array[][COLMAX],int row,int col,int n);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX],int &row,int &col){
    cout << "Input a table and output the Augment row,col and total sums."<<endl;
    cout << "First input the number of rows and cols. <20 for each"<<endl;
    cin>>row>>col;
    
    cout << "Now input the table." <<endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    }
}


void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    //  Create a new table augmented by 1 row and 1 column.
    //copy array to augAry
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            augAry[i][j] = array[i][j];
        }
    }
    //  augmented table has the row sums in the new column and the column sums in the new row
    for (int i = 0; i < row; ++i) {
        int rowSum = 0;
        for (int j = 0; j < col; ++j) {
            rowSum += array[i][j];
        }
        augAry[i][col] = rowSum;
    }
    
    for (int j = 0; j < col; ++j) {
        int colSum = 0;
        for (int i = 0; i < row; ++i) {
            colSum += array[i][j];
        }
        augAry[row][j] = colSum;
    }
    
    
    int grandTotal = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            grandTotal += array[i][j];
        }
    }
    augAry[row][col] = grandTotal;

    // sum is in the lower corner of the table
}


void print(const int array[][COLMAX],int row,int col,int n){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << setw(n) << array[i][j];
        }
        cout << endl;
    }
}