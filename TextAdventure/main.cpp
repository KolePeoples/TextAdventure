//
//  main.cpp
//  TextAdventure
//
//  Created by Kole Peoples on 1/23/24.
//

#include <iostream>
#include <cctype>
#include "Monsters.h"
using namespace std;

struct Object{
string name;
string description;
int location;
};

bool answerRiddle(Monster monster) {
    string Answer;
    
    cout << "\"" << monster.riddle << "\"" << endl;
    
    cout << "Enter your answer:";
    getline(cin, Answer);
    
    if(Answer == monster.answer) {
        return true;
    }
        
    else {
        return false;
    }
}

int Level1(string input, int location) {
    int currentLoc = location;
    string answer;
    string level_1_Input = input;
    Monster Dracula{"Dracula","What gets bigger the more you take away?","a hole",1};
    
    
    //Level 1 Discovery Logic
    if (level_1_Input == "look" || level_1_Input == "look around") {
         cout << "You are in a spacious room. To your left is a massive hole, you cannot tell how deep it is.\nTo your right is a door. Probably the exit. Between you and this door is a tall, thin, pale,\nwhite-haired man with a long mustache.\n";
    }
    
    else if (level_1_Input == "hear" || level_1_Input == "listen") {
        cout << "You hear the faint breathing of another living being.\n";
    }
    
    else if (level_1_Input == "smell" || level_1_Input == "sniff") {
         cout << "You catch a faint metallic smell.\n";
    }
    
    else if (input == "touch" || input == "feel") {
        cout << "There wasn't anything in reach.\n";
    }
    
    else if (input == "taste" || input == "lick") {
        cout << "There is nothing to taste or lick.\n";
    }
    
    else if (level_1_Input == "speak") {
        cout << "\"Hello. I am Vlad Tepes. Answer my riddle or be thrown into that hole!\"\n";
        
            if(answerRiddle(Dracula) == 1) {
                cout << "\"I have unlocked the door for you. Leave quickly before I become thirsty!\"\n";
                cout << "You escape the room without a second thought. Eager to avoid becomming Dracula's next meal...\n";
                cout << "The door lead to a dark hallway. There's no chance you turn around to face Dracula again,\nso you venture forward into the darknees.\n";
                cout << "After sometime you spot what looks like a crack of light from under a door.\nYou are confused by what is on the other side.\n";
                currentLoc++;
                return currentLoc;
            }
            else {
                cout << "\"Now you DIE...\"\n";
                return 0;
            }
    }
    
    //Help
    else if (level_1_Input == "help") {
         cout << "Congrats on making it out of the cell!\nYou're on your own from now on, but your freedom is in reach!\nIf you're stuck, try using your 5 senses!\nKeep your wits about you and good luck!\nDon't forget: Type all commands in LOWERCASE.\nYou will never need more than one or two word commands.\n";
    }
    
    else {
         cout << "I don't understand that command.\n";
    }
    return currentLoc;
}

int Level2(string input, int location) {
    
    int currentLoc = location;
    string level_2_Input = input;
    static bool sphinxArrive = false;
    static bool solved = false;
    Monster Sphinx {"Sphinx", "What runs, but never walks. Murmurs, but never talks. Has a bed, but never sleeps.\nAnd has a mouth, but never eats?", "a river",2};
    
    //Discovery Logic
    if (level_2_Input == "look" || level_2_Input == "look around") {
            cout << "You are in...\nA garden?? How are plants able to thrive here with no sunlight?.\n";
            cout << "There are several beautiful flowers and other flora about.\nStopping to smell the roses doesn't seem like a bad idea at the moment\n";
    }
    
    else if (level_2_Input == "hear" || level_2_Input == "listen") {
        cout << "It sounded... like a garden\n";
    }
    
    else if (level_2_Input == "take" || level_2_Input == "pick" || level_2_Input == "pick flower" || level_2_Input == "smell plant" || level_2_Input == "smell flower" || level_2_Input == "lick" || level_2_Input == "taste" || level_2_Input == "smell") {
        cout << "A terrifying voice booms: \"WHO DARES DISTURB MY GARDEN??\"\n";
        cout << "A massive winged lion with the head of a deformed man materializes across the room.\n";
        sphinxArrive = true;
    }
    
    else if (sphinxArrive == true && (level_2_Input == "speak" || level_2_Input == "talk" || level_2_Input == "apologize")) {
        cout << "\"Solve my riddle or die for your transgresstion.\"\n";
        
        if(answerRiddle(Sphinx) == 1) {
            cout << "\"Good! Take that flower with you. I don't want it here now that you've contaminated it.\"\n";
            cout << "\"Now close your eyes.\"\n";
            solved = true;
        }
        else {
            cout << "\"Wrong! Now you DIE!\"\n";
            return 0;
        }
    }
    
    else if ((level_2_Input == "close eyes") && solved == true) {
        cout << "You closed your eyes.\n";
        cout << "Upon opening your eyes again, you realize you are in a different location.\n";
        currentLoc++;
        return currentLoc;
    }
    
    else if ((level_2_Input == "speak" || level_2_Input == "talk") && sphinxArrive != true) {
        cout << "There was nobody to talk to.\n";
    }
    
    else if (level_2_Input == "help") {
         cout << "Type all commands in LOWERCASE. You will never need more than one or two word commands.\n";
    }
    
    else {
         cout << "I don't understand that command.\n";
    }
    return currentLoc;
}

int Level3(string input, int location) {
    
    string level_3_Input = input;
    int currentLoc = location;
    static int depth = 0;
    static int lickCount = 0;
    bool hasDisease = false;
    
    Monster Troll{"Troll","Me stronger than steel, but me full of holes. What it is?","a chain",3};
    
    //Exploration Logic
    if (level_3_Input == "look" || level_3_Input == "look around") {
        
        if (depth == 0) {
            cout << "You're in a humid cave. Dark red crystals illuminate your surrondings with an eerie crimson glow.\n";
        }
        
        else if (depth == 1) {
            cout << "The crimson light from the crystals has become a distant glow behind you.\nIt's much harder to see.\nNot like there is much to see in a cave anyway.\n";
        }
        
        else if (depth == 2) {
            cout << "You can't see your own hand in front of you face.\nYou'll have to rely on other senses.\n";
        }
    }
    
    else if (level_3_Input == "hear" || level_3_Input == "listen") {
        
        if (depth == 0) {
            cout << "The silence is deafening. You must be deep underground.\nOccassionally, you hear water dripping from stalactites.\n";
        }
        
        else if (depth == 1) {
            cout << "There is a faint grumling coming frm deeper in the cave...\n";
        }
        
        else if (depth == 2) {
            cout << "It almost sounds like someone is snoring.\n";
        }
    }
    
    else if (level_3_Input == "smell" || level_3_Input == "sniff") {
        
        if (depth == 0) {
            cout << "It smells sour and musty. Like someone spoiled milk and then ran a marathon with it in their shoes.\n";
        }
        
        else if (depth == 1) {
            cout << "The smell is getting stronger...\n";
        }
        
        else if (depth == 2) {
            cout << "Your nose is burning, the source of the smell is right in front of you.\n";
        }
    }
    
    else if (level_3_Input == "lick" || level_3_Input == "taste") {
        
        if (lickCount == 0) {
            cout << "You really shouldn't...\n";
            lickCount++;
            cout << lickCount << endl;
        }
        
        else if (lickCount == 1) {
            cout << "You... Lick and taste everything you can get your nasty tongue on... Sicko\n";
            lickCount++;
            cout << lickCount << endl;
        }
        
        else if (lickCount == 2) {
            cout << "Why are you still licking things!? Whatever. You have hepatitus now.\n";
            hasDisease = true;
            lickCount++;
            cout << lickCount << endl;
        }
        
        else if (lickCount > 2) {
            lickCount++;
            cout << "You have " << lickCount <<" stacks of hepatitus.\n";
            cout << lickCount << endl;
        }
        
    }
    
    else if (level_3_Input == "talk" || level_3_Input == "speak") {
        
    }
    
    else if (level_3_Input == "touch" || level_3_Input == "poke" || level_3_Input == "feel") {
        
    }
    
   //Cave Expolration Logic
    else if (level_3_Input == "go further" || level_3_Input == "go deeper" || level_3_Input == "spelunk"|| level_3_Input == "explore cave" || level_3_Input == "explore") {
        depth++;
        cout << "You venture deeper into the cave, the smell is getting stronger...\n";
    }
         

        /*
         and the smell is overpowering now. Your nose feels like it's about to fall off.\nJust when you cant take anymore, you bump into a spongy wall
         */
    
    else if (level_3_Input == "help") {
         cout << "Type all commands in LOWERCASE. You will never need more than one or two word commands.\n";
    }
    
    else {
         cout << "I don't understand that command.\n";
    }
    
    return currentLoc;
}

int Level4(string input, int location) {
    
    string level_4_input = input;
    bool hasFlower = true;
    int currentLoc = location;
    Monster Leshen{"Leshen","I am not like the others. I have no riddle. Instead, I seek treasure","",4};
    
    if (input == "look" || input == "look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
    
    return currentLoc;
}

int Level5(string input, int location) {
    
    string level_5_input = input;
    int currentLoc = location;
    
    if (input == "look" || input == "look around") {
         cout << "You are in a small, dank cell with a rusted iron door.\n";
    }
    
    return currentLoc;
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
        
        for (char &c : input) { //Makes input lowercase
            c = tolower(c);
        }
        
        if (location == 0) {
            
                if ((input == "look" || input == "look around") && orientation != "B") {
                    cout << "You are in a small, dank cell with a rusted iron door. A candle burns in a mounted medieval sconce\nabove the door, your only source of light. It is just out of reach.\n";
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
                   orientation = "F";
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
                    cout << "You spot a rusty key on the ground. There's no way they left you the key to your own cell... right?\n";
                }
            
            //Take Logic
                else if (orientation == "B" && (input == "grab" || input == "take" || input == "pick up")) {
                    hasKey = true;
                    cout << "You pick up " << Lvl_0_key.description << endl;
                }
            
            //Help
                else if (input == "help") {
                     cout << "Text adventures (sometimes synonymously referred to as interactive fiction) are text-based games\nwherein worlds are described in the narrative and the player submits typically simple commands to\ninteract with the worlds. The object of this game is to break out of a mysterious prison, where\nanything could happen :). Type all commands in LOWERCASE. You will never need more than one or\ntwo-word commands.\n";
                }
                else {
                     cout << "I don't understand that command.\n";
                }
            }
        else if (location == 1){ // player is in the out of the cell
            location = Level1(input, location);// call level 1 function
        }
        else if(location == 2) {
            location = Level2(input, location);
        }
        else if(location == 3) {
            location = Level3(input, location);
        }
        else if(location == 4) {
            location = Level4(input, location);
        }
        else if(location == 5) {
            location = Level5(input, location);
        }
    }
}

