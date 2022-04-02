#include "headers/Application.h"

Application::Application(BoardManager* bm, ProjectManager* pm) : board_manager(bm), project_manager(pm) {};
Application::~Application() {}

void Application::run() {

    is_running = true;
    board_manager->set_board(project_manager->current_project.all_boards.head);

}