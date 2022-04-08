#include "headers/InnerStructure/UserInterface.h"
#include "headers/ConsoleVisInt/ConsoleVisualizer.h"
#include "headers/ConsoleVisInt/ConsoleInterfaceMessages.h"
#include <string>
#include <iostream>
#pragma once

class ConsoleInterface : public UserInterface {
public:
    ConsoleInterface(Application* holding_app);
    void run() override;
    std::string await_command();

};