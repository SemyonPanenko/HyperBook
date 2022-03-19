#include "headers/Project.h"
#include "headers/ProjectVisualizer.h"
#pragma once

class ProjectManager {
public:

    void create_project();
    void visualize_project();
    void close_project();

private:

    Project current_project;
    ProjectVisualizer current_visualizer;
    
};