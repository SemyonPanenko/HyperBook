#include "headers/BoardTree.h"
#pragma once

class Project {
public:

    void add_board(Board board);
    void remove_board(uint64_t board_node_id);
    Board& get_board(uint64_t board_node_id);

private:

    BoardTree all_boards;

};