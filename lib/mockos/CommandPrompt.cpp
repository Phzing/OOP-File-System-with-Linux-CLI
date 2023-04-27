#include "mockos/CommandPrompt.h"
#include <iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() {
    fileSys = nullptr;
    fileFact = nullptr;
}

void CommandPrompt:: setFileSystem(AbstractFileSystem *  afsPtr){
    fileSys = afsPtr;
}

void CommandPrompt:: setFileFactory(AbstractFileFactory * affPtr){
    fileFact = affPtr;
}

int CommandPrompt:: addCommand(std::string command, AbstractCommand* acPtr){
    if(commands.insert({command, acPtr}).second == true){
        return 0; //fix hardcode success
    }
    else{
        return -1; //fix hardcode new int needed instead of -1 (failed command insertion)
    }
}

void CommandPrompt:: listCommands(){
    for (const auto& command : commands) {
        std::cout << command.first << std::endl;
    }
}

string CommandPrompt:: prompt(){
    string input;
    cout << "Please enter a valid command, 'q' to quit, 'help' \n"
            "for a list of commands, 'help <command name>' for details about a specific command name"<< endl;
    cout<< endl;
    cout<< "$  ";
    getline(cin, input);
    return input;
}

int CommandPrompt:: run(){
    bool done = false;
    while(done == false) {
        string input = prompt();
        istringstream iss(input);
        if (input == "q") {
            return -1; //fix hardcode new int needed instead of -1 (quit)
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
                    if (commands.find(input)->second->execute("") != 0) {
                        cout << "Command failed " << endl;
                    }
                }
                else {
                    cout << "Command does not exist" << endl;
                }
            }
            else {
                istringstream iss(input);
                string word1;
                iss >> word1;
                if (word1 == "help") {
                    string word2;
                    iss >> word2;
                    if (commands.find(word2) != commands.end()) {
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

