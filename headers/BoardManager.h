#include "headers/Board.h"
#include "headers/BoardVisualizer.h"
#include <iostream>
#pragma once

class BoardManager {
public:

    BoardManager(BoardVisualizer* bv);
    void visualize_current_board();
    void set_board(Board* board_to_set);

private:

    Board* current_board;
    BoardVisualizer* current_visualizer;

};