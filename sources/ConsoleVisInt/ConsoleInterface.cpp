#include "headers/ConsoleVisInt/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(Application *holding_app) : UserInterface(holding_app){};

std::string ConsoleInterface::await_command()
{

    std::string result;
    std::cin >> result;
    return result;
}

void ConsoleInterface::run()
{

    std::cout << opening_message;

    while (holding_app->is_running)
    {

        std::string current_command = await_command();

        if (current_command == stop_command)
        {

            holding_app->is_running = false;
        }

        if (current_command == visualize_project_command)
        {

            holding_app->project_manager->visualize_project();
        }

        if (current_command == visualize_board_command)
        {

            holding_app->board_manager->visualize_current_board();
        }

        if (current_command == add_board_command)
        {

            holding_app->board_manager->current_board->add_sub_board();
        }

        if (current_command == add_content_from_text_file_command)
        {

            std::cout << ask_for_text_file_name_message;

            std::string input_file_name;
            std::cin >> input_file_name;

            TextContent *new_content = new TextContent();
            new_content->retrieve_content_from_file(input_file_name);

            holding_app->board_manager->current_board->board.add_content(new_content);

            std::cout << add_content_success_message;
        }

        if (current_command == up_board_tree_command)
        {

            if (holding_app->board_manager->current_board->upper_node)
            {

                holding_app->board_manager->set_board(
                    holding_app->board_manager->current_board->upper_node);

                auto current_board_id = holding_app->board_manager->current_board->board_node_id;

                std::cout << went_up_board_message << current_board_id << "\n";
            } else {

                std::cout << no_upper_board_error_message;

            }
        }

        if (current_command == go_down_board_by_id_command)
        {

            std::cout << ask_for_id_message;
            uint64_t board_id;
            std::cin >> board_id;

            holding_app->board_manager->set_board(

                holding_app->board_manager->current_board->sub_boards[board_id]

            );

            std::cout << success_went_down_message;
        }

        if (current_command == get_current_id_command)
        {

            auto current_board_id = holding_app->board_manager->current_board->board_node_id;
            std::cout << board_id_message << current_board_id << "\n";
        }
    }
}