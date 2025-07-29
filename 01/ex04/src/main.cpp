
#include <fstream>
#include <iostream>

int replace (char **av, std::string str)
{
  std::ofstream outfile;
  int pos;

  outfile.open((std::string(av[1]) + ".replace").c_str());
  if (outfile.fail())
    return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int main (int ac, char **av)
{
  std::ifstream infile;
  char c;
  std::string str;
  if (ac != 4)
  {
    std::cout << "Usage : ./sed <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  infile.open(av[1]);
  if (infile.fail())
  {
    std::cout << "Error opening \"" << av[1] << "\"" << std::endl;
    return (1);
  }
	while(!infile.eof() && infile >> std::noskipws >> c) //a revoir
		str += c;
	infile.close();
	return (replace(av, str));
}
