#include "headers/Board/Board.h"
#include "styles/ConsoleVisualizerStyles.h"
#pragma once

class BoardVisualizer {
public:
    virtual void visualize_board(const Board& board) = 0;
    virtual void set_style(const visualizer_styles& new_style) = 0;
    virtual ~BoardVisualizer(){};
};