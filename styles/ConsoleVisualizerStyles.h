#include <string>
#include <unordered_map>

enum class message_type {

    error_type, success_type, ask_type, info_type, stash_type

};

enum class visualizer_styles {

    default_style, redish_style

};

using style_map_type = const std::unordered_map<message_type, const std::string&>;

//Default style
const std::string error_message_default = "\033[1;31m";
const std::string success_message_default = "\033[32m";
const std::string ask_message_default = "\033[37m";
const std::string info_message_default = "\033[34m";

const std::string stash_style = "\033[0m";

style_map_type style_default{

    {message_type::error_type, error_message_default},
    {message_type::success_type, success_message_default},
    {message_type::ask_type, ask_message_default},
    {message_type::info_type, info_message_default},
    {message_type::stash_type, stash_style}

}; 

//Redish style
const std::string error_message_redish = "\033[1;30m";
const std::string success_message_redish = "\033[1;31m";
const std::string ask_message_redish = "\033[91m";
const std::string info_message_redish = "\033[97m";

const std::string stash_style_redish = "\033[0m";


style_map_type style_redish{

    {message_type::error_type, error_message_redish},
    {message_type::success_type, success_message_redish},
    {message_type::ask_type, ask_message_redish},
    {message_type::info_type, info_message_redish},
    {message_type::stash_type, stash_style_redish}

}; 

const std::unordered_map<visualizer_styles, style_map_type>
style_to_map {

    {visualizer_styles::default_style, style_default},
    {visualizer_styles::redish_style, style_redish}

};

const std::unordered_map<std::string, visualizer_styles>
style_string_to_style {

    {"default", visualizer_styles::default_style},
    {"redish", visualizer_styles::redish_style}

};