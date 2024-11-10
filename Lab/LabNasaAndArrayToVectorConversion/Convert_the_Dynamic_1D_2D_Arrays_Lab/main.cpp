
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 * Created on September 26th, 2024, 5:44 PM
 * Purpose:  Convert the Dynamic 1D abd 2d Arrays to Vectors Lab
 */

// System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector> // Include the vector library
using namespace std;

// Function Prototypes Here
void prntVec(const vector<int> &, int);
void prntVec(const vector<vector<int> > &);
vector<int> fillVec(int, int, int);
vector<vector<int> > fillVec(int, int);
void fillVec(vector<vector<int> > &, const vector<int> &, int, int);
void swap(int &, int &);
void smlLst(vector<int> &, int, int);
void mrkSort(vector<int> &);

// Program Execution Begins Here
int main(int argc, char** argv) {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Declare all Variables Here
    int rowsize = 4; // Row size for both 1 and 2 D arrays
    int colsize = 3; // The column size for a 2-dimensional array
    int lowRng = 100, highRng = 999;
    int perLine = 4;
        
    // Fill each parallel vector
    vector<int> array = fillVec(rowsize, highRng, lowRng);
    vector<int> brray = fillVec(rowsize, highRng / 10, lowRng / 10);
    vector<int> crray = fillVec(rowsize, highRng / 100, lowRng / 100);
    
    // Sort the vectors for all positions
    mrkSort(array);
    mrkSort(brray);
    mrkSort(crray);
    
    // Fill the 2-D vector
    vector<vector<int> > table = fillVec(rowsize, colsize);
    fillVec(table, array, rowsize, 0);
    fillVec(table, brray, rowsize, 1);
    fillVec(table, crray, rowsize, 2);
    
    // Print the values in the vector
    prntVec(array, perLine);
    prntVec(brray, perLine);
    prntVec(crray, perLine);
    prntVec(table);

    // Exit
    return 0;
}

void fillVec(vector<vector<int> > &a, const vector<int> &c, int rowSize, int wchCol) {
    for (int row = 0; row < rowSize; row++) {
        a[row][wchCol] = c[row];
    }
}

vector<int> fillVec(int n, int hr, int lr) {
    n = n < 2 ? 2 : n;
    vector<int> a(n);
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand() % (hr - lr + 1) + lr;
    }
    return a;
}

vector<vector<int> > fillVec(int rows, int cols) {
    // Allocate Memory for 2-D vector
    rows = rows < 2 ? 2 : rows;
    cols = cols < 2 ? 2 : cols;
    vector<vector<int> > a(rows, vector<int>(cols, 0));
    return a;
}

void prntVec(const vector<vector<int> > &a) {
    cout << endl << "The Vector Values" << endl;
    for (const auto &row : a) {
        for (const auto &elem : row) {
            cout << setw(4) << elem;
        }
        cout << endl;
    }
}

void prntVec(const vector<int> &a, int perLine) {
    // Print the values in the vector
    cout << endl << "The Vector Values" << endl;
    for (int indx = 0; indx < a.size(); indx++) {
        cout << a[indx] << " ";
        if (indx % perLine == (perLine - 1)) cout << endl;
    }
    cout << endl;
}

void mrkSort(vector<int> &a) {
    for (int pos = 0; pos < a.size() - 1; pos++) {
        smlLst(a, a.size(), pos);
    }
}

void smlLst(vector<int> &a, int n, int pos) {
    for (int i = pos + 1; i < n; i++) {
        if (a[pos] > a[i]) {
            swap(a[pos], a[i]);
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
