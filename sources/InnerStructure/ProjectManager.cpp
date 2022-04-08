#include "headers/InnerStructure/ProjectManager.h"

ProjectManager::ProjectManager(ProjectVisualizer* project_vis) : current_visualizer(project_vis) {

};

void ProjectManager::visualize_project() {

    current_visualizer->visualize_tree(current_project.all_boards);

};