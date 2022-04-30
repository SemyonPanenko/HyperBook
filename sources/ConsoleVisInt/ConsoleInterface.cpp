#include "headers/ConsoleVisInt/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(Application *holding_app) : UserInterface(holding_app), current_style(visualizer_styles::default_style), current_style_map(&style_default){};

std::string ConsoleInterface::await_command()
{

    std::string result;

    std::cout << stash_style;
    std::cin >> result;
    return result;
}
// tree traversal
void ConsoleInterface::prehandle_command_go_up()
{

    try
    {

        holding_app->command_handler->handle_command_go_up();
    }
    catch (std::exception &excep)
    {

        std::cout << (*current_style_map).at(message_type::error_type);
        std::cout << upper_board_error;
    }
};

void ConsoleInterface::prehandle_command_go_down()
{

    std::cout << (*current_style_map).at(message_type::ask_type);
    std::cout << ask_for_id_message;
    uint64_t board_id;

    std::cout << (*current_style_map).at(message_type::stash_type);
    std::cin >> board_id;

    try
    {
        holding_app->command_handler->handle_command_go_down(board_id);

        std::cout << (*current_style_map).at(message_type::success_type);
        std::cout << success_went_down_message;
    }
    catch (std::out_of_range &excep)
    {
        std::cout << (*current_style_map).at(message_type::error_type);
        std::cout << no_sub_board_error;
    }

};

void ConsoleInterface::prehandle_command_get_current_id()
{

    auto current_board_id = holding_app->command_handler->handle_command_get_current_id();

    std::cout << (*current_style_map).at(message_type::info_type);
    std::cout << board_id_message << current_board_id << "\n";
};

// project management
void ConsoleInterface::prehandle_command_save()
{

    std::cout << (*current_style_map).at(message_type::ask_type);
    std::cout << ask_for_save_project_path;

    std::string desired_path;

    std::cout << (*current_style_map).at(message_type::stash_type);
    std::cin >> desired_path;
    holding_app->command_handler->handle_command_save(desired_path);

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << success_save_project_message;
};

void ConsoleInterface::prehadndle_command_load()
{

    std::cout << (*current_style_map).at(message_type::ask_type);
    std::cout << ask_project_path;
    std::string project_path_;

    std::cout << (*current_style_map).at(message_type::stash_type);
    std::cin >> project_path_;

    holding_app->command_handler->hadndle_command_load(project_path_);

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << success_loaded_project_message;
};

// content manipulation
void ConsoleInterface::prehandle_command_add_content_from_text_file()
{

    std::cout << (*current_style_map).at(message_type::ask_type);
    std::cout << ask_for_text_file_name_message;

    std::string input_file_name;

    std::cout << (*current_style_map).at(message_type::stash_type);
    std::cin >> input_file_name;

    holding_app->command_handler->handle_command_add_content_from_text_file(std::move(input_file_name));

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << add_content_success_message;
};
void ConsoleInterface::prehandle_command_add_board()
{

    holding_app->command_handler->handle_command_add_board();

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << success_added_board_message;
};

// visualization commands
void ConsoleInterface::prehandle_command_visualize_project()
{
    holding_app->command_handler->handle_command_visualize_project();
};
void ConsoleInterface::prehandle_command_visualize_board()
{

    holding_app->command_handler->handle_command_visualize_board();
};

// auxillary command
void ConsoleInterface::prehandle_command_stop()
{

    holding_app->command_handler->handle_command_stop();
};

void ConsoleInterface::prehandle_chage_style() {

    std::cout << (*current_style_map).at(message_type::ask_type);
    std::cout << ask_for_style_string;

    std::cout << (*current_style_map).at(message_type::stash_type);
    std::string new_style;
    std::cin >> new_style;

    try {

        auto visualizer_style_type = style_string_to_style.at(new_style);
        current_style = visualizer_style_type;
        current_style_map = &style_to_map.at(current_style);

    } catch (std::invalid_argument& inv_arg) {

        std::cout << (*current_style_map).at(message_type::error_type);
        std::cout << no_such_style_message;
        return;

    }

    auto vis_board_ptr_ = holding_app->board_manager->current_visualizer;
    auto vis_proj_ptr_ = holding_app->project_manager->current_visualizer;

    auto vis_board_ptr = dynamic_cast<ConsoleBoardVisualizer*>(vis_board_ptr_);
    auto vis_proj_ptr = dynamic_cast<ConsoleProjectVisualizer*>(vis_proj_ptr_);

    if (!vis_board_ptr || !vis_proj_ptr){

        std::cout << (*current_style_map).at(message_type::error_type);
        std::cout << wrong_initializer_for_restyling;

    } else {

        vis_board_ptr->set_style(current_style);
        vis_proj_ptr->set_style(current_style);

    }

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << success_changed_style;

}

void ConsoleInterface::run()
{

    std::cout << (*current_style_map).at(message_type::info_type);
    std::cout << opening_message;

    while (holding_app->is_running)
    {

        std::string current_command = await_command();
        try {

            ((*this).*(command_to_handler.at(current_command)))();

        } catch (...) {

            std::cout << (*current_style_map).at(message_type::error_type);
            std::cout << unknown_command_error;

        }
    }
}