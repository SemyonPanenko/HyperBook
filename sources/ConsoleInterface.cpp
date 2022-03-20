#include "headers/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(Application* holding_app) : UserInterface(holding_app) {};

std::string ConsoleInterface::await_command() {

    std::string result;
    std::cin >> result;
    return result;

}   

void ConsoleInterface::run() {

    while(holding_app->is_running){

        std::string current_command = await_command();
        std::cout << "Currently completing command " << current_command << "\n";

        if (current_command == "stop") {

            holding_app->is_running = false;

        }

        if (current_command == "visualize_project") {

            holding_app->project_manager->visualize_project();

        }

    }

}