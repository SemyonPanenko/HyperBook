#include "headers/BoardTree.h"


BoardTree::BoardNode::BoardNode(BoardNode* upper_node=nullptr) : upper_node(upper_node) {

    board_node_id = std::rand();

    std::cout << "Just created board with board id: " << board_node_id << "\n";

}

BoardTree::BoardTree() {

    head = new BoardTree::BoardNode();

}

BoardTree::BoardNode* BoardTree::BoardNode::add_sub_board() {

    std::cout << "Adding sub_board\n";

    BoardNode* new_board = new BoardNode(this);

    sub_boards.insert({new_board->board_node_id, new_board});

    std::cout << "Pushed sub_board\n";
    std::cout.flush();

    return new_board;

}

