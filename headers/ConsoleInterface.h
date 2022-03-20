#include "headers/UserInterface.h"
#include <string>
#include <iostream>

class ConsoleInterface : public UserInterface {
public:
    ConsoleInterface(Application* holding_app);
    void run() override;
    std::string await_command();

};