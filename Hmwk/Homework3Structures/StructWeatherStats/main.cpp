#include <iostream>
#include <sstream>  
#include <iomanip>

using namespace std;


struct Month
{
    string name;
    float ttlRain;
    int lowTemp;
    int highTemp;
    int avgTemp;
};

void getData(Month[], int);
float clcltAvg(Month[], int);
int clcltLowest(Month[], int, string &);
int clcltHighest(Month[], int, string &);
float clcltAvgTemp(Month[], int);
void printData(float avg, string lwstMnth, int lowTemp, string hghstMnth, int highTemp, float avgTemp);

int main(){
	//variables
	const int SIZE = 12;
	Month data[SIZE];
	
	//get data
	getData(data, SIZE);
	
	//avg Rainfall
	float avg = clcltAvg(data, SIZE);
	
	//lowest Temperature
	string lwstMnth;
	int lwstTemp = clcltLowest(data, SIZE, lwstMnth);
	
	//highest Temperature
	string hghstMnth;
	int hghstTemp = clcltHighest(data, SIZE, hghstMnth);
	
	//average temperature
    float avgTemp = clcltAvgTemp(data, SIZE);
	
	//print data
	printData(avg, lwstMnth, lwstTemp, hghstMnth, hghstTemp, avgTemp);
	
	return 0;
}


void getData(Month data[], int SIZE){
    for (int i = 0; i < SIZE; i++){
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        
        ss >> data[i].name;
        ss >> data[i].ttlRain;
        ss >> data[i].lowTemp;
        ss >> data[i].highTemp;
        data[i].avgTemp = (data[i].lowTemp + data[i].highTemp) / 2;
    }
}


float clcltAvg(Month data[], int SIZE){
    float total= 0;
    for (int i = 0; i < SIZE; i++){
        total += data[i].ttlRain;
    }
    return total / SIZE;
}

int clcltLowest(Month data[], int SIZE, string &lwstMnth){
    int lwstTemp = data[0].lowTemp;
    lwstMnth = data[0].name;
    
    for (int i = 1; i < SIZE; i++){
        if (data[i].lowTemp < lwstTemp){
            lwstTemp = data[i].lowTemp;
            lwstMnth = data[i].name;
        }
    }
    return lwstTemp;
}

int clcltHighest(Month data[], int SIZE, string &hghstMnth){
    int hghstTemp = data[0].highTemp;
    hghstMnth = data[0].name;
    
    for (int i = 1; i < SIZE; i++){
        if (data[i].highTemp > hghstTemp){
            hghstTemp = data[i].highTemp;
            hghstMnth = data[i].name;
        }
    }
    return hghstTemp;
}

float clcltAvgTemp(Month data[], int SIZE){
    float total = 0;
    for(int i = 0; i < SIZE; i++){
        total += data[i].avgTemp;
    }
    return total / SIZE;
}

void printData(float avg, string lwstMnth, int lwstTemp, string hghstMnth, int hghstTemp, float avgTemp){
    cout << fixed << setprecision(1);
    cout  << "Average Rainfall " << avg <<  " inches/month" << endl;
    
    cout  << "Lowest  Temperature " << lwstMnth << "  " <<  lwstTemp << " Degrees Fahrenheit" <<endl;
    
    cout << "Highest Temperature " << hghstMnth << "  " << hghstTemp <<" Degrees Fahrenheit" << endl;
    
    cout << fixed << setprecision(0);
    cout << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << endl;
}