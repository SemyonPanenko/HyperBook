#include "headers/Board.h"
#pragma once
#include <list>

class BoardTree {

    class BoardNode {
        public:

            std::list<BoardNode*> sub_boards;    
            Board board;
            uint64_t board_node_id;

    };

};