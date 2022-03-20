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

void ConsoleBoardVisualizer::visualize_content(Content *const text_content)
{

    auto to_text_ptr = dynamic_cast<TextContent *const>(text_content);

    if (to_text_ptr)
    {

        std::cout << to_text_ptr->text_data;
    }
}

void ConsoleProjectVisualizer::visualize_tree(BoardTree &board_to_visualize)
{
    std::cout << "Visualizing tree...\n";

    current_offset = 0;
    visualize_board_node(*board_to_visualize.head);

}

void ConsoleProjectVisualizer::visualize_board_node(const BoardTree::BoardNode &node_to_visualize)
{
    std::string offset_str(current_offset, '=');

    std::cout << current_offset;
    std::cout << "board node with number:" << node_to_visualize.board_node_id << "\n";
    std::cout << current_offset;
    std::cout << "His subboards:\n";

    current_offset += 4;

    for (auto sub_board_ptr: node_to_visualize.sub_boards) {

        visualize_board_node(*sub_board_ptr);

    }

    current_offset -= 4;
}