#include "headers/InnerStructure/Project.h"
#include "headers/Content/TextContent.h"
#include "headers/FileVisualizer/FileVisualizerConst.h"
#include <fstream>

class ProjectLoader {
public:

    ProjectLoader(std::string project_path);

    void load_project_tree();
    void load_content();    
    
    Project* get_loaded_project();

private:

    void load_project_tree(BoardTree::BoardNode* current_board);
    void load_content(BoardTree::BoardNode* current_board);
    void load_content_from_file(BoardTree::BoardNode* current_board, const std::string& file_name);

    std::string project_path_;
    Project* loading_project_;
    std::ifstream project_tree_desc_;

};