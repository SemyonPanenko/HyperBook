#include "headers/Board.h"
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
        uint64_t board_node_id;

        BoardNode* upper_node;

        BoardNode *add_sub_board();
    };

    BoardTree();

    BoardNode *head;
};