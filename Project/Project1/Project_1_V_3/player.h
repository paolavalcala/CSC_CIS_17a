
/* 
 * File:   player.h
 * Author: paolaalcala
 *
 * Created on November 9, 2024, 8:36 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>   // For std::string
#include <vector>   // For std::vector
#include <iostream> // For std::cout


struct Player{
    int id;// number of player // dynamically register 
    //number of players and register as id for each player example: player 1, player 2
    std::string name; //name of player
    std::vector<std::string> hand; // Player's hand of cards
    //int *wins; //dynamically register wins utilizing pointer
    
    // Function to initialize player attributes
    void initialize(int playerId, const std::string& playerName) {
        id = playerId;
        name = playerName;
        std::cout << "Initialized Player: ID = " << id << ", Name = " << name << std::endl;
    }

    // Function to display the player's hand with commas between cards
    void displayHand() const {
        std::cout << name << "'s hand: ";
        for (size_t i = 0; i < hand.size(); ++i) {
            std::cout << hand[i];
            if (i < hand.size() - 1) { // Add comma except after the last card
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};


#endif /* PLAYER_H */
