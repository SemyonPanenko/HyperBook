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

        BoardNode *add_sub_board();
        void set_board_node_id(uint64_t new_id);
        uint64_t get_board_id() const;
        void set_board_name(const std::string& new_name);
        const std::unordered_map<uint64_t, BoardNode*>& get_subboards() const; 
        Board& get_board();

        BoardNode* const get_upper_node() const; 

    private:
        std::unordered_map<uint64_t, BoardNode*> sub_boards;
        Board board;
        BoardNode* upper_node;
        uint64_t board_node_id;

    };

    BoardTree();
    BoardNode *head;
};