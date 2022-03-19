#include "headers/BoardTree.h"


BoardTree::BoardNode::BoardNode() {

    board_node_id = std::rand();
    std::cout << "Just created board with board id: " << board_node_id << "\n";

}

BoardTree::BoardTree() {

    head = new BoardTree::BoardNode();

}

BoardTree::BoardNode* BoardTree::BoardNode::add_sub_board() {

    BoardNode* new_board = new BoardNode();
    sub_boards.push_back(new_board);

    return new_board;

}

