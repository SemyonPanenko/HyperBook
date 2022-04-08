#include "headers/InnerStructure/Application.h"
#pragma once 

class UserInterface {
public:

    UserInterface(Application* holding_app) : holding_app(holding_app) {};  
    virtual void run() = 0;
    Application* holding_app;

};