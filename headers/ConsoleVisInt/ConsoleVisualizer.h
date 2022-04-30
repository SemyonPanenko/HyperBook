#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Content/TextContent.h"
#include "headers/ConsoleVisInt/ConsoleVisualizerMessages.h"
#include "styles/ConsoleVisualizerStyles.h"
#include <iostream>
#pragma once

class ConsoleProjectVisualizer : public ProjectVisualizer {
public:
    ConsoleProjectVisualizer();
    void visualize_tree(BoardTree& board_to_visualize) override;
    void visualize_board_node(const BoardTree::BoardNode& brd_node);

    void set_style(const visualizer_styles& new_style);

private:

    uint64_t current_offset = 0;
    visualizer_styles current_style;
    style_map_type* current_style_map;

};

class ConsoleBoardVisualizer : public BoardVisualizer {
public:
    ConsoleBoardVisualizer();
    void visualize_board(const Board& board) override;

    void set_style(const visualizer_styles& new_style);

private:

    void visualize_content(Content* const text_content);
    visualizer_styles current_style;
    style_map_type* current_style_map;

};