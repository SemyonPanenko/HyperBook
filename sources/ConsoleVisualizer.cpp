#include "headers/ConsoleVisualizer.h"

void ConsoleBoardVisualizer::visualize_board(const Board &board)
{

    std::cout << "Visualizing board...\n";

    for (auto content_iter = board.contents.begin();
         content_iter != board.contents.end();
         ++content_iter)
    {
        visualize_content(content_iter->second);
    }

    std::cout << "\n";

    std::cout << "Board has been succesfully visualized\n";
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

    std::cout << "Ended tree visualization\n";
}

void ConsoleProjectVisualizer::visualize_board_node(const BoardTree::BoardNode &node_to_visualize)
{
    std::string offset_str(current_offset, '=');

    std::cout << offset_str;
    std::cout << "board node with number:" << node_to_visualize.board_node_id << "\n";

    if (node_to_visualize.sub_boards.size())
    {

        std::cout << offset_str;
        std::cout << "His subboards:\n";

        current_offset += 4;

        for (auto sub_board_ptr : node_to_visualize.sub_boards)
        {

            visualize_board_node(*(sub_board_ptr.second));
        }

        current_offset -= 4;
    }
}