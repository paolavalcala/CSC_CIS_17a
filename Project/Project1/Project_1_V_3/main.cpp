
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on November 9, 2024, 8:36 PM
 * Purpose: Project 1 Version 3
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <fstream> //File operations
#include <sstream> // string stream for parsing
#include <vector> //vector for dynamic array storage
#include <cstring>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For seeding random number generator

#include "player.h"

using namespace std;


//Functions

// Functions to initialize the Players
Player* getPlyrs(int& numPlayers);
void intlzePlyr(Player& player, int playerId, const string& playerName);

//function to shuffle the deck 
void shuffleDeck(string deck[4][13]);

//function to save shuffled deck to a new file
void saveShuffled(const string deck[4][13], const string& filename);

//functions to deal cards
// Convert 2D deck to 1D vector for the center pile
vector<string> createPile(string deck[4][13]);

void dealCards(vector<string>& centerPile, Player* players, int numPlayers, int cardsPerPlayer);


int main(int argc, char** argv) {
    
    //declare variables
    fstream deckFile;
    const int ROWS = 4;
    const int COLS = 13;
    string data[ROWS][COLS];
    string line;
    
    //check to see if file exists
    //open file  
    deckFile.open("deck.txt", ios::in);
    if (!deckFile) {
        cout << "The file deck.txt does not exist." << endl;
        return 1; // Exit program if file does not exist
    }
    
    for (int row = 0; row < ROWS && getline(deckFile, line); row++){
        stringstream ss(line);
        string card;
        int col = 0;
        
        while(getline(ss, card, ',') && col < COLS){
            //remove leading white space if any
            if (card[0] == ' '){
                card.erase(0, 1);
            }
            data[row][col++] = card;
        }
        
    }
    
    //close the file after reading
    deckFile.close();
    
    //display the original deck
    cout << "Here is your deck of cards: " << endl;
    cout << endl;
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            cout << data[row][col];
            if (col < COLS - 1) cout << ", "; //add comma
        }
        cout << endl;
    }
    
    cout << endl;
   
    
    //shuffle the deck 
    shuffleDeck(data);
    
    
    // Display the shuffled deck
    cout << "Here is your shuffled deck of cards: " << endl;
    cout << endl;
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            cout << data[row][col];
            if (col < COLS - 1) cout << ", "; // Add comma
        }
        cout << endl;
    }
    
    cout << endl;
    
    // Save the shuffled deck to a file
    saveShuffled(data, "shuffled_deck.txt");
    cout << endl;
    
    
    // player data
    int numPlayers;
    
    // Initialize players
    Player* players = getPlyrs(numPlayers);
    if (!players) {
        cout << "Failed to initialize players due to invalid input." << endl;
        return 1;
    }

    // Welcome Players
    cout << "Welcome Players!" << endl;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Player " << players[i].id << ": " << players[i].name << endl;
    }
    cout << endl;

    
    // Convert to center pile
    vector<string> centerPile = createPile(data);

    // Deal cards to players
    int cardsPerPlayer = 5; // Adjust based on game rules
    dealCards(centerPile, players, numPlayers, cardsPerPlayer);

    // Display each player's hand
    cout << "Players' Hands After Dealing:" << endl;
    for (int i = 0; i < numPlayers; ++i) {
        players[i].displayHand();
    }
    cout << endl;

    // Remaining cards are in the center pile
    cout << "Cards remaining in the center pile: " << centerPile.size() << endl;
    
    // Deallocate the dynamic array
    delete[] players;
    
    return 0;
}

// Function to initialize the Player

Player* getPlyrs(int& numPlayers) {
    cout << "Ready to play Go Fish?" << endl;
    cout << endl;
    cout << "You will need 2 - 5 players to play." << endl;
    cout << endl;
    cout << "Enter the number of players: ";
    cin >> numPlayers;
    
    cout << endl;

    // Validate the number of players
    if (numPlayers < 2 || numPlayers > 5) {
        cout << "Invalid number of players. Please enter between 2 and 5." << endl;
        return nullptr;  // Return nullptr if input is invalid
    }

    // Dynamically allocate an array of Players
    Player* players = new Player[numPlayers];

    // Initialize each player
    for (int i = 0; i < numPlayers; ++i) {
        string playerName;
        cout << "Enter name for Player " << (i + 1) << ": ";
        cin >> playerName;
        intlzePlyr(players[i], i + 1, playerName);
    }

    return players;  // Return the pointer to the dynamically allocated array
}

void intlzePlyr(Player& player, int playerId, const std::string& playerName) {
    player.initialize(playerId, playerName);
    player.id = playerId;
    player.name = playerName;
    //player.wins = new int(0);  // Allocate memory and initialize wins to 0
    
    cout << "Player: " << player.id << " " <<  player.name << endl;
    cout << endl;
}


// Function to shuffle the deck of cards
void shuffleDeck(string deck[4][13]) {
    srand(time(0)); // Seed the random number generator
    const int ROWS = 4;
    const int COLS = 13;
    
    for (int i = 0; i < ROWS * COLS; ++i) {
        int row1 = rand() % ROWS;
        int col1 = rand() % COLS;
        int row2 = rand() % ROWS;
        int col2 = rand() % COLS;
        
        // Swap the two cards
        swap(deck[row1][col1], deck[row2][col2]);
    }
}


void saveShuffled(const string deck[4][13], const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file to save the shuffled deck." << endl;
        return;
    }

    // Write the shuffled deck to the file
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 13; ++col) {
            outFile << deck[row][col];
            if (col < 12) outFile << ", "; // Add comma between cards
        }
        outFile << endl; // New line after each suit (row)
    }

    outFile.close();
    cout << "Shuffled deck saved to " << filename << endl;
}

// Convert 2D deck to 1D vector for the center pile
vector<string> createPile(string deck[4][13]) {
    vector<string> centerPile;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 13; ++col) {
            centerPile.push_back(deck[row][col]);
        }
    }
    return centerPile;
}

void dealCards(vector<string>& centerPile, Player* players, int numPlayers, int cardsPerPlayer) {
    for (int i = 0; i < numPlayers; ++i) {
        // Assume each Player has a vector<string> hand to hold dealt cards
        for (int j = 0; j < cardsPerPlayer && !centerPile.empty(); ++j) {
            players[i].hand.push_back(centerPile.back());  // Deal from the back of the pile
            centerPile.pop_back();  // Remove dealt card from the center pile
        }
    }
}




/* 
 Version 3
 In this version I will be splitting the deck between players.
 The rest of the cards will be held in a center pile.
 I just have a few questions? Is it more productive to set 
 the center pile varaible first that holds the data from 
 the shuffled deck. Then I would deal the cards to each player
 with a function. 
 
 First I will be creating a data structure to hold the shuffled
 deck to represent the center pile. The center pile will hold
 cards initially and then have them removed as dealt to players.
 * 

 2nd implement a function to deal cards to each player.
 This function would take the shuffled deck as input
 Then remove cards from the center pile and assign them
 to each player's hand.
 */
