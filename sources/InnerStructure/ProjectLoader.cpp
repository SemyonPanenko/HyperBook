#include "headers/InnerStructure/ProjectLoader.h"

ProjectLoader::ProjectLoader(std::string project_path) : project_path_(project_path)
{

    loading_project_ = new Project();
    std::string project_tree_path = project_path_ + slash + project_tree_file_name;
    project_tree_desc_.open(project_tree_path);
};

void ProjectLoader::load_content()
{

    load_content(loading_project_->all_boards.head);
};

void ProjectLoader::load_content(BoardTree::BoardNode *current_board)
{

    auto curr_id = current_board->get_board().get_board_id();
    auto this_board_folder_path = project_path_ + slash + std::to_string(curr_id);

    std::string listing_script = create_listing_file_script_path;
    auto listing_command = listing_script + " " + this_board_folder_path;

    std::system(listing_command.c_str());

    std::ifstream listing_file_desc;
    std::string listing_file_path = this_board_folder_path + slash + listing_file_name;
    listing_file_desc.open(listing_file_path);

    std::string curr_file_name = "";
    std::getline(listing_file_desc, curr_file_name);

    while (curr_file_name != "")
    {

        load_content_from_file(current_board, curr_file_name);
        std::getline(listing_file_desc, curr_file_name);
    }

    for (auto it : current_board->get_subboards())
    {

        load_content(it.second);
    }

    std::string clearing_script = delete_listing_file_script_path;
    auto clear_command = clearing_script + " " + this_board_folder_path;
    std::system(clear_command.c_str());

};

void ProjectLoader::load_content_from_file(BoardTree::BoardNode *current_board, const std::string &file_name)
{

    std::string extension = file_name.substr(file_name.size() - 3);

    if (extension == text_extension)
    {

        TextContent *current_content = new TextContent();
        current_content->retrieve_content_from_file(file_name);

        current_board->get_board().add_content(current_content);
    }
}

void ProjectLoader::load_project_tree()
{

    auto head_board_node = loading_project_->all_boards.head;
    std::string dummy_string;
    std::getline(project_tree_desc_, dummy_string);
    load_project_tree(head_board_node);
};

void ProjectLoader::load_project_tree(BoardTree::BoardNode *current_board)
{

    std::string curr_line;
    uint64_t curr_board_id;

    std::getline(project_tree_desc_, curr_line);

    // Stoy, komu govoryu!!!!
    curr_board_id = std::stoi(curr_line);
    current_board->set_board_node_id(curr_board_id);

    std::getline(project_tree_desc_, curr_line);
    current_board->set_board_name(curr_line);

    while (curr_line != board_node_end_tag)
    {

        std::getline(project_tree_desc_, curr_line);
        if (curr_line == sub_board_begin_tag)
        {

            std::getline(project_tree_desc_, curr_line);
            while (curr_line != sub_board_end_tag)
            {

                auto sub_board_ptr = current_board->add_sub_board();
                load_project_tree(sub_board_ptr);
                std::getline(project_tree_desc_, curr_line);
            }
        }
    }
};

Project *ProjectLoader::get_loaded_project()
{

    load_project_tree();
    load_content();
    return loading_project_;
}
