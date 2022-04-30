#include "headers/ConsoleVisInt/ConsoleVisualizer.h"

ConsoleBoardVisualizer::ConsoleBoardVisualizer() :
current_style(visualizer_styles::default_style),
current_style_map(&style_default){}

void ConsoleBoardVisualizer::visualize_board(const Board &board)
{

    std::cout << (*current_style_map).at(message_type::stash_type);

    for (auto content_iter = board.contents.begin();
         content_iter != board.contents.end();
         ++content_iter)
    {
        visualize_content(content_iter->second);
    }

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << board_visualization_success_message;
}

void ConsoleBoardVisualizer::visualize_content(Content *const text_content)
{

    auto to_text_ptr = dynamic_cast<TextContent *const>(text_content);

    if (to_text_ptr)
    {
        std::cout << to_text_ptr->text_data;
    }

    std::cout << "\n";
}

void ConsoleBoardVisualizer::set_style(const visualizer_styles& new_style) {

    current_style = new_style;
    current_style_map = &style_to_map.at(current_style);

}


ConsoleProjectVisualizer::ConsoleProjectVisualizer() :
current_style(visualizer_styles::default_style),
current_style_map(&style_default){}

void ConsoleProjectVisualizer::visualize_tree(BoardTree &board_to_visualize)
{

    current_offset = 0;
    visualize_board_node(*board_to_visualize.head);

    std::cout << (*current_style_map).at(message_type::success_type);
    std::cout << tree_visualization_success_message;
}

void ConsoleProjectVisualizer::visualize_board_node(const BoardTree::BoardNode &node_to_visualize)
{
    std::string offset_str(current_offset, offset_symbol);

    std::cout << (*current_style_map).at(message_type::info_type);
    std::cout << offset_str;
    std::cout << board_node_number_message << node_to_visualize.board_node_id << "\n";

    if (node_to_visualize.sub_boards.size())
    {

        std::cout << offset_str;
        std::cout << sub_boards_message;

        current_offset += row_offset;

        for (auto sub_board_ptr : node_to_visualize.sub_boards)
        {

            visualize_board_node(*(sub_board_ptr.second));
        }

        current_offset -= row_offset;
    }
}

void ConsoleProjectVisualizer::set_style(const visualizer_styles& new_style) {

    current_style = new_style;
    current_style_map = &style_to_map.at(current_style);

}