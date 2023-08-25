#pragma once
#include <memory>
#ifndef LINEAR_HPP
#define LINEAR_HPP

namespace singly_linked_list{
    template<typename T>
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node(T data) : data{data}, next{nullptr} {};
    };
};

#endif 
