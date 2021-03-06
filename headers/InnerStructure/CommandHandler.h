#pragma once
#include "headers/InnerStructure/Application.h"
#include <string>

class Application; 

class CommandHandler {
public:

    CommandHandler();
    
    // tree traversal
    void handle_command_go_up();
    void handle_command_go_down(uint64_t id);
    uint64_t handle_command_get_current_id();

    // project management
    void handle_command_save(std::string project_path);
    void hadndle_command_load(std::string project_path);

    // content manipulation
    void handle_command_add_content_from_text_file(std::string input_file);
    void handle_command_add_board();

    // visualization commands
    void handle_command_visualize_project();
    void handle_command_visualize_board();

    // auxillary command
    void handle_command_stop();

private:

friend class Application;

    Application* app;

};