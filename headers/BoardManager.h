#include "headers/Board.h"
#include "headers/BoardVisualizer.h"
#include "headers/BoardTree.h"
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