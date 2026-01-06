#include <iostream>
#include "Array.hpp"
#include "arrayTemplate.hpp"

// try to compile int * a = new int(); then display *a

int main() {
    try {
        Array<int> array1(5);
        for (size_t i = 0; i < array1.size(); i++) {
            array1[i] = i * 10;
        }

        std::cout << "array1 (" << &array1 << ") : ";
        for (size_t i = 0; i < array1.size(); i++)
            std::cout << array1[i] << " ";
        std::cout << std::endl;

        std::cout << "copying array1 in array2 " << std::endl;
        Array<int> array2 = array1;
        std::cout << "modifying array2 (" << &array2 << ") " << std::endl;
        array2[0] = 42;

        std::cout << "array1 (" << &array1 << ") : ";
        for (size_t i = 0; i < array1.size(); i++)
            std::cout << array1[i] << " ";
        std::cout << std::endl;

        std::cout << "array2 (" << &array2 << ") : ";
        for (size_t i = 0; i < array2.size(); i++)
            std::cout << array2[i] << " ";
        std::cout << std::endl;

        //this should trigger the try catch
        std::cout << array1[10] << std::endl;

    } catch (std::exception& e) {
        std::cerr << "exception caught : " << e.what() << std::endl;
    }

    return 0;
}
