#include "headers/ConsoleVisualizer.h"

void ConsoleBoardVisualizer::visualize_board(const Board &board)
{

    for (auto content_iter = board.contents.begin();
         content_iter != board.contents.end();
         ++content_iter)
    {
        visualize_content(content_iter->second);
    }
}

void ConsoleBoardVisualizer::visualize_content(Content* const text_content)
{

    auto to_text_ptr = dynamic_cast<TextContent* const>(text_content);

    if (to_text_ptr) {

        std::cout << to_text_ptr->text_data;

    }

}

void ConsoleProjectVisualizer::visualize_tree(BoardTree& board_to_visualize)
{

    std::cout << "I can't visualize project trees yet... =(";

}