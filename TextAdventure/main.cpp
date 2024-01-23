//
//  main.cpp
//  TextAdventure
//
//  Created by Kole Peoples on 1/23/24.
//

#include <iostream>
using namespace std;

struct Object{
string name;
string description;
int location;
};

void Level1() {
    string level1Input;
    if (level1Input == "look" || level1Input == "Look" || level1Input == "look around" || level1Input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
}

void Level2() {
    string level2Input;
    if (level2Input == "look" || level2Input == "Look" || level2Input == "look around" || level2Input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
}

void Level3() {
    string input;
    if (input == "look" || input == "Look" || input == "look around" || input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
}

void Level4() {
    string input;
    if (input == "look" || input == "Look" || input == "look around" || input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
}

void Level5() {
    string input;
    if (input == "look" || input == "Look" || input == "look around" || input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
}

int main() {
    
    int location = 0;
    bool  gameRunning = true;
    string input;
    string orientation = "F"; //Can be F, B, L or R
    Object key = {"key", "A small iron key.", 2};

    
    cout << "This is a text based adventure game! If you have never played this kind of game before, type 'help' to get an explanation";
    
    while(gameRunning) {
        cin >> input;
        if (location == 0) {
                if ((input == "look" || input == "Look" || input == "look around" || input == "Look around") && orientation != "B") {
                     cout << "You are in a small, dank cell with a rusted iron door.\n";
                }
                else if (input == "open door") {
                     cout << "The door is locked.\n";
                }
                else if (input == "use key") {
                     cout << "You don't have a key.\n";
                }
                else if (input == "escape") {
                     cout << "You can't escape from here without finding a way to open the door.\n";
                }
                else if (input == "turn left" || input == "Turn Left") {
                    orientation = "L";
                    cout << "You turn left to face a wall.\n";
                }
                else if (input == "escape") {
                     cout << "You can't escape from here without finding a way to open the door.\n";
                }
                else{
                     cout << "I don't understand that command.\n";
                }
            }
        if (location == 1){ // player is in the cell
        Level1(); // call level 1 function
        }
    }
}

