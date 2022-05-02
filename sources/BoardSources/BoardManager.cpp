#include "headers/Board/BoardManager.h"
const std::string already_in_top_node_error = "Already in the upper node";

BoardManager::BoardManager(BoardVisualizer* bv) : current_visualizer(bv) {

}

void BoardManager::visualize_current_board() {

    if (current_board) {

        current_visualizer->visualize_board(current_board->get_board());

    }

}

void BoardManager::set_board_by_id(uint64_t board_id) {

    set_board(current_board->get_subboards().at(board_id));

}

BoardTree::BoardNode* BoardManager::get_current_board() const {

    return current_board;

}

uint64_t BoardManager::get_current_id() const {

    return current_board->get_board_id();

}

void BoardManager::set_board(BoardTree::BoardNode* brd) {

    current_board = brd;

}

void BoardManager::set_board_visualizer_style(visualizer_styles new_style) {

    current_visualizer->set_style(new_style);

}

void BoardManager::go_to_parent_board() {

    if (get_current_board()->get_upper_node())
    {
        set_board(
            get_current_board()->get_upper_node());

        auto current_board_id = get_current_board()->get_board_id();
    }
    else
    {
        throw std::domain_error(already_in_top_node_error);
    }

}