#include "headers/InnerStructure/Application.h"
#pragma once 

class UserInterface {
public:

    UserInterface(CommandHandler* command_handler) : command_handler_(command_handler) {};  
    virtual void run() = 0;
    CommandHandler* command_handler_;

};