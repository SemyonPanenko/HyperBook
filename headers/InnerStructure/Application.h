#pragma once
#include "headers/Board/BoardManager.h"
#include "headers/InnerStructure/ProjectManager.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/InnerStructure/CommandHandler.h"
#include <iostream>

class CommandHandler;

class Application
{
public:
    Application(BoardManager *board_manager, ProjectManager *proj_man, CommandHandler* command_handler);
    void run();
    void reset_board();

    ~Application();
    bool is_running;

    BoardManager *board_manager;
    ProjectManager *project_manager;
    CommandHandler *command_handler;
};