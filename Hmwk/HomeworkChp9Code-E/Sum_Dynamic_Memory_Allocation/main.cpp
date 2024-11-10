
#include <iostream>

using namespace std;


int *getData(int &size);             //Return the array size and the array from the inputs

int *sumAry(const int *ary,int size);//Return the array with successive sums

void prntAry(const int *ary, int size);//Print the array


int main(){
	//declare variables
	int *ary = nullptr;
	int *sAry = nullptr;
	int size;
	
	//input 
	cin >> size;
	//get getData
	ary = getData(size);
	//return the array with successive sums
	sAry = sumAry(ary, size);
	//print the array
	prntAry(ary, size);
	cout << endl;
	
	//print sum array
	prntAry(sAry, size);
	
	delete[] ary;
	delete[] sAry;
	
	return 0;
}


int *getData(int &size){
    //Return the array size and the array from the inputs
    int *ary = new int[size];
    
    for (int i = 0; i < size; i++){
        cin >> ary[i];
    }
    return ary;
}

int *sumAry(const int *ary,int size){
    //Return the array with successive sums
    int *sAry = new int[size]; //create a sum array
    sAry[0] = ary[0];
    
    for (int i = 1; i < size; i++){
        sAry[i] = sAry[i-1] + ary[i]; // s[1] = s[1-0 = 0] + a[0] sum array accumulates sum of the previous sum and adds the num from original array
    }
    return sAry;
}

void prntAry(const int *ary,int size){
    //Print the array
    for (int i = 0; i < size; i++){
        if (i < size-1){
            cout << ary[i] << " ";
        }else{
            cout << ary[i];
        }
    }
}