#include "headers/InnerStructure/UserInterface.h"
#include "headers/ConsoleVisInt/ConsoleVisualizer.h"
#include "headers/ConsoleVisInt/ConsoleInterfaceMessages.h"
#include <string>
#include <iostream>
#include <unordered_map>
#pragma once

class ConsoleInterface : public UserInterface {
public:
    ConsoleInterface(CommandHandler* command_handler);
    void run() override;
    std::string await_command();

    // tree traversal
    void prehandle_command_go_up();
    void prehandle_command_go_down();
    void prehandle_command_get_current_id();
    void prehandle_command_go_down_name();

    // project management
    void prehandle_command_save();
    void prehadndle_command_load();

    // content manipulation
    void prehandle_command_add_content_from_text_file();
    void prehandle_command_add_board();

    // visualization commands
    void prehandle_command_visualize_project();
    void prehandle_command_visualize_board();

    // auxillary command
    void prehandle_command_stop();
    void prehandle_chage_style();
    void prehandle_change_board_name();
    void prehandle_empty_command();

private:
    visualizer_styles current_style;
    style_map_type* current_style_map;
};

typedef void (ConsoleInterface::*pointer_to_prehandler) ();
static const std::unordered_map<std::string, pointer_to_prehandler> command_to_handler{

    {stop_command, &ConsoleInterface::prehandle_command_stop},
    {visualize_board_command, &ConsoleInterface::prehandle_command_visualize_board},
    {visualize_project_command, &ConsoleInterface::prehandle_command_visualize_project},
    {add_board_command, &ConsoleInterface::prehandle_command_add_board},
    {add_content_from_text_file_command, &ConsoleInterface::prehandle_command_add_content_from_text_file},
    {load_from_file_command, &ConsoleInterface::prehadndle_command_load},
    {save_to_file_command, &ConsoleInterface::prehandle_command_save},
    {go_down_board_by_id_command, &ConsoleInterface::prehandle_command_go_down},
    {up_board_tree_command, &ConsoleInterface::prehandle_command_go_up},
    {get_current_id_command, &ConsoleInterface::prehandle_command_get_current_id},
    {change_style_command, &ConsoleInterface::prehandle_chage_style},
    {change_board_name_command, &ConsoleInterface::prehandle_change_board_name},
    {go_down_name_command, &ConsoleInterface::prehandle_command_go_down_name},
    {empty_command, &ConsoleInterface::prehandle_empty_command}
};