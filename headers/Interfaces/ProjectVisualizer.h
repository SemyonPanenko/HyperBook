#include "headers/Board/BoardTree.h"
#include "styles/ConsoleVisualizerStyles.h"
#pragma once

class ProjectVisualizer {
public:

    virtual void visualize_tree(BoardTree& board_to_visualize) = 0;
    virtual ~ProjectVisualizer(){};
    virtual void set_style(const visualizer_styles& new_style) = 0;

};