#include "headers/Board/Board.h"
#include <list>
#include <cstdlib>
#include <iostream>

#pragma once

class BoardTree
{
public:

    class BoardNode
    {
    public:
        BoardNode(BoardNode* upper_node);

        std::unordered_map<uint64_t, BoardNode*> sub_boards;
        Board board;
        BoardNode* upper_node;
        uint64_t board_node_id;

        BoardNode *add_sub_board();
        void set_board_node_id(uint64_t new_id);
    };

    BoardTree();
    BoardNode *head;
};