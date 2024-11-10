/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on Oct 29, 2024, 12:44 PM
 * Purpose: Midterm Question 4
 */

//System Libraries
#include <iostream> //Input-Output Library 
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 
void getData(int &data);
int encryptData(int data);
int decryptData(int encrptdData);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    int data;
    int choice; //user choice of either encrypted or decrypted option
    
    //ask user if they want to encrypt or decrypt before 
    //getting the data
    cout << "Hi! What would you like to do?:\n";
    cout << "1. Encrypt data\n";
    cout << "2. Decrypt data\n";
    cout << "3. Both encrypt and decrypt" << endl;
    cout << "Enter your choice (1, 2, 3): " << endl;
    cin >> choice;
    
    
    getData(data);
    
  
    if (choice == 1){
        //encrypted data option
        int encrptdData = encryptData(data);
        cout << "Encrypted data: " << encrptdData << endl;
    } 
    else if (choice == 2){     
        //decrypted data option 
        cout  << "Decrypted data: " << data << endl;
    } 
    else if (choice == 3){
        int encrptdData = encryptData(data);
        cout << "Encrypted data: " << encrptdData << endl;
        int decryptedData = decryptData(encrptdData);
        cout << "Decrypted data: " << decryptedData << endl;
    }
    else{
        cout << "Invalid choice! Please restart the program and select a valid option." << endl;
    }
    
    //Exit the program
    return 0;
}

//function to get the four digit integer data 
void getData(int &data){
    cout << "Enter a four-digit integer (digits must be between 0 and 7): ";
    cin >> data;
    
    while (data < 0 || data > 7777){
        cout << "Invalid input! Please enter a four-digit integer between 0 and 7: ";
        cin >> data;
    }
}

int encryptData(int data){
    int digits[4];
    
    // Separate each digit and store it in the array
    for (int i = 3; i >= 0; i--) {
        digits[i] = data % 10;
        data /= 10;
    }
    
    // read and encrypt each digit
    //encrypt: replace each digit by the sum of the digit 
    //plus 6 modulus 8
    for (int i = 0; i < 4; i++){
        digits[i] = (digits[i] + 6) % 8;
    }
    
    //then swap the first digit with the third and swap the 
    //second digit with the fourth
    swap(digits[0], digits[2]);
    swap (digits[1], digits[3]);

    // Recombine the array into a single integer
    int encrptdData = 0;
    for (int i = 0; i < 4; i++) {
        encrptdData = encrptdData * 10 + digits[i];
    }
    
    return encrptdData;

}


int decryptData(int encrptdData){
    
    int digits[4];
    
    // Separate each digit and store it in the array
    for (int i = 3; i >= 0; i--) {
        digits[i] = encrptdData % 10;
        encrptdData /= 10;
    }
    
    //then swap the first digit with the third and swap the 
    //second digit with the fourth
    swap(digits[0], digits[2]);
    swap (digits[1], digits[3]);
    
    //decrypt each digit 
    for (int i = 0; i < 4; i++){
        digits[i] = (digits[i] - 6 + 8) % 8;
    }
    
    //recombine the array into a single integer
    
    int decrypted = 0;
    for (int i = 0; i < 4; i++){
        decrypted = decrypted * 10 + digits[i];
    }
    
    return decrypted;
}