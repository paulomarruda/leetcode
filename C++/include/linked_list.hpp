#pragma once
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

namespace linked_list{

typedef struct Node{
    int data;
    int num_nexts;
    struct Node* next;
} Node;

class LinkedList{
    private:
    Node* head;
    public:
    
    LinkedList();

    int length();

    void print();

    void prepend(const int data);

    LinkedList inverse();

    LinkedList append(LinkedList other);

    bool remove(const int data);

    bool removeAll(const int data);

};

};
#endif 
