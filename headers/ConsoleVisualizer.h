#include "headers/BoardVisualizer.h"
#include "headers/ProjectVisualizer.h"
#include "headers/TextContent.h"
#include <iostream>

class ConsoleProjectVisualizer : public ProjectVisualizer {

    void visualize_tree(BoardTree& board_to_visualize) override;

};

class ConsoleBoardVisualizer : public BoardVisualizer {
public:

    void visualize_board(const Board& board) override;

private:

    void visualize_content(Content* const text_content);

};