#include "headers/Board/Board.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Board/BoardTree.h"
#include <iostream>
#pragma once

class BoardManager {
public:

    BoardManager(BoardVisualizer* bv);
    void visualize_current_board();
    void set_board(BoardTree::BoardNode* board_to_set);

    BoardTree::BoardNode* current_board;
    BoardVisualizer* current_visualizer;

};