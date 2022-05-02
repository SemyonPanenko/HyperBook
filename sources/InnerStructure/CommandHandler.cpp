#include "headers/InnerStructure/CommandHandler.h"

const std::string domain_error_message = "Already in upper board!\n";

CommandHandler::CommandHandler() {};

void CommandHandler::handle_command_change_board_name(const std::string& new_board_name) {

    app->board_manager->current_board->set_board_name(new_board_name);

}

void CommandHandler::handle_command_stop()
{

    app->is_running = false;
};

void CommandHandler::handle_command_visualize_board()
{

    app->board_manager->visualize_current_board();
};

void CommandHandler::handle_command_add_board()
{

    app->board_manager->current_board->add_sub_board();
};

void CommandHandler::handle_command_visualize_project()
{

    app->project_manager->visualize_project();
};

void CommandHandler::handle_command_add_content_from_text_file(std::string input_file)
{

    TextContent *new_content = new TextContent();
    new_content->retrieve_content_from_file(input_file);
    app->board_manager->current_board->board.add_content(new_content);
};

void CommandHandler::handle_command_go_up()
{
    if (app->board_manager->current_board->upper_node)
    {
        app->board_manager->set_board(
            app->board_manager->current_board->upper_node);

        auto current_board_id = app->board_manager->current_board->board_node_id;
    }
    else
    {
        throw std::domain_error(domain_error_message);
    }
};

uint64_t CommandHandler::handle_command_get_current_id()
{
    auto current_board_id = app->board_manager->current_board->board_node_id;
    return current_board_id;
};

void CommandHandler::handle_command_save(std::string desired_path)
{

    app->project_manager->save_project(desired_path);
};

void CommandHandler::hadndle_command_load(std::string project_path)
{
    app->project_manager->load_project(project_path);
    app->reset_board();
};

void CommandHandler::handle_command_go_down(uint64_t id)
{
    app->board_manager->set_board(

        app->board_manager->current_board->sub_boards.at(id)

    );
}

void CommandHandler::handle_command_go_down_name(std::string subboard_name) {

    auto& board_container = app->board_manager->current_board->sub_boards;

    uint64_t found_with_correct_name_counter = 0;
    uint64_t last_found_id = 0;

    for (auto& sub_board : board_container) {

        if (sub_board.second->board.board_name == subboard_name){

            last_found_id = sub_board.first;
            ++found_with_correct_name_counter;

        }

    }

    if (found_with_correct_name_counter > 1){

        throw std::invalid_argument(too_many_subboards_with_this_name);

    } else if (found_with_correct_name_counter == 0) {

        throw std::invalid_argument(too_few_subboards_with_this_name);

    } else {

        handle_command_go_down(last_found_id);

    }

}