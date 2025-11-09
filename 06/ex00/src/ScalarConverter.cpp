#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

enum Type {
    T_CHAR,
    T_INT,
    T_FLOAT,
    T_DOUBLE,
    T_NAN,
    T_POS_INF,
    T_NEG_INF,
    T_INVALID,
}; 

static bool isChar(const std::string& literal)
{
    if (literal.length() == 3)
    {
        if (literal[0] == '\'' && literal[2] == '\'' && isprint(literal[1]) != 0)
            return true;
    }
    return false;
}

static bool isInt(const std::string& literal)
{
    int start = 0;
    if (literal[0] == '+' || literal[0] == '-') {
        start = 1;
        if (literal.length() == 1)
            return false;
    }
    for (int i = start; i < static_cast<int>(literal.length()); i++) {
        if (!isdigit(literal[i]) || i == std::numeric_limits<int>::max()) 
            return false;
    }

    return true;
}

static bool isDouble(const std::string& literal)
{
    int dot = 0;
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() == 1)
            return false;
        start = 1;
    }
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (dot == 0)
                dot = 1;
            else
                return false;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return true; //checker si au moins un digit ?
}

static bool isFloat(const std::string& literal)
{
    if (literal[literal.length() - 1] != 'f')
        return false;

    std::string shorten_literal = literal.substr(0, literal.length() - 1);
    return isDouble(shorten_literal);
}

static Type getType(const std::string& literal)
{
	if (literal.empty())
	    return T_INVALID;
    if (literal == "nan" || literal == "nanf")
        return T_NAN;
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
        return T_POS_INF;
    else if (literal == "-inf" || literal == "-inff")
        return T_NEG_INF;
    else if (isChar(literal))
        return T_CHAR;
    else if (isInt(literal))
        return T_INT;
    else if (isFloat(literal))
        return T_FLOAT;
    else if (isDouble(literal))
        return T_DOUBLE;
    else
        return T_INVALID;
}

static void printChar(const std::string& literal, Type type)
{
    std::cout << "char: ";
    switch (type)
    {
        case T_CHAR:
            {
                std::cout << literal[1];
                break;
            }
        case T_INT:
            {
                std::cout << "Non displayable";
                //des erreurs a gerer ?
                break;
            }
        case T_FLOAT:
            {
                float val = std::atof(literal.c_str());
                std::cout << val;
                //des erreurs a gerer ?
                break;
            }
        case T_DOUBLE:
            {
                std::cout << std::strtod(literal.c_str(), NULL);
                break;
            }
        case T_NAN:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_POS_INF:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_NEG_INF:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_INVALID:
            {
                std::cout << "impossible";
                break;
            }
    }
    std::cout << std::endl;
}

static void printInt(const std::string& literal, Type type)
{
    std::cout << "int: ";
    switch (type)
    {
        case T_CHAR:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_INT:
            {
                for (size_t i = 0; i < literal.length(); i++)
                    std::cout << literal[i];
                break;
            }
        case T_FLOAT:
            {
                for (size_t i = 0; i < literal.length(); i++)
                    std::cout << literal[i];
                std::cout << "f";
                break;
            }
        case T_DOUBLE:
            {
                for (size_t i = 0; i < literal.length(); i++)
                    std::cout << literal[i];
                break;
            }
        case T_NAN:
            {
                std::cout << "impossible";
                break;
            }
        case T_POS_INF:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_NEG_INF:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_INVALID:
            {
                std::cout << "nan";
                break;
            }
    }
    std::cout << std::endl;
}

static void printFloat(const std::string& literal, Type type)
{
    std::cout << "float: ";
    switch (type)
    {
        case T_CHAR:
            {
                std::cout << "*";
                break;
            }
        case T_INT:
            {
                for (size_t i = 0; i < literal.length(); i++)
                {
                    if (!std::isdigit(literal[i]))
                        break;
                    std::cout << literal[i];
                }
                break;
            }
        case T_FLOAT:
            {
                for (size_t i = 0; i < literal.length(); i++)
                    std::cout << literal[i];
                break;
            }
        case T_DOUBLE:
            {
                for (size_t i = 0; i < literal.length() - 1; i++)
                    std::cout << literal[i];
                break;
            }
        case T_NAN:
            {
                std::cout << "nanf";
                break;
            }
        case T_POS_INF:
            {
                std::cout << "Non displayable"; // tenter quand meme ?
                break;
            }
        case T_NEG_INF:
            {
                std::cout << "Non displayable"; // tenter quand meme ?
                break;
            }
        case T_INVALID:
            {
                std::cout << "nanf";
                break;
            }
    }
    std::cout << std::endl;
}

static void printDouble(const std::string& literal, Type type)
{
    std::cout << "double: ";
    switch (type)
    {
        case T_CHAR:
            {
                std::cout << "Non displayable";
                break;
            }
        case T_INT:
            {
                for (size_t i = 0; i < literal.length() - 1; i++)
                {
                    if (!std::isdigit(literal[i]))
                        break;
                    std::cout << literal[i];
                }
                break;
            }
        case T_FLOAT:
            {
                for (size_t i = 0; i < literal.length() - 1; i++)
                    std::cout << literal[i];
                std::cout << "f";
                break;
            }
        case T_DOUBLE:
            {
                for (size_t i = 0; i < literal.length() - 1; i++)
                    std::cout << literal[i];
                break;
            }
        case T_NAN:
            {
                std::cout << "nan";
                break;
            }
        case T_POS_INF:
            {
                std::cout << "Non displayable"; // tenter quand meme ?
                break;
            }
        case T_NEG_INF:
            {
                std::cout << "Non displayable"; // tenter quand meme ?
                break;
            }
        case T_INVALID:
            {
                std::cout << "nan";
                break;
            }
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    Type type = getType(literal);

    if (type == T_INVALID) // !!!! 
        return ; // afficher l'erreur 

    printChar(literal, type);
    printInt(literal, type);
    printFloat(literal, type);
    printDouble(literal, type);
}
