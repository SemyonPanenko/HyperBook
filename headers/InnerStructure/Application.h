#include "headers/Board/BoardManager.h"
#include "headers/InnerStructure/ProjectManager.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include <iostream>
#pragma once

class Application
{
public:
    Application(BoardManager *board_manager, ProjectManager *proj_man);
    void run();

    ~Application();
    bool is_running;

    BoardManager *board_manager;
    ProjectManager *project_manager;
};