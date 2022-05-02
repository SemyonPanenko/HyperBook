#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Content/TextContent.h"
#include "headers/FileVisualizer/FileVisualizerConst.h"
#include <fstream>

class FileBoardVisualizer : public BoardVisualizer {
public:
    FileBoardVisualizer(std::string desired_path);
    void visualize_board(const Board& board) override;
    void visualize_content(Content* content, const std::string& this_content_file_path);
    void visualize_all_boards(BoardTree::BoardNode& head_node);
    void set_style(const visualizer_styles& new_style) {};
    ~FileBoardVisualizer();
private:
    std::string project_path_;
};

class FileProjectVisualizer : public ProjectVisualizer {
public:
    FileProjectVisualizer(std::string desired_path);
    void visualize_tree(BoardTree& board_to_visualize) override;
    void visualize_board_node(BoardTree::BoardNode& board_node, std::ofstream& file_desc_);
    void set_style(const visualizer_styles& new_style) {};
    ~FileProjectVisualizer();
private:
    std::string project_path_;
};