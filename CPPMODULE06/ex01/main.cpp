#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>


int main() {
    Data data;
    data.num = 42;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw: " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);
    std::cout << ptr->num << std::endl;
    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    return 0;
}