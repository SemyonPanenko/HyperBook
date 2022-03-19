#include "headers/BoardManager.h"

BoardManager::BoardManager(BoardVisualizer* bv) : current_visualizer(bv) {

}

void BoardManager::visualize_current_board() {

    if (current_board) {

        current_visualizer->visualize_board(*current_board);

    } else {

        std::cout << "Tried visualizing empty board!\n";

    }

}

void BoardManager::set_board(Board* brd) {

    current_board = brd;

}