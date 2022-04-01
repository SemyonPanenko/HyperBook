#include "headers/UserInterface.h"
#include "headers/ConsoleVisualizer.h"
#include "headers/ConsoleInterfaceMessages.h"
#include <string>
#include <iostream>
#pragma once

class ConsoleInterface : public UserInterface {
public:
    ConsoleInterface(Application* holding_app);
    void run() override;
    std::string await_command();

};