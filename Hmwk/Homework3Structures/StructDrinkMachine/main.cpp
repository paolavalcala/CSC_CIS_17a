#include <iostream>

using namespace std;

struct Drinks
{
    string name;
    float cost;
    int numOfDrnks;
};

void getData(Drinks[], int);
void printData(Drinks[], int);

int main(){
	//your code here
	const int SIZE = 5;
	Drinks data[SIZE] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
	};
	
	
	//get data
	getData(data, SIZE);
	
	//print data
	printData(data, SIZE);
	
	return 0;
}


void getData(Drinks data[], int SIZE){
    for (int i = 0; i < SIZE; i++){
        cin >> data[i].name;
        cin >> data[i].cost;
        cin >> data[i].numOfDrnks;
    }
}

void printData(Drinks data[], int SIZE){
    for (int i = 0; i < SIZE; i++){
        cout << data[i].name << endl;
        cout << data[i].cost << endl;
        cout << data[i].numOfDrnks << endl;
    }
}