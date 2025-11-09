#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);
    private: //constructeurs et destructeurs en prive pour rendre la classe non instanciable 
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};

#endif
