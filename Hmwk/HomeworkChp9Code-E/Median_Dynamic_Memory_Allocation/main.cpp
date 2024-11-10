
#include <iostream>
#include <iomanip>

using namespace std;


int *getData(int &nums);         //Return the array size and the array
void prntDat(int *ary,int size);    //Print the integer array
float *median(int *ary,int size);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *medAry, int size);     //Print the median Array

int main(){
	//Declare varaibles
	int  *ary = nullptr, //ptr to array
	    size;
	    
    float *medAry = nullptr; //ptr to median array
	    
	//input 
	cin >> size;
	// get data 
	ary = getData(size);
	
	//print 
	prntDat(ary, size);
	
	//calculate median
	medAry = median(ary, size);
	
	//print meidan
    prntMed(medAry, size);	
	
	delete []ary;
	delete []medAry;
	
	return 0;
}

int *getData(int &nums){
    int *ary = new int[nums];
    
    for (int i = 0; i < nums; i++) {
        cin >> ary[i];
    }
    return ary;
}

void prntDat(int *ary,int size){
    for (int i = 0; i < size; i++){
        if (i < size-1){
            cout << ary[i] << " ";
        }else{
            cout << ary[i] << endl;
        }
    }
    
}

float *median(int *ary,int size){
 //Fill the median Array with the Float array size, the median, and the integer array data
   float *medAry = new float [size + 2]; //create a dynamic float array 2 larger in size than the dynamic integer array
   
   //set index 0 to the new size of the array
   medAry[0] = size + 2;
   
   //calculate the median and return sum to index 1
   float sum = 0;
   
   for (int i = 0; i < size; i++){
       sum+=ary[i];
   }
   float med = sum / size;
   
   medAry[1] = med;
   
   //returning int array values as floats
   for (int i = 2; i < size + 2; i++){
       medAry[i] = ary[i - 2];
   }
   return medAry;
   
}

void prntMed(float *medAry, int size){
    cout << medAry[0] << " ";
    for (int i = 1; i < size +2; i++ ){
        cout << fixed << showpoint << setprecision(2);
        if (i < size +1) {
            cout <<medAry[i] << " ";
        }else{
            cout << medAry[i];
        }
    }
}