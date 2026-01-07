#include "Array.hpp"
#include "arrayTemplate.hpp"
#include <iostream>

int main() {
  try {
    int *a = new int();
    std::cout << "int* a = new int(); *a = " << *a << std::endl;
    delete a;
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

    Array<double> doubleArray(2);
    std::cout << "doubleArray[0] = " << doubleArray[0]
              << ", doubleArray[1] = " << doubleArray[1] << std::endl;

    Array<bool> boolArray(2);
    std::cout << std::boolalpha << "boolArray[0] = " << boolArray[0]
              << ", boolArray[1] = " << boolArray[1] << std::endl;

    Array<int *> ptrArray(2);
    std::cout << "ptrArray[0] = " << ptrArray[0]
              << ", ptrArray[1] = " << ptrArray[1] << std::endl;

    std::cout << "Atrempt to read un out of limit index in array" << std::endl;
    // this should trigger the try catch
    std::cout << array1[10] << std::endl;

  } catch (std::exception &e) {
    std::cerr << "exception caught : " << e.what() << std::endl;
  }

  return 0;
}
