#include "headers/Board.h"

void Board::add_content(Content* content_to_add)
{
    uint64_t current_content_id = std::rand();

    contents.insert({current_content_id, content_to_add});
}

void Board::remove_content(uint64_t content_id)
{

    auto found_content = contents.find(content_id);

    if (found_content == contents.end()) {
        
        return;

    } else {
        
        delete found_content->second;
        contents.erase(found_content);

    }
}

Board::~Board() {

    for (auto content_iter : contents) {

        delete content_iter.second;

    }

}   

Board::Board() {
}