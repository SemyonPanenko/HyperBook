#include "headers/ConsoleVisInt/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(Application *holding_app) : UserInterface(holding_app){};

std::string ConsoleInterface::await_command()
{

    std::string result;

    std::cout << stash_style;
    std::cin >> result;
    return result;
}

void ConsoleInterface::run()
{

    std::cout << info_messages_set_style;
    std::cout << opening_message;

    while (holding_app->is_running)
    {

        std::string current_command = await_command();

        if (current_command == stop_command)
        {
            holding_app->command_handler->handle_command_stop();
        }

        if (current_command == visualize_project_command)
        {
            holding_app->command_handler->handle_command_visualize_project();
        }

        if (current_command == visualize_board_command)
        {
            holding_app->command_handler->handle_command_visualize_board();
        }

        if (current_command == add_board_command)
        {
            holding_app->command_handler->handle_command_add_board();
            std::cout << success_messages_set_style;
            std::cout << success_added_board_message;
        }

        if (current_command == add_content_from_text_file_command)
        {

            std::cout << ask_messages_set_style;
            std::cout << ask_for_text_file_name_message;

            std::string input_file_name;

            std::cout << stash_style;
            std::cin >> input_file_name;

            holding_app->command_handler->handle_command_add_content_from_text_file(std::move(input_file_name));

            std::cout << success_messages_set_style;
            std::cout << add_content_success_message;
        }

        if (current_command == up_board_tree_command)
        {
            try{
            
                holding_app->command_handler->handle_command_go_up();
            
            } catch (std::exception& excep) {

                std::cout << error_messages_set_style;
                std::cout << upper_board_error;

            }
            
        }

        if (current_command == go_down_board_by_id_command)
        {

            std::cout << ask_messages_set_style;
            std::cout << ask_for_id_message;
            uint64_t board_id;

            std::cout << stash_style;
            std::cin >> board_id;

            try
            {

                holding_app->command_handler->handle_command_go_down(board_id);
            }
            catch (std::out_of_range &excep)
            {
                std::cout << error_messages_set_style;
                std::cout << no_sub_board_error;
            }

            std::cout << success_messages_set_style;
            std::cout << success_went_down_message;
        }

        if (current_command == get_current_id_command)
        {

            auto current_board_id = holding_app->command_handler->handle_command_get_current_id();
            
            std::cout << info_messages_set_style;
            std::cout << board_id_message << current_board_id << "\n";
        }

        if (current_command == save_to_file_command)
        {

            std::cout << ask_messages_set_style;
            std::cout << ask_for_save_project_path;

            std::string desired_path;

            std::cout << stash_style;
            std::cin >> desired_path;
            holding_app->command_handler->handle_command_save(desired_path);

            std::cout << success_messages_set_style;
            std::cout << success_save_project_message;
        }

        if (current_command == load_from_file_command)
        {

            std::cout << ask_messages_set_style;
            std::cout << ask_project_path;
            std::string project_path_;

            std::cout << stash_style;
            std::cin >> project_path_;

            holding_app->command_handler->hadndle_command_load(project_path_);

            std::cout << success_messages_set_style;
            std::cout << success_loaded_project_message;
        }
    }
}