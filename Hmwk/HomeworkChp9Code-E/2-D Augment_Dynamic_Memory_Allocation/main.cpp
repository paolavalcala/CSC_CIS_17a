#include <iostream>

using namespace std;


int **getData(int &rows,int &cols);//Get the Matrix Data

void printDat(const int* const *ary,int rows,int cols, bool addEndl);//Print the Matrix

int **augment(const int* const *ary,int rows,int cols);//Augment the original array

void destroy(int **ary,int rows);//Destroy the Matrix, i.e., reallocate memory


int main(){
	//declare varaibles
	int **ary = nullptr;
	int **newAry = nullptr;
	int rows, cols;
	
	//input 
	cin >> rows >> cols;
	// get the data
	ary = getData(rows, cols);
	//print the data
	printDat(ary, rows, cols, false);
	
	// Augment the array
    newAry = augment(ary, rows, cols);
    
    // Print the augmented array
    printDat(newAry, rows + 1, cols + 1, true);
    
    // destroy data
    destroy(ary, rows);
    destroy(newAry, rows + 1);
	
	
	return 0;
}


int **getData(int &rows,int &cols){
    //Get the Matrix Data
    int **ary = new int*[rows];
    
    for (int i = 0; i < rows; i++){
        ary[i] = new int[cols];
        for (int j = 0; j < cols; j++){
            cin >> ary[i][j];
        }
    }
    return ary;
}

void printDat(const int* const *ary, int rows, int cols, bool addEndl) {
    // Print the Matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ary[i][j];
            if (j < cols - 1) {
                cout << " ";  // Space between elements in the same row
            }
        }
        if (addEndl && i < rows - 1) {
            cout << endl;  // Add endl for every line except the last one
        } else if (!addEndl) {
            cout << endl;  // Normal endl for regular arrays
        }
    }
}

int **augment(const int* const *ary,int rows, int cols){
    //Augment the original array
    //add new row
    int **newAry = new int*[rows + 1];
    //add new col
    for (int i = 0; i < rows + 1; i++){
        newAry[i] = new int[cols + 1];
    }
    
    //fill the first row and first col with zeros
    for (int i = 0; i < rows + 1; i++){
        newAry[i][0] = 0; //fills the first col with 0's
    }
    
    for (int j = 0; j < cols + 1; j++){
        newAry[0][j] = 0; //fills the first row with 0s
    }
    
    // Copy the original data into the augmented array
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            newAry[i][j] = ary[i - 1][j - 1];
        }
    }
    
    return newAry;

}

void destroy(int **ary,int rows){
    //Destroy the Matrix, i.e., reallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] ary[i];
    }
    delete[] ary;
}

