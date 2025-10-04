#ifndef CHAINEDLIST_HPP
#define CHAINEDLIST_HPP

#include "AMateria.hpp"

class ChainedList {
  private:
      struct Node {
          AMateria* materia;
          Node* next;
          Node(AMateria* m);
      };
      Node* head;
  public:
      ChainedList();
      ~ChainedList();
      ChainedList(const ChainedList& other);
      ChainedList& operator=(const ChainedList& other);
      
      void display() const;
      void add(AMateria* dropped);
      void clear();
};

#endif 
