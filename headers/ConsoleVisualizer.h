#include "headers/BoardVisualizer.h"
#include "headers/ProjectVisualizer.h"
#include "headers/TextContent.h"
#include <iostream>

class ConsoleProjectVisualizer {

    void visualize_tree(BoardTree& board_to_visualize);

};

class ConsoleBoardVisualizer {
public:

    void visualize_board(const Board& board);

private:

    void visualize_content(Content* const text_content);

};