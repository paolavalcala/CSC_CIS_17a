#include <iostream>
#include <sstream>  
#include <iomanip>

using namespace std;


enum Months { JANUARY, FEBRUARY, MARCH, APRIL, MAY, 
    JUNE, SIZE };


struct Month
{
    string name;
    float ttlRain;
    int lowTemp;
    int highTemp;
    int avgTemp;
};

void getData(Month[]);
float clcltAvg(Month[], int);
int clcltLowest(Month[], int);
int clcltHighest(Month[], int);
float clcltAvgTemp(Month[], int);
void printData(float avg, int lowTemp, int highTemp, float avgTemp);

int main(){
	//variables
	Month data[SIZE];
	
	//get data
	getData(data);

	
	//avg Rainfall
	float avg = clcltAvg(data, SIZE);
	
	//lowest Temperature
	string lwstMnth;
	int lwstTemp = clcltLowest(data, SIZE);
	
	//highest Temperature
	string hghstMnth;
	int hghstTemp = clcltHighest(data, SIZE);
	
	//average temperature
    float avgTemp = clcltAvgTemp(data, SIZE);
	
// 	print data
	printData(avg, lwstTemp, hghstTemp, avgTemp);
	
	return 0;
}


void getData(Month data[]){
    const string monthNames[] = { "January", "February", "March", "April", "May", 
        "June" };

    string line;
    getline(cin, line);
    
    stringstream ss(line);

    for (Months month = JANUARY; month < SIZE; month = static_cast<Months>(month + 1)) {
        data[month].name = monthNames[month];
        
        cout << "Enter the total rainfall for the month:" << endl;        
        ss >> data[month].ttlRain;
        cout << "Enter the high temp:" << endl;
        ss >> data[month].highTemp;
        cout << "Enter the low temp:" << endl;
        ss >> data[month].lowTemp;
        data[month].avgTemp = (data[month].lowTemp + data[month].highTemp) / 2;
    }
}


float clcltAvg(Month data[], int SIZE){
    float total= 0;
    for (int i = 0; i < SIZE; i++){
        total += data[i].ttlRain;
    }
    return total / SIZE;
}

int clcltLowest(Month data[], int SIZE){
    int lwstTemp = data[0].lowTemp;
    
    for (int i = 1; i < SIZE; i++){
        if (data[i].lowTemp < lwstTemp){
            lwstTemp = data[i].lowTemp;
        }
    }
    return lwstTemp;
}

int clcltHighest(Month data[], int SIZE){
    int hghstTemp = data[0].highTemp;
    
    for (int i = 1; i < SIZE; i++){
        if (data[i].highTemp > hghstTemp){
            hghstTemp = data[i].highTemp;
        }
    }
    return hghstTemp;
}

float clcltAvgTemp(Month data[], int SIZE){
    float ttlTemp = 0;
    int ttlCount = 0;
    
    for(int i = 0; i < SIZE; i++){
        ttlTemp += data[i].highTemp  + data[i].lowTemp;
        ttlCount += 2;
    }
    return ttlTemp / ttlCount;
}

void printData(float avg, int lwstTemp, int hghstTemp, float avgTemp){
    cout << fixed << setprecision(2);
    cout << "Average monthly rainfall:" << avg << endl;
    cout << "High Temp:" << hghstTemp << endl;
    cout << "Low Temp:" << lwstTemp << endl;
    cout << fixed << setprecision(1);
    cout << "Average Temp:" << avgTemp;
}