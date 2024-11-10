
#include <iostream>

using namespace std;


int **getData(int &rows,int &cols);        //Return the 2-D array and its size.

void prntDat(const int* const *ary,int rows,int cols);//Print the 2-D Array

void destroy(int **ary,int rows);       //Deallocate memory

int sum(const int * const *ary, int rows,int cols);    //Return the Sum


int main(){
	//declare variables
	int **ary = nullptr;
	int rows, cols;
	
	//input
	cin >> rows >> cols;
	
	//get the Data
	ary = getData(rows, cols);
	
	//print the Data
	prntDat(ary, rows, cols);
	
	//deallocate the memory
	destroy(ary, rows);

	
	return 0;
}


int **getData(int &rows,int &cols){
    //Return the 2-D array and its size
    int **ary = new int*[rows];
    
    for (int i = 0; i < rows; i++){
        ary[i] = new int[cols];
        for (int j = 0; j < cols; j++){
            cin >> ary[i][j];
        }
    }
    return ary;
}

void prntDat(const int* const *ary,int rows,int cols){
    //Print the 2-D Array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << ary[i][j];
            if (j < cols - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    
    //return the sum 
	int ttl = sum(ary, rows, cols);
	cout << ttl;

}

void destroy(int **ary,int rows){
    //Deallocate memory
    for(int i = 0; i < rows; i++){
        delete[] ary[i];
    }
    delete[] ary;
}

int sum(const int * const *ary, int rows,int cols){
    //Return the Sum
    int ttlSum = 0;
    
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            ttlSum += ary[i][j];
        }
    }
    return ttlSum;
}