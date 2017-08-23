#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include <cstdlib>

class LinkedList {
    class Node {
        int value;
        Node * next;
    };

private:
    Node * head;
    std::size_t length;

public:
    LinkedList() {
        this->length = 0;
    }

    const std::size_t size() const;
    const bool empty() const { return this->length == 0; }
};

#endif //ALGORITHMS_LINKEDLIST_H
