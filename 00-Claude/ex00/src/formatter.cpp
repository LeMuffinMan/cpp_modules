#include <cctype>
#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    std::string str;
    int i;
    int j;
    int count;

    if (argc <= 2 || argv[1][0] != '-' || argv[1][1] != '-')
    {
        std::cout << "Usage: ./formatter [--upper | --lower | --reverse | --count] <str> <str> <str> ..." << std::endl;
        return 1;
    }
    if (std::strcmp(argv[1], "--upper") == 0)
    {
        i = 2;
	    while (i < argc)
	    {
	        j = 0;
		    while (argv[i][j])
		    {
			    std::cout << (char) std::toupper(argv[i][j]);
			    j++;
		    }
		    i++;
		    if (i == argc)
		        std::cout << std::endl;
		    else
		        std::cout << " ";
	    }
	}
    else if (std::strcmp(argv[1], "--lower") == 0)
    {
        i = 2;
	    while (i < argc)
	    {
	        j = 0;
		    while (argv[i][j])
		    {
			    std::cout << (char) std::tolower(argv[i][j]);
			    j++;
		    }
		    i++;
		    if (i == argc)
		        std::cout << std::endl;
		    else
		        std::cout << " ";
	    }
	}
    else if (std::strcmp(argv[1], "--reverse") == 0)
    {
        i = 2;
	    while (i < argc)
	    {
	        j = 0;
	        while (argv[i][j])
	            j++;
	        j--;
		    while (j >= 0)
		    {
			    std::cout << (char) argv[i][j];
			    j--;
		    }
		    i++;
		    if (i == argc)
		        std::cout << std::endl;
		    else
		        std::cout << " ";
	    }
    }
    else if (std::strcmp(argv[1], "--count") == 0)
    {
        i = 2;
        while (i < argc)
        {
            count = 0;
            while (argv[i][count])
            {
                count++;
            }
	        j = 0;
		    while (argv[i][j])
		    {
			    std::cout << (char) argv[i][j];
			    j++;
		    }
            std::cout << ": " << count << " characters" << std::endl;
            i++;
        }
    }
    else 
        std::cout << "Incorrect format" << std::endl;
    return 0;
}
