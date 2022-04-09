#include "headers/Content/TextContent.h"

TextContent::TextContent(){};

void TextContent::retrieve_content_from_file(const std::string &file_path)
{

    std::ifstream file_desc;

    file_desc.open(file_path);

    std::string data_chunk;

    while (std::getline(file_desc, data_chunk))
    {
        text_data += data_chunk;
        text_data += "\n";
    }

    file_desc.close();
}