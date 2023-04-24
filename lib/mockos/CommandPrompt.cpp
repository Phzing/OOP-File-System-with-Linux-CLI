#include "mockos/CommandPrompt.h"
#include <iostream>

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
        std::cout << command.second<< ": " << command.first << std::endl;
    }
}

string CommandPrompt:: prompt(){
    string input;
    cout << "Please enter a valid command, 'q' to quit, 'help' \n"
            "for a list of commands, 'help <command name>' for details about a specific command name"<< endl;
    cout<< endl;
    cout<< "$  ";
    cin>>input;
    //coded wrong, need to use getline method
    return input;
}

int CommandPrompt:: run(){
    bool done = false;
    while(done == false){
        string input = prompt();
        if(input == "q"){
            return -1; //fix hardcode new int needed instead of -1 (quit)
        }
        else if(input == "help"){
            listCommands();
        }
        else if(input == ""){

        }
    }
}
