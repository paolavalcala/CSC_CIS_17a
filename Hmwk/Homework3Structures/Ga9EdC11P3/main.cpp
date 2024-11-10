
/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct Divisions 
{
    string name;
    float frstQSls;
    float scndQsls;
    float thrdQSls;
    float frthQSls;
    float total;
    float average;
};

//Function Prototypes
void getData(Divisions &d);
void clcltData(Divisions &d);
void displyData(const Divisions &d);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    //declare struct varaibles
    Divisions north = {"North"};
    Divisions west = {"West"};
    Divisions east = {"East"};
    Divisions south = {"South"};
    
    //input getData
    getData(north);
    clcltData(north);
    displyData(north);
    cout << endl;
    
    getData(west);
    clcltData(west);
    displyData(west);
    cout << endl;
    
    getData(east);
    clcltData(east);
    displyData(east);
    cout << endl;
    
    getData(south);
    clcltData(south);
    displyData(south);
    
    //Display Outputs

    //Exit stage right!
    return 0;
}


void getData(Divisions &d){
    cout << d.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> d.frstQSls;
    cout << "Enter second-quarter sales:" << endl;
    cin >> d.scndQsls;
    cout << "Enter third-quarter sales:" << endl;
    cin >> d.thrdQSls;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> d.frthQSls;
}

void clcltData(Divisions &d){
    d.total = d.frstQSls + d.scndQsls + d.thrdQSls + d.frthQSls;
    d.average = d.total/4;
}

void displyData(const Divisions &d){
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$" << d.total << endl;
    cout << "Average Quarterly Sales:$" << d.average;
}