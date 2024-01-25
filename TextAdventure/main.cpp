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
    bool hasKey = false;
    bool isLocked = true;
    string input;
    string orientation = "F"; //Can be F, B, L or R
    Object Lvl_0_key = {"key", "a small iron key.", 0};

    
    cout << " This is a text based adventure game!.\n If you have never played this kind of game before, type 'help' to get an explanation.\n" << endl;
    cout << "You wake up in a cell with no idea how you got there.\n";
    
    while(gameRunning) {
        getline(cin,input);
        if (location == 0) {
                if ((input == "look" || input == "look around") && orientation != "B") {
                    cout << "You are in a small, dank cell with a rusted iron door.\n";
                }
                else if (input == "open door" && hasKey == false) {
                    cout << "The door is locked.\n";
                }
                else if (input == "open door" && hasKey == true) {
                    cout << "Try using the key first.\n";
                }
                else if (input == "open door" && isLocked == false) {
                    cout << "The rusty door creaks open. What do you do now?\n";
                }
               else if (input == "use key" && hasKey == false) {
                    cout << "You don't have a key.\n";
                }
               else if (input == "use key" && hasKey == true) {
                   isLocked = false;
                    cout << "The door unlocked!.\n";
                }
                else if (input == "escape" && isLocked == false) {
                    cout << "You can't escape from here without finding a way to open the door.\n";
                }
                else if (input == "turn left") {
                    orientation = "L";
                    cout << "You turn left to face a wall.\n";
                }
                else if (input == "turn right") {
                    orientation = "R";
                    cout << "You turn right to face a wall.\n";
                }
                else if (input == "turn around") {
                    orientation = "B";
                    cout << "You spot a rusty key on the ground. No way they left you the key to your own cell?\n";
                }
                else if (input == "help") {
                     cout << "Text adventures (sometimes synonymously referred to as interactive fiction) are text-based games wherein worlds are described in the narrative and the player submits typically simple commands to interact with the worlds. The object of this game is to break out of a mysterious prison, where anything could happen :). Type all commands in LOWERCASE and you'll never need more than one or two word commands.\n";
                }
                else if (input == "turn around") {
                    orientation = "B";
                    cout << "You spot a rusty key on the ground. No way they left you the key to your own cell?\n";
                }
                else if (orientation == "B" && (input == "grab" || input == "take" || input == "pick up")) {
                    hasKey = true;
                    cout << "You pick up " << Lvl_0_key.description << endl;
                }
                else {
                     cout << "I don't understand that command.\n";
                }
            }
        if (location == 1){ // player is in the cell
        Level1(); // call level 1 function
        }
    }
}

