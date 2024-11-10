

/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on November 9, 2024, 10:24 PM
 * Purpose: Project 1 Version 4
 */

//System Libraries
#include <iostream> //Input-Output Library 
#include <fstream> //File operations
#include <sstream> // string stream for parsing
#include <vector> //vector for dynamic array storage
#include <cstring>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For seeding random number generator
#include <set>

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

//functions to find matches
void findMatches(Player* players, int numPlayers);

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
    int cardsPerPlayer = 7; // Adjust based on game rules
    dealCards(centerPile, players, numPlayers, cardsPerPlayer);

    // Display each player's hand
    cout << "Players' Hands After Dealing:" << endl;
    for (int i = 0; i < numPlayers; ++i) {
        players[i].displayHand();
    }
    cout << endl;
    
    // Find matches and display scores
    findMatches(players, numPlayers);
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


void findMatches(Player* players, int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        Player& player = players[i];
        set<string> matchedRanks; // Track ranks already counted as matches

        // Iterate over each card in the hand
        for (size_t j = 0; j < player.hand.size(); ++j) {
            string rank1 = player.hand[j].substr(0, player.hand[j].find(" ")); // Extract the rank
            cout << "Checking card: " << player.hand[j] << " with rank: " << rank1 << endl; // Debug

            // Compare with other cards in the hand
            for (size_t k = j + 1; k < player.hand.size(); ++k) {
                string rank2 = player.hand[k].substr(0, player.hand[k].find(" "));

                // Check if ranks match and if this rank hasn't been matched before
                if (rank1 == rank2 && matchedRanks.find(rank1) == matchedRanks.end()) {
                    //cout << "Match found: " << player.hand[j] << " and " << player.hand[k] << endl; // Debug
                    player.matches.push_back(player.hand[j]);
                    player.matches.push_back(player.hand[k]);
                    player.score++; // Increase score for each unique match
                    matchedRanks.insert(rank1); // Mark rank as matched
                    break; // Avoid counting duplicate matches for this rank
                }
            }
        }
        cout << endl;
        
        cout << player.name << "'s Matches: ";
        for (size_t m = 0; m < player.matches.size(); ++m) {
            cout << player.matches[m];
            if (m < player.matches.size() - 1) {
                cout << ", "; // Add comma between matches, except after the last one
            }
        }
        cout << endl;

        player.displayScore();
    }
}




/* 
 Version 4
 In this version I will be working on comparing the cards in 
 each players hand to search for matches.
 Compare the first word(rank) of the card to each other
 for example Ace of spades and ace of diamonds
 looking to see if ace === ace
 
 function to find matches
 * 
 vaiable to hold cards that have matches for each player
 keep score of each match 
 * 
 *
 * 
 
 */