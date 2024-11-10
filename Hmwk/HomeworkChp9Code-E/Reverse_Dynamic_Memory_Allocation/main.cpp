
#include <iostream>

using namespace std;


int *getData(int &);               //Fill the array

int *sort(const int *ary,int nums);         //Sort smallest to largest

int *reverse(const int *,int);  //Sort in reverse order

void prntDat(const int *srtAry,int size); //Print the array


int main(){
	//set varaibles
	int *ary = nullptr,
	    *srtAry = nullptr,
	    *rvrAry = nullptr,
	    size; 
	
	//input 
	cin >> size;
	//get data 
	ary = getData(size);
	//sort 
	srtAry = sort(ary, size);
	
	//reverse
	rvrAry = reverse(srtAry, size);
	//print sorted array
	prntDat(srtAry, size);
	cout << endl;
	
	//print reveresed array 
	prntDat(rvrAry, size);
	
    delete[] ary;
    delete[] srtAry;
    delete[] rvrAry;
	
	return 0;
}


int *getData(int &nums){
    //fill the array 
    int *ary = new int[nums];
    
    for (int i = 0; i < nums; i++){
        cin >> ary[i];
    }
    return ary;
}

int *sort(const int *ary,int nums){
    //Sort smallest to largest
    int *srtAry = new int[nums];
    
    for (int i = 0; i < nums; i++){
        srtAry[i] = ary[i];
    }
    
    for (int i = 0; i < nums-1; i++){
        int minIdx = i;
        for (int j = i+1; j < nums; j++){
            if (srtAry[j] < srtAry[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(srtAry[i], srtAry[minIdx]);
    }
    return srtAry;
}

int *reverse(const int *srtAry,int nums){
    //Sort in reverse order
    int *rvrAry = new int[nums];
    
    for (int i = 0; i < nums; i++){
        rvrAry[i] = srtAry[nums - 1 - i];
    }
    return rvrAry;
}

void prntDat(const int *ary,int size){
    //Print the array
    for (int i = 0; i < size; i++){
        if (i < size - 1){
            cout << ary[i] << " ";
        }else{
            cout << ary[i];
        }
    }
}