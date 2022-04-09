#include "headers/Board/BoardTree.h"


BoardTree::BoardNode::BoardNode(BoardNode* upper_node=nullptr) : upper_node(upper_node) {

    board_node_id = std::rand();
    board.board_id_ = board_node_id;

}

BoardTree::BoardTree() {

    head = new BoardTree::BoardNode();

}

BoardTree::BoardNode* BoardTree::BoardNode::add_sub_board() {

    BoardNode* new_board = new BoardNode(this);

    sub_boards.insert({new_board->board_node_id, new_board});

    return new_board;

}

void BoardTree::BoardNode::set_board_node_id(uint64_t new_id) {

    auto old_id = board_node_id;

    board_node_id = new_id;
    board.board_id_ = new_id;

    if (upper_node) {

        auto this_board_it = upper_node->sub_boards.find(old_id);
        upper_node->sub_boards.erase(this_board_it);
        upper_node->sub_boards.insert(std::make_pair(new_id, this));

    }

};

