#include "headers/InnerStructure/ProjectManager.h"

ProjectManager::ProjectManager(ProjectVisualizer* project_vis) : current_visualizer(project_vis) {

    current_project = new Project();

};

void ProjectManager::visualize_project() {

    current_visualizer->visualize_tree(current_project->all_boards);

};

void ProjectManager::save_project(std::string& desired_path) {

    FileBoardVisualizer* board_vis = new FileBoardVisualizer(desired_path);

    auto*& head = current_project->all_boards.head;
    board_vis->visualize_all_boards(*head);

    delete board_vis;

    FileProjectVisualizer* proj_vis = new FileProjectVisualizer(desired_path);
    proj_vis->visualize_tree(current_project->all_boards);

    delete proj_vis;

};

void ProjectManager::load_project(std::string& project_path) {

    ProjectLoader* curr_project_loader = new ProjectLoader(project_path);
    Project* loaded_proj = curr_project_loader->get_loaded_project();

    delete current_project;
    current_project = loaded_proj;

};