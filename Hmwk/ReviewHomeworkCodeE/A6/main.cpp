/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Fill even/odd vectors and transfer to 2-D array
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &even, vector<int> &odd);
void copy(vector<int> even, vector<int> odd,int array[][COLMAX]);
void prntVec(vector<int> even, vector<int> odd,int n);//int n is the format setw(n)
void prntAry(const int array[][COLMAX],int rows,int cols,int n);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}


void read(vector<int> &even, vector<int> &odd){
    int size;
    cout <<"Input the number of integers to input."<<endl;
    cin >> size;
   
    cout<<"Input each number."<<endl; 
    int num;
    
    for (int i = 0; i < size; ++i) {
        cin >> num;
        if (num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    for (int i = 0; i < even.size(); i++){
        array[i][0] = even[i];
    }
    for (int i = 0; i < odd.size(); i++){
        array[i][1] = odd[i];
    }
}

void prntVec(vector<int> even, vector<int> odd,int n){
    cout << setw(10) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;

    int max_size = max(even.size(), odd.size());
    for (int i = 0; i < max_size; ++i) {
        if (i < even.size())
            cout << setw(20) << (i < even.size() ? to_string(even[i]) : "");
        else
            cout << setw(20) << "";

        if (i < odd.size())
            cout << setw(n) << (i < odd.size() ? to_string(odd[i]) : "") << endl;
        else
            cout << setw(n) << "" << endl;
    }
}


void prntAry(const int array[][COLMAX],int rows,int cols,int n){
    cout << setw(10) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;

    int max_size = max(rows, cols);
    for (int i = 0; i < max_size; ++i) {
        cout << setw(20) << (i < rows ? to_string(array[i][0]) : "") << setw(n) << (i < cols ? to_string(array[i][1]) : "") << endl;
    }
}