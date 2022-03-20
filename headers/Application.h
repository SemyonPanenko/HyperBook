#include "headers/BoardManager.h"
#include "headers/ProjectManager.h"
#include "headers/ProjectVisualizer.h"
#include "headers/BoardVisualizer.h"
#include <iostream>
#pragma once

class Application
{
public:
    Application(BoardManager *board_manager, ProjectManager *proj_man);
    void run();

    ~Application();

private:
    BoardManager *board_manager;
    ProjectManager *project_manager;
};