#include "headers/TextContent.h"
#include <iostream>
#include <fstream>

TextContent::TextContent() {};

void TextContent::retrieve_content_from_file(const std::string& file_path) {

    std::ifstream file_desc;

    file_desc.open(file_path);
    file_desc >> text_data;
    
    file_desc.close();

}