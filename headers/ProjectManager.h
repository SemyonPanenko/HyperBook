#include "headers/Project.h"
#include "headers/ProjectVisualizer.h"
#pragma once

class ProjectManager {
public:

    ProjectManager(ProjectVisualizer* project_vis);

    // void create_project();
    void visualize_project();
    // void close_project();

    Project current_project;
    ProjectVisualizer* current_visualizer;
    
};