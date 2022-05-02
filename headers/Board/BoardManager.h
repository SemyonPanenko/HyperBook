#include "headers/Board/Board.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Board/BoardTree.h"
#include "styles/ConsoleVisualizerStyles.h"
#include <iostream>
#pragma once

class BoardManager {
public:

    BoardManager(BoardVisualizer* bv);
    void visualize_current_board();
    void set_board_by_id(uint64_t board_id);
    BoardTree::BoardNode* get_current_board() const;
    uint64_t get_current_id() const;
    void go_to_parent_board();
    void set_board_visualizer_style(visualizer_styles new_style);
    void set_board(BoardTree::BoardNode* board_to_set);

private:

    BoardTree::BoardNode* current_board;
    BoardVisualizer* current_visualizer;

};