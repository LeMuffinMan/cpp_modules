
#include <fstream>
#include <iostream>

int replace (char **argv, std::string str)
{
  std::ofstream outfile;
  int pos;

  //error si argc != 4
  //error si s1 est null
  outfile.open((std::string(argv[1]) + ".replace").c_str());
  //outfile.good() ?
  if (outfile.fail())
    return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else // si pos == -1 error ?
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int main (int ac, char **argv)
{
  std::ifstream infile;
  char c;
  std::string str;
  if (ac != 4)
  {
    std::cout << "Usage : ./sed <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  infile.open(argv[1]);
  if (infile.fail())
  {
    std::cout << "Error opening \"" << argv[1] << "\"" << std::endl;
    return (1);
  }
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return (replace(argv, str));
}
