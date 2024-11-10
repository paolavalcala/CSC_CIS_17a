#include <iostream>

using namespace std;


int *getData(int &);//Read the array

int *augment(const int *ary,int size);//Augment and copy the original array

void prntAry(const int *,int);//Print the array


int main(){
	//declare variables
	int *ary = nullptr;
	int *newAry = nullptr;
	int size;
	
	//input 
	cin >> size;
	// get the data
	ary = getData(size);
	//augment and copy the original array
	newAry = augment(ary, size);
	
	// print the array
	prntAry(ary, size);
	cout << endl;
	
	prntAry(newAry, size + 1);
	
	delete[] ary;
    delete[] newAry;
	

	return 0;
}


int *getData(int &size){
    //Read the array
    int *ary = new int[size];
    
    for (int i = 0; i < size; i++){
        cin >> ary[i];
    }
    return ary;
}

int *augment(const int *ary,int size){
    //Augment and copy the original array
    int *newAry = new int[size + 1];
    
    newAry[0] = 0; 
    
    for (int i = 0; i < size; i++){
       newAry[i + 1] = ary[i];
    }
    return newAry;
}

void prntAry(const int *ary,int size){
    //Print the array
    for (int i = 0; i < size; i++){
        if (i < size - 1){
            cout << ary[i] << " ";
        }else{
            cout << ary[i];
        }
    }
}