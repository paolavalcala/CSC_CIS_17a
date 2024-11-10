
/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

    struct MonthlyBudget
    {
        float housing;
        float util;
        float expenses;
        float transport;
        float food;
        float medical;
        float insurance;
        float entertainment;
        float clothing;
        float misc;
    };

//Function Prototypes
void getSpent(MonthlyBudget &spent);
void display(const MonthlyBudget &budget, const MonthlyBudget &spent);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    MonthlyBudget budget = {500.0, 150.0, 65.0, 50.0, 250.0, 30.0, 100.0, 150.0, 75.0, 50.0};
    MonthlyBudget spent;

    //Initialize Variables
    
    //get getData
    getSpent(spent);
    
    display(budget, spent);

    //Exit stage right!
    return 0;
}


void getSpent(MonthlyBudget &spent){
    cout << "Enter housing cost for the month:$" << endl;
    cin >> spent.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> spent.util;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> spent.expenses;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> spent.transport;
    cout << "Enter food cost for the month:$" << endl;
    cin >> spent.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> spent.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> spent.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> spent.entertainment;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> spent.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> spent.misc;
}


void display(const MonthlyBudget &budget, const MonthlyBudget &spent){
    float totalBudget = budget.housing + budget.util + budget.expenses + budget.transport +
                        budget.food + budget.medical + budget.insurance + budget.entertainment +
                        budget.clothing + budget.misc;

    float totalSpent = spent.housing + spent.util + spent.expenses + spent.transport +
                      spent.food + spent.medical + spent.insurance + spent.entertainment +
                      spent.clothing + spent.misc;

    float totalDifference = totalBudget - totalSpent;

    // Output each category status
    cout << (spent.housing == budget.housing ? "Housing Even" : (spent.housing > budget.housing ? "Housing Over" : "Housing Under")) << endl;
    cout << (spent.util == budget.util ? "Utilities Even" : (spent.util > budget.util ? "Utilities Over" : "Utilities Under")) << endl;
    cout << (spent.expenses == budget.expenses ? "Household Expenses Even" : (spent.expenses > budget.expenses ? "Household Expenses Over" : "Household Expenses Under")) << endl;
    cout << (spent.transport == budget.transport ? "Transportation Even" : (spent.transport > budget.transport ? "Transportation Over" : "Transportation Under")) << endl;
    cout << (spent.food == budget.food ? "Food Even" : (spent.food > budget.food ? "Food Over" : "Food Under")) << endl;
    cout << (spent.medical == budget.medical ? "Medical Even" : (spent.medical > budget.medical ? "Medical Over" : "Medical Under")) << endl;
    cout << (spent.insurance == budget.insurance ? "Insurance Even" : (spent.insurance > budget.insurance ? "Insurance Over" : "Insurance Under")) << endl;
    cout << (spent.entertainment == budget.entertainment ? "Entertainment Even" : (spent.entertainment > budget.entertainment ? "Entertainment Over" : "Entertainment Under")) << endl;
    cout << (spent.clothing == budget.clothing ? "Clothing Even" : (spent.clothing > budget.clothing ? "Clothing Over" : "Clothing Under")) << endl;
    cout << (spent.misc == budget.misc ? "Miscellaneous Even" : (spent.misc > budget.misc ? "Miscellaneous Over" : "Miscellaneous Under")) << endl;

    // Output overall budget status
    if (totalDifference > 0) {
        cout << "You were $" << fixed << setprecision(2) << totalDifference << " under budget";
    } else if (totalDifference < 0) {
        cout << "You were $" << fixed << setprecision(2) << -totalDifference << " over budget";
    } else {
        cout << "You were exactly on budget!";
    }
}