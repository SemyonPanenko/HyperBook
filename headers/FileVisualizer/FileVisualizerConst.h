#include <string>
#pragma once

// auxillary
const std::string slash = "/";
const std::string text_extension = "txt";

//scripts path
const std::string create_listing_file_script_path = "../sources/Scripts/create_file_listing_files.sh";
const std::string create_nested_foled_script_path = "../sources/Scripts/create_nested_folder.sh";

// core project file names
const std::string project_tree_file_name = "project_tree.txt";
const std::string listing_file_name = "all_contents.txt";

// tags. 
// I wonder if I could actually generate html files
const std::string board_node_begin_tag = "board_node_begin_tag: ";
const std::string board_node_end_tag = "board_node_end_tag: ";
const std::string sub_board_begin_tag = "sub_boards_begin_tag: ";
const std::string sub_board_end_tag = "sub_boards_end_tag: ";