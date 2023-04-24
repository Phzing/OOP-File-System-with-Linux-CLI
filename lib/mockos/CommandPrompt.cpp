#include "mockos/CommandPrompt.h"

using namespace std;

CommandPrompt::CommandPrompt() {
    fileSys = nullptr;
    fileFact = nullptr;
}

void CommandPrompt:: setFileSystem(AbstractFileSystem *  afsPtr){

}

void CommandPrompt:: setFileFactory(AbstractFileFactory * affPtr){

}

int CommandPrompt:: addCommand(std::string command, AbstractCommand* acPtr){

}

void CommandPrompt:: listCommands(){

}

string CommandPrompt:: prompt(){

}

int CommandPrompt:: run(){

}
