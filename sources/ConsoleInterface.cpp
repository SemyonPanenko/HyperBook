#include "headers/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(Application* holding_app) : UserInterface(holding_app) {};

std::string ConsoleInterface::await_command() {

    std::string result;
    std::cin >> result;
    return result;

}   

void ConsoleInterface::run() {

    std::cout << "===============================\n";
    std::cout << "All the preparations were completed and I am ready to listen to your commands\n";

    while(holding_app->is_running){

        std::string current_command = await_command();
        std::cout << "Currently completing command " << current_command << "\n";

        if (current_command == "stop") {

            holding_app->is_running = false;

        }

        if (current_command == "visualize_project") {

            holding_app->project_manager->visualize_project();

        }

        if (current_command == "visualize_board") {

            holding_app->board_manager->visualize_current_board();

        }

        if (current_command == "add_board") {

            holding_app->board_manager->current_board->add_sub_board();

        }

        if (current_command == "visualize_content") {

            holding_app->board_manager->current_visualizer->visualize_board(
                holding_app->board_manager->current_board->board
            );

        }

        if (current_command == "add_content_from_text_file") {

            std::cout << "Please, enter a name of a text_file: \n";
            std::string input_file_name;
            std::cin >> input_file_name;

            TextContent* new_content = new TextContent();
            new_content->retrieve_content_from_file(input_file_name);

            holding_app->board_manager->current_board->board.add_content(new_content); 

        }

        if (current_command == "go_up") {

            holding_app->board_manager->set_board(
                holding_app->board_manager->current_board->upper_node
            );

            auto current_board_id = holding_app->board_manager->current_board->board_node_id;

            std::cout << "Went up to board with id= " << current_board_id << "\n";

        }

        if (current_command == "go_down_id") {

            std::cout << "Please enter id of a required board: \n";
            uint64_t board_id;
            std::cin >> board_id;

            holding_app->board_manager->set_board(

                holding_app->board_manager->current_board->sub_boards[board_id]

            );

            std::cout << "Successfully went down\n";

        }

        if (current_command == "get_current_id") {

            auto current_board_id = holding_app->board_manager->current_board->board_node_id;

            std::cout << "You are currently in a board with id= " << current_board_id << "\n";

        }

    }

}