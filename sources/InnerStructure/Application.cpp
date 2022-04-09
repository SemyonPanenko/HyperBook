#include "headers/InnerStructure/Application.h"

Application::Application(BoardManager* bm, ProjectManager* pm, CommandHandler* ch) : board_manager(bm), 
project_manager(pm), command_handler(ch) {

    ch->app = this;

};
Application::~Application() {}

void Application::run() {

    is_running = true;
    board_manager->set_board(project_manager->current_project->all_boards.head);

}

void Application::reset_board() {

    board_manager->set_board(project_manager->current_project->all_boards.head);

}