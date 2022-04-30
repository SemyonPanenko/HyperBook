#include "headers/FileVisualizer/FileVisualizer.h"

FileBoardVisualizer::FileBoardVisualizer(std::string desired_path) : project_path_(desired_path) {
};

void FileBoardVisualizer::visualize_board(const Board& board) {

    std::string this_board_folder_path = project_path_ + slash + std::to_string(board.board_id_);
    std::string create_folder_command = create_nested_foled_script_path + " " + this_board_folder_path; 
    std::system(create_folder_command.c_str());

    for (auto content_iter = board.contents.begin();
         content_iter != board.contents.end();
         ++content_iter)
    {
        std::string this_content_file_path = this_board_folder_path + slash + std::to_string(content_iter->first) + "." + text_extension;
        visualize_content(content_iter->second, this_content_file_path);
    }

};

void FileBoardVisualizer::visualize_all_boards(BoardTree::BoardNode& board_node) {

    visualize_board(board_node.board);

    for (auto sub_board_ptr : board_node.sub_boards){

        visualize_all_boards(*(sub_board_ptr.second));

    }

}

void FileBoardVisualizer::visualize_content(Content* content, const std::string& this_content_file_path) {

    auto to_text_ptr = dynamic_cast<TextContent *const>(content);

    if (to_text_ptr)
    {
        std::ofstream this_content_visualizer_;
        this_content_visualizer_.open(this_content_file_path);

        this_content_visualizer_ << to_text_ptr->text_data;

        this_content_visualizer_.close();
    }

};

FileBoardVisualizer::~FileBoardVisualizer() {

};

FileProjectVisualizer::FileProjectVisualizer(std::string desired_path) : project_path_(desired_path) {
};

FileProjectVisualizer::~FileProjectVisualizer() {
};

void FileProjectVisualizer::visualize_tree(BoardTree& board_to_visualize) {

    std::ofstream project_visualizer_desc_;
    
    auto resulting_fiel = project_path_ + slash + project_tree_file_name;
    project_visualizer_desc_.open(resulting_fiel);

    visualize_board_node(*board_to_visualize.head, project_visualizer_desc_);
    project_visualizer_desc_.close();

};

void FileProjectVisualizer::visualize_board_node(const BoardTree::BoardNode& board_node, std::ofstream& file_desc_){

    file_desc_ << board_node_begin_tag << std::endl;
    file_desc_ << board_node.board_node_id << std::endl;
    
    if (board_node.sub_boards.size()){

        file_desc_ << sub_board_begin_tag << std::endl;
        for (auto sub_board_ptr : board_node.sub_boards){

            visualize_board_node(*(sub_board_ptr.second), file_desc_);

        }
        file_desc_ << sub_board_end_tag << std::endl;
    }

    file_desc_ << board_node_end_tag << std::endl;

};

