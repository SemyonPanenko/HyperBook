#include <string>
#pragma once

/// Command names
const std::string visualize_project_command = "visualize_project";
const std::string visualize_board_command = "visualize_board";
const std::string add_board_command = "add_board";
const std::string add_content_from_text_file_command = "add_content_from_text_file";
const std::string up_board_tree_command = "go_up";
const std::string go_down_board_by_id_command = "go_down_id";
const std::string get_current_id_command = "get_current_id";
const std::string stop_command = "stop";
const std::string save_to_file_command = "save_project";
const std::string load_from_file_command = "load_project";
const std::string change_style_command = "change_style";

/// Informative messages
const std::string opening_message = "===============================\nAll the preparations were completed and I am ready to listen to your commands\n"; 
const std::string went_up_board_message = "Went up to board with id= ";
const std::string board_id_message = "You are currently in a board with id= ";

/// Asking messagees 
const std::string ask_for_save_project_path = "Please, enter full absolute path to the desired location\n";
const std::string ask_project_path = "Please, enter full absolute path to project\n";
const std::string ask_for_id_message = "Please enter id of a required board: \n";
const std::string ask_for_text_file_name_message = "Please, enter a full absolute path to a text_file: \n";
const std::string ask_for_style_string = "Please, enter a style name\n";

/// Error messages
const std::string no_sub_board_error = "Soryy, no such sub board\n";
const std::string upper_board_error = "Sorry, already in upper board!\n";
const std::string no_upper_board_error_message = "Sorry, but you are already in the upper-most board!\n";
const std::string unknown_command_error = "Unknow command. Try again\n";
const std::string no_such_style_message = "No such style. Aborting command\n";
const std::string wrong_initializer_for_restyling = "Could not swithc visualizer to new style\n";

/// Success messages
const std::string add_content_success_message = "Succesfully added content\n";
const std::string success_went_down_message = "Successfully went down\n";
const std::string success_save_project_message = "Successfully saved project\n";
const std::string success_added_board_message = "Successfully saved project\n";
const std::string success_loaded_project_message = "Succesfully loaded project\n";
const std::string success_changed_style = "Succesfully changed style\n";