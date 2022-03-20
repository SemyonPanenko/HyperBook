#include <unordered_map>
#include "headers/Content.h"
#include <cstdlib>
#include <iostream>
#pragma once

class Board {
public:

    Board();

    void add_content(Content* content_to_add);
    void remove_content(uint64_t content_id);

    std::unordered_map<uint64_t, Content*> contents;

    ~Board();

};