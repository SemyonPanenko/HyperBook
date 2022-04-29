#include "headers/InnerStructure/Project.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/FileVisualizer/FileVisualizer.h"
#include "headers/InnerStructure/ProjectLoader.h"
#include <fstream>
#pragma once

const std::string clean_directory_script_path = "../sources/Scripts/clean_directory.sh";

class ProjectManager {
public:

    ProjectManager(ProjectVisualizer* project_vis);

    // void create_project();
    void visualize_project();
    void save_project(std::string& desired_path);
    void load_project(std::string& project_path);

    Project* current_project;
    ProjectVisualizer* current_visualizer;
    
};