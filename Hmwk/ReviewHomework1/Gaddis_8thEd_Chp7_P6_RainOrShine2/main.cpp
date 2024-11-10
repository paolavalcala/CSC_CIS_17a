/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on September 4, 2024, 1:47 am
 * Purpose: Rain or Shine Problem
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set a random seed
    
    //Declare all variables
    fstream weather;
    const int ROWS = 3;
    const int COLS = 30;
    char data[ROWS][COLS];
    int rainy[ROWS] = {0}, cloudy[ROWS] = {0}, sunny[ROWS] = {0}; // keeps total in an array
    int ttlRainy = 0,ttlCloudy = 0, ttlSunny = 0; // keeps count 
    
    //Initialize all variables
    weather.open("RainOrShine.txt", ios::in);
    
    for (int row = 0; row< ROWS; row++){
        for (int col = 0; col < COLS; col++){
            weather>>data[row][col];
        }
    }
    
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            switch (data[row][col]) {
                case 'R': rainy[row]++; ttlRainy++; break;
                case 'C': cloudy[row]++; ttlCloudy++; break;
                case 'S': sunny[row]++; ttlSunny++; break;
            }
        }
    }
    
    //Process or Map Solutions
    
    // Display the number of rainy, cloudy, and sunny days for each month
    const char* months[] = {"June", "July", "August"};
    for (int i = 0; i < ROWS; i++) {
        cout << months[i] << ":\n";
        cout << "Rainy Days: " << rainy[i] << endl;
        cout << "Cloudy Days: " << cloudy[i] << endl;
        cout << "Sunny Days: " << sunny[i] << endl << endl;
    }

    // Display total weather data for the whole period
    cout << "Total for the 3-month period:\n";
    cout << "Rainy Days: " << ttlRainy << endl;
    cout << "Cloudy Days: " << ttlCloudy << endl;
    cout << "Sunny Days: " << ttlSunny << endl;

    // Determine the month with the most rainy days
    int maxRainyIndex = 0;
    for (int i = 1; i < ROWS; i++) {
        if (rainy[i] > rainy[maxRainyIndex]) {
            maxRainyIndex = i;
        }
    }
    cout << months[maxRainyIndex] << " had the most rainy days.\n";
    
    //Display the output
    
    //close files
    weather.close();    
    //Exit the program
    return 0;
}
