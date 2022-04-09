#include "headers/Interfaces/ProjectVisualizer.h"
#include "headers/Interfaces/BoardVisualizer.h"
#include "headers/Content/TextContent.h"
#include "string"
#include <fstream>

class FileBoardVisualizer : public BoardVisualizer {
public:
    FileBoardVisualizer(std::string desired_path);
    void visualize_board(const Board& board) override;
    void visualize_content(Content* content, const std::string& this_content_file_path);
    void visualize_all_boards(BoardTree::BoardNode& head_node);
    ~FileBoardVisualizer();
private:
    std::string project_path_;
};

class FileProjectVisualizer : public ProjectVisualizer {
public:
    FileProjectVisualizer(std::string desired_path);
    void visualize_tree(BoardTree& board_to_visualize) override;
    void visualize_board_node(const BoardTree::BoardNode& board_node, std::ofstream& file_desc_);
    ~FileProjectVisualizer();
private:
    std::string project_path_;
};