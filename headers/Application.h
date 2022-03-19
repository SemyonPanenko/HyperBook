#include "headers/BoardManager.h"
#include "headers/ProjectManager.h"
#include "headers/ProjectVisualizer.h"
#include "headers/BoardVisualizer.h"
#pragma once

class Application {
public:
    
    Application(BoardManager& board_manager, ProjectManager& proj_man);
    void run();
    
private:

    BoardManager board_manager;
    ProjectManager project_manager;

};