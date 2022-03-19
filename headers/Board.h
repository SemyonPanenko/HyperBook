#include <unordered_map>
#include "headers/Content.h"
#pragma once

class Board {
public:

    void add_content(Content content_to_add);
    void remove_content(uint64_t content_id);

private:

    std::unordered_map<uint64_t, Content> contents;

};