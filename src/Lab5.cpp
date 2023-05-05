#include <iostream>
#include <string>
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TouchCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/TouchPlusCatParsingStrategy.h"
#include "mockos/AggregateStatsCommand.h"

using namespace std;

int main(int argc, char* argv[]) {
    SimpleFileSystem fileSystem;
    SimpleFileFactory fileFactory;
    AbstractCommand* touchComm = new TouchCommand(&fileSystem, &fileFactory);
    AbstractCommand* removeCommand = new RemoveCommand(&fileSystem);
    AbstractCommand* lsCommand = new LSCommand(&fileSystem);
    AbstractCommand* catCommand = new CatCommand(&fileSystem);
    AbstractCommand* displayCommand = new DisplayCommand(&fileSystem);
    AbstractCommand* copyCommand = new CopyCommand(&fileSystem);

    MacroCommand* renameMacro = new MacroCommand(&fileSystem);
    renameMacro->addCommand(copyCommand);
    renameMacro->addCommand(removeCommand);
    AbstractParsingStrategy* renamingParse = new RenameParsingStrategy();
    renameMacro->setParseStrategy(renamingParse);

    MacroCommand* touchAndCat = new MacroCommand(&fileSystem);
    touchAndCat->addCommand(touchComm);
    touchAndCat->addCommand(catCommand);
    AbstractParsingStrategy* touchcatParse = new TouchPlusCatParsingStrategy();
    touchAndCat->setParseStrategy(touchcatParse);

   //AbstractCommand* aggStatsCommand = new AggregateStatsCommand(&fileSystem);
    AbstractCommand* aggStatsCommand = new AggregateStatsCommand(&fileSystem);

    CommandPrompt* cmdPrompt = new CommandPrompt();
    cmdPrompt->setFileSystem(&fileSystem);
    cmdPrompt->setFileFactory(&fileFactory);
    cmdPrompt->addCommand("touch", touchComm);
    cmdPrompt->addCommand("rm", removeCommand);
    cmdPrompt->addCommand("ls", lsCommand);
    cmdPrompt->addCommand("cat", catCommand);
    cmdPrompt->addCommand("ds", displayCommand);
    cmdPrompt->addCommand("cp", copyCommand);
    cmdPrompt->addCommand("rn", renameMacro);
    cmdPrompt->addCommand("touchcat", touchAndCat);
    cmdPrompt->addCommand("as", aggStatsCommand);
    cmdPrompt->run();
    return 0;
}