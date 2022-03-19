#include "Content.h"

class TextContent : Content {
public:

    void retrieve_content_from_file(const std::string& file_path) override;
    TextContent();
    
    std::string text_data;

};