#include <unordered_map>
#include "headers/Content/Content.h"
#include <cstdlib>
#include <iostream>
#pragma once

const std::string default_board_name = "Unnamed board";

class Board {
public:

    Board();

    void add_content(Content* content_to_add);
    void remove_content(uint64_t content_id);
    void set_name(const std::string& new_name);
    void set_id(size_t new_board_id);
    const std::string& get_name() const;

    const std::unordered_map<uint64_t, Content*>& get_content_container() const {

        return contents;

    }

    size_t get_board_id() const  {

        return board_id_;

    }

    ~Board();

private:

    std::unordered_map<uint64_t, Content*> contents;
    size_t board_id_;
    std::string board_name;

};