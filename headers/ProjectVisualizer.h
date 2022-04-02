#include "headers/BoardTree.h"
#pragma once

class ProjectVisualizer {
public:

    virtual void visualize_tree(BoardTree& board_to_visualize) = 0;
    virtual ~ProjectVisualizer(){};

};