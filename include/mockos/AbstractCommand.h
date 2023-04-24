#include <string>

class AbstractCommand{
public:
    virtual int execute(std::string command);
    virtual void displayInfo();
    virtual ~AbstractCommand() = default;
};