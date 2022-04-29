#include "headers/Board/BoardManager.h"

BoardManager::BoardManager(BoardVisualizer* bv) : current_visualizer(bv) {

}

void BoardManager::visualize_current_board() {

    if (current_board) {

        current_visualizer->visualize_board(current_board->board);

    }

}

void BoardManager::set_board(BoardTree::BoardNode* brd) {

    current_board = brd;

}