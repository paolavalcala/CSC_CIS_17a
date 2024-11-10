

/* 
 * Purpose:  Search an array for a value
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array

int  srch1(const char sntnce[],const char pattern[],int start);//Search for 1 occurrence
void srchAll(const char sntnce[],const char pattern[],int match[]);//Search for all occurrences
void print(const char arr[]);//Print the character arrays
void print(const int match[]); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int srch1(const char sntnce[], const char pattern[], int start) {
    int sntnceLen = strlen(sntnce);
    int patternLen = strlen(pattern);
    
    for (int i = start; i <= sntnceLen - patternLen; ++i) {
        int j;
        for (j = 0; j < patternLen; ++j) {
            if (sntnce[i + j] != pattern[j])
                break; // mismatch found, break inner loop
        }
        if (j == patternLen)
            return i; // pattern found at index i
    }
    return -1; // pattern not found
}



void srchAll(const char sntnce[],const char pattern[],int match[]) {
    //srchAll Input->sentence, pattern Output->position array
    int start = 0; // search from index 0 
    int count = 0; //number of matches found
    
    // Keep searching until no more occurrences are found
    while (true) {
        int foundIndex = srch1(sntnce, pattern, start);
        
        // If pattern is found
        if (foundIndex != -1) {
            match[count++] = foundIndex;
            start = foundIndex + 1;
        } else {
            // No more occurrences found, break the loop
            break;
        }
    }
    
    match[count] = -1;
}


void print(const char arr[]) {
    cout << arr <<endl;
}


void print(const int match[]) {
    if (match[0] == -1) {
        cout << "None" << endl;
        return;
    }
    
    int i = 0;
    // Iterate until reaching the sentinel value -1
    while (match[i] != -1) {
        cout << match[i++];
        if (match[i] != -1) // If there is another match, print a newline
            cout << endl;
    }
    cout << endl;
}