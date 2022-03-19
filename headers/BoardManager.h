#include "headers/Board.h"
#include "headers/BoardVisualizer.h"
#pragma once

class BoardManager {
public:

    void visualize_board();
    void set_board(Board board_to_set);

private:

    Board current_board;
    BoardVisualizer current_visualizer;

};