/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char array[][COLMAX],int &rowDet);//Outputs row and columns detected from input
void sort(char array[][COLMAX],int rowIn,int colIn,const char replace[],const char with[]);//Sort by row using strcmp();
void print(const char array[][COLMAX],int rowIn,int colIn);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char a[],char b[],const char replace[],const char with[]);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}


int  read(char array[][COLMAX],int &rowDet){
    cin.ignore(); // Ignore newline character from previous input
    int colDet = 0;
    for (int i = 0; i < rowDet; ++i) {
        cin.getline(array[i], COLMAX);
        int len = strlen(array[i]);
        if (len > colDet)
            colDet = len;
    }
    return colDet;
}


void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[]) {
    for (int i = 0; i < rowIn - 1; ++i) {
        for (int j = i + 1; j < rowIn; ++j) {
            // strcmp with replacement rules
            if (strcmp(array[i], array[j], replace, with) >= 0) { // Reversed the condition
                char temp[COLMAX];
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}




void print(const char array[][COLMAX],int rowIn,int colIn){
    for (int i = 0; i < rowIn; ++i) {
        cout << array[i] << endl;
    }
}


int strcmp(char a[], char b[], const char replace[], const char with[]) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int maxlen = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < maxlen; ++i) {
        char ch1 = (i < len1) ? a[i] : '\0'; // Handle the case where one string is shorter
        char ch2 = (i < len2) ? b[i] : '\0'; // than the other

        // replacement rules
        for (int j = 0; j < strlen(replace); ++j) {
            if (ch1 == replace[j])
                ch1 = with[j];
            if (ch2 == replace[j])
                ch2 = with[j];
        }

        // Compare characters after 
        if (ch1 != ch2)
            return ch1 - ch2;
    }

    // compare their lengths
    return len1 - len2;
}

