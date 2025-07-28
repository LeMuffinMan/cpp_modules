
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main ()
{
  randomChump("Billy");
  Zombie *myHeapZombie = newZombie("Mina");
  myHeapZombie->_announce();

  delete myHeapZombie;
  return (0);
}
