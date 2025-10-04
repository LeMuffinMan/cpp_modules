#include "ChainedList.hpp"

ChainedList::Node::Node(AMateria* m) : materia(m), next(NULL) {}

ChainedList::ChainedList() : head(NULL) {}

ChainedList::ChainedList(const ChainedList& other) : head(NULL) {
  (void)other;
}

ChainedList& ChainedList::operator=(const ChainedList& other) {
    if (this != &other) {
        clear();
    }
    return *this;
}

ChainedList::~ChainedList() {
    clear();
}

void ChainedList::addBack(AMateria* dropped) {
    if (!dropped) return;
    
    Node* newNode = new Node(dropped);
    
    if (!head) {
        head = newNode;
        return;
    }
    
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void ChainedList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->materia;  
        delete current;  
        current = next;
    }
    head = NULL;
}
