#include "headers/Application.h"

Application::Application(BoardManager* bm, ProjectManager* pm) : board_manager(bm), project_manager(pm) {};
Application::~Application() {}

void Application::run() {

    std::cout << "Running application\n";
    is_running = true;
    std::cout << "Application stopped\n";

}