#include "headers/InnerStructure/Project.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/FileVisualizer/FileVisualizer.h"
#pragma once

class ProjectManager {
public:

    ProjectManager(ProjectVisualizer* project_vis);

    // void create_project();
    void visualize_project();
    void save_project(std::string& desired_path);
    // void close_project();

    Project current_project;
    ProjectVisualizer* current_visualizer;
    
};