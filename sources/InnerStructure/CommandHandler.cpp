#include "headers/InnerStructure/CommandHandler.h"

const std::string domain_error_message = "Already in upper board!\n";

CommandHandler::CommandHandler() {};

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