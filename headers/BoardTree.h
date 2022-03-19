#include "headers/Board.h"
#include <list>
#include <cstdlib>
#include <isotream>

#pragma once

class BoardTree
{

    class BoardNode
    {
    public:
        BoardNode();

        std::list<BoardNode *> sub_boards;
        Board board;
        uint64_t board_node_id;

        BoardNode *add_sub_board();
    };

    BoardTree();

    BoardNode *head;
};