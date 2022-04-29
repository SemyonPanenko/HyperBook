#include "headers/Board/Board.h"
#pragma once

class BoardVisualizer {
public:
    virtual void visualize_board(const Board& board) = 0;
    virtual ~BoardVisualizer(){};
};