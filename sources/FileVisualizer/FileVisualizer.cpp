#include "headers/FileVisualizer/FileVisualizer.h"

FileBoardVisualizer::FileBoardVisualizer(std::string desired_path) {

    auto actual_path = desired_path + ".hp";
    file_desc_.open(actual_path);

};

void FileBoardVisualizer::visualize_board(const Board& board) {

    file_desc_ << "\nboard_start_tag: \n";

    for (auto content_iter = board.contents.begin();
         content_iter != board.contents.end();
         ++content_iter)
    {
        visualize_content(content_iter->second);
    }

    file_desc_ << "\nboard_end_tag: \n";

};

void FileBoardVisualizer::visualize_all_boards(BoardTree::BoardNode& board_node) {

    visualize_board(board_node.board);

    for (auto sub_board_ptr : board_node.sub_boards){

        visualize_all_boards(*(sub_board_ptr.second));

    }


}

void FileBoardVisualizer::visualize_content(Content* content) {


    auto to_text_ptr = dynamic_cast<TextContent *const>(content);

    if (to_text_ptr)
    {
        file_desc_ << "text_content_start_tag: \n";
        file_desc_ << to_text_ptr->text_data;
        file_desc_ << "\ntext_content_end_tag: \n";
    }

};

FileBoardVisualizer::~FileBoardVisualizer() {

    file_desc_.close();

};

FileProjectVisualizer::FileProjectVisualizer(std::string desired_path) {

    std::string actual_path = desired_path + ".hp";
    file_desc_.open(actual_path, std::ios_base::app);

};

FileProjectVisualizer::~FileProjectVisualizer() {

    file_desc_.close();

};

void FileProjectVisualizer::visualize_tree(BoardTree& board_to_visualize) {

    file_desc_ << "tree_visualization_start_tag: \n";
    
    visualize_board_node(*board_to_visualize.head);

    file_desc_ << "tree_visualization_end_tag: \n";

};

void FileProjectVisualizer::visualize_board_node(const BoardTree::BoardNode& board_node){

    file_desc_ << "board_node_begin_tag: \n";
    file_desc_ << board_node.board_node_id << "\n";
    file_desc_ << "sub_boards_begin_tag: \n";
    
    if (board_node.sub_boards.size()){

        for (auto sub_board_ptr : board_node.sub_boards){

            visualize_board_node(*(sub_board_ptr.second));

        }

    }

    file_desc_ << "sub_board_end_tag: \n";
    file_desc_ << "board_node_end_tag: \n";

};

