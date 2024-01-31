//
//  main.cpp
//  TextAdventure
//
//  Created by Kole Peoples on 1/23/24.
//

#include <iostream>
#include "Monsters.h"
using namespace std;

struct Object{
string name;
string description;
int location;
};

string answerRiddle(string riddle) {
    
    return 0;
}

void Level1(string input) {
    
    Monster Dracula{"Sphinx","What gets bigger the more you take away?","A hole",1};
    string level1Input = input;

    if (level1Input == "look" || level1Input == "Look" || level1Input == "look around" || level1Input == "Look around") {
         cout << "You are in a spacious room. To your left is a massive hole, you cannot tell how deep it is.\n To your right is a door. Probably the exit. Between you and this door is an unassuming man.\n";
    }
    
    else if (level1Input == "speak") {
        cout << "Hello. I am Vlad Tepes. Answer my riddle or be thrown into that hole\n";
        cout << Dracula.riddle << endl;
        answerRiddle(Dracula.riddle);
    }
    
    else if (level1Input == "help") {
         cout << "Congrats on making it out of the cell! You're on your own from now on, but your freedom is in reach! If you're stuck, try using your 5 senses! Keep your wits about you and good luck! Don't forget: Type all commands in LOWERCASE. You will never need more than one or two word commands.\n";
    }
}

void Level2() {
    string level2Input;
    if (level2Input == "look" || level2Input == "Look" || level2Input == "look around" || level2Input == "Look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
    
    else if (level2Input == "help") {
         cout << "Type all commands in LOWERCASE. You will never need more than one or two word commands.\n";
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
                    cout << "You are in a small, dank cell with a rusted iron door. A candle burns in a mounted medieval sconce above the door, your only source of light. It is just out of reach.\n";
                }
                else if (input == "smell" || input == "sniff") {
                    cout << "It smells like feet (Hopefully not yours).\n";
                }
                else if (input == "hear" || input == "listen") {
                    cout << "You listen for guards or other prisoners. You are met with eerie silence.\n";
                }
                else if (input == "touch" || input == "feel") {
                    cout << "You touch everything you can see in front of you. You gain no information from this.\n";
                }
                else if (input == "taste" || input == "lick") {
                    cout << "You... lick everything in front of you? Surely your health will suffer from this. Nasty.\n";
                }
            
            //Door logic
                else if (input == "open door" && hasKey == false) {
                    cout << "The door is locked.\n";
                }
                else if (input == "open door" && hasKey == true && isLocked == true) {
                    cout << "Try using the key first.\n";
                }
                else if (input == "open door" && isLocked == false) {
                    cout << "The rusty door creaks open. What do you do now?\n";
                }
            
            //Key Logic
               else if (input == "use key" && hasKey == false) {
                    cout << "You don't have a key.\n";
                }
               else if (input == "use key" && hasKey == true) {
                   isLocked = false;
                   cout << "The door unlocked!\n";
                }
            
            //Escape Logic
                else if (input == "escape" && isLocked == true) {
                    cout << "You can't escape from here without finding a way to open the door.\n";
                }
                else if ((input == "escape" || input == "leave") && isLocked == false) {
                    cout << "You escape your cell! It's still baffling that the key was inside the cell...\nBut you press on anyway!\n";
                    cout << "After escaping your cell, you climbed a flight of stairs that led you into a large room.\n";
                    location = 1;
                }
            
            //Orientation Logic
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
                else if (input == "turn around") {
                    orientation = "B";
                    cout << "You spot a rusty key on the ground. There is no way they left you the key to your own cell... right?\n";
                }
            
            //Take Logic
                else if (orientation == "B" && (input == "grab" || input == "take" || input == "pick up")) {
                    hasKey = true;
                    cout << "You pick up " << Lvl_0_key.description << endl;
                }
            
            //Help
                else if (input == "help") {
                     cout << "Text adventures (sometimes synonymously referred to as interactive fiction) are text-based games wherein worlds are described in the narrative and the player submits typically simple commands to interact with the worlds. The object of this game is to break out of a mysterious prison, where anything could happen :). Type all commands in LOWERCASE. You will never need more than one or two-word commands.\n";
                }
                else {
                     cout << "I don't understand that command.\n";
                }
            }
        if (location == 1){ // player is in the cell
        Level1(input); // call level 1 function
        }
    }
}

