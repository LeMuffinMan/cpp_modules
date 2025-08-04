
#include "Zombie.hpp"
#include <sstream>
#include <iostream>

int main (int ac, char **av)
{
  if (ac != 2)
  {
    std::cout << "Usage: ./program <positive_integer>" << std::endl;
    return 1;
  }
  std::string arg(av[1]);
  for (size_t i = 0; i < arg.length(); ++i)
  {
    if (!std::isdigit(arg[i]))
    {
      std::cout << "Error: invalid argument" << std::endl;
      return 1;
    }
  }
  std::istringstream iss(arg);
  int N;
  iss >> N;
  if (iss.fail() || !iss.eof() || N <= 0 || N > 10000000)
  {
    std::cout << "Error: invalid argument" << std::endl;
    return 1;
  }
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; ++i)
  {
    std::stringstream ss;
    ss << "Zombie_" << i;
    horde[i].setName(ss.str());
    horde[i].announce();
  }
  delete [] horde;
  return (0);
}
