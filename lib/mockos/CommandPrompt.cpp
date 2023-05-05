/*
* Lab 5
* File: CommandPrompt.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions for the CommandPrompt.
*/

#include "mockos/CommandPrompt.h"
#include <iostream>
#include <sstream>
#include "mockos/enums.h"

using namespace std;

CommandPrompt::CommandPrompt() {
    fileSys = nullptr;
    fileFact = nullptr;
}

void CommandPrompt:: setFileSystem(AbstractFileSystem *  afsPtr){ //sets the member file system equal to the one passed in
    fileSys = afsPtr;
}

void CommandPrompt:: setFileFactory(AbstractFileFactory * affPtr){ //sets the member file factory equal to the one passed in
    fileFact = affPtr;
}

int CommandPrompt:: addCommand(std::string command, AbstractCommand* acPtr){ //adds a command as a pair into the map
    if(commands.insert({command, acPtr}).second == true){
        return returns::SUCCESS;
    }
    else{
        return returns::COMMAND_INSERT_FAIL;
    }
}

void CommandPrompt:: listCommands(){ //displays the list of commands
    for (const auto& command : commands) {
        std::cout << command.first << std::endl;
    }
}

string CommandPrompt:: prompt(){ //prompts the user for input, listing available options
    string input;
    cout << "Please enter a valid command, 'q' to quit, 'help' \n"
            "for a list of commands, or 'help <command name>' for details about a specific command name."<< endl;
    cout<< endl;
    fflush(stdin);
    while(input == "") {
        cout<< "$  " << flush; 
        getline(cin >> ws, input); //takes in the user's input
    }
    return input;
}

int CommandPrompt:: run(){ //repeatedly calls prompt() to continue asking the user for input until they quit
    bool done = false;
    while(done == false) {
        string input = prompt();
        istringstream iss(input);
        if (input == "q") {
            return returns::QUIT; 
        } 
        else if (input == "help") {
            listCommands();
        }
        else {
            bool space = false;
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == ' ') {
                    space = true;
                }
            }
            if (space == false) {
                if (commands.find(input) != commands.end()) {
                    if (commands.find(input)->second->execute("") != 0) { //given command did not properly run
                        cout << "Command failed " << endl;
                    }
                }
                else {
                    cout << "Command does not exist" << endl; //given command does not exist
                }
            }
            else {
                istringstream iss(input); //runs commands with multiple words
                string word1;
                iss >> word1;
                if (word1 == "help") {
                    string word2;
                    iss >> word2;
                    if (commands.find(word2) != commands.end()) { //displays usage info for a command if it exists
                        commands.find(word2)->second->displayInfo();
                  
                    }
                    else {
                        cout << "Command does not exist" << endl;
                    }
                }
                else {
                    if (commands.find(word1) != commands.end()) {
                        string remString;
                        getline(iss, remString);
                        while (remString[0] == ' ') {
                            remString.erase(remString.begin());
                        }

                        if (commands.find(word1)->second->execute(remString) != 0) {
                            cout << "Command failed" << endl;
                        }
                    }
                    else {
                        cout << "Command does not exist" << endl;
                    }
                }
            }
        }
    }
}

