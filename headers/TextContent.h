#include "Content.h"
#pragma once

class TextContent : public Content {
public:

    void retrieve_content_from_file(const std::string& file_path) override;
    TextContent();
    
    std::string text_data;

};