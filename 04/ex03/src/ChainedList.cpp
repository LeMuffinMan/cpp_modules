#include "ChainedList.hpp"
#include <iostream>

ChainedList::Node::Node(AMateria* m) : materia(m), next(NULL) {}

ChainedList::ChainedList() : head(NULL) {}

ChainedList::ChainedList(const ChainedList& other) : head(NULL) {
    Node* current = other.head;
    Node** copyCurrent = &head;
    
    while (current != NULL) {
        *copyCurrent = new Node(current->materia->clone());
        current = current->next;
        copyCurrent = &((*copyCurrent)->next);
    }
}

ChainedList& ChainedList::operator=(const ChainedList& other) {
    if (this != &other) {
        clear();  
        
        Node* current = other.head;
        Node** copyCurrent = &head;
        
        while (current != NULL) {
            *copyCurrent = new Node(current->materia->clone());
            current = current->next;
            copyCurrent = &((*copyCurrent)->next);
        }
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

void ChainedList::display() const {
    Node* current = head;
    if (!current) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    int index = 0;
    while (current) {
        std::cout << "Node " << index << ":" << std::endl;
        std::cout << "  Materia type: " << current->materia->getType() << std::endl;
        std::cout << "  Materia addr: " << current->materia << std::endl;
        std::cout << "  Node addr: " << current << std::endl;
        std::cout << "  Next addr: " << current->next << std::endl;
        std::cout << "-------------------" << std::endl;
        
        current = current->next;
        index++;
    }
    std::cout << "Total nodes: " << index << std::endl;
}
