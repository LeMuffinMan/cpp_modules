#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "Test";
    data.value = 24;

    std::cout << "Before serialization data: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "after deserialization data: " << ptr << std::endl;

    // if (ptr == &data) {
    //     std::cout << "✅ Success: Pointer matches!" << std::endl;
    //     std::cout << "Data contents -> id: " << ptr->id
    //               << ", name: " << ptr->name
    //               << ", value: " << ptr->value << std::endl;
    // } else {
    //     std::cout << "❌ Error: Pointer does not match!" << std::endl;
    // }

    return 0;
}
