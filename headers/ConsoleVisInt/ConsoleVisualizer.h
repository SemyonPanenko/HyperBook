#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Content/TextContent.h"
#include "headers/ConsoleVisInt/ConsoleVisualizerMessages.h"
#include <iostream>
#pragma once

class ConsoleProjectVisualizer : public ProjectVisualizer {

    void visualize_tree(BoardTree& board_to_visualize) override;
    void visualize_board_node(const BoardTree::BoardNode& brd_node);

    uint64_t current_offset = 0;

};

class ConsoleBoardVisualizer : public BoardVisualizer {
public:

    void visualize_board(const Board& board) override;

private:

    void visualize_content(Content* const text_content);

};