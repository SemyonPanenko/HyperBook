#include "headers/InnerStructure/ProjectManager.h"

ProjectManager::ProjectManager(ProjectVisualizer* project_vis) : current_visualizer(project_vis) {

};

void ProjectManager::visualize_project() {

    current_visualizer->visualize_tree(current_project.all_boards);

};

void ProjectManager::save_project(std::string& desired_path) {

    FileBoardVisualizer* board_vis = new FileBoardVisualizer(desired_path);

    auto*& head = current_project.all_boards.head;
    board_vis->visualize_all_boards(*head);

    delete board_vis;

    FileProjectVisualizer* proj_vis = new FileProjectVisualizer(desired_path);
    proj_vis->visualize_tree(current_project.all_boards);

    delete proj_vis;

};