
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.id = 42;
    data.name = "Alexandra";

    Data *ptr = &data;
    uintptr_t raw = Serializer::serialize(ptr);
    
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Id       : "<< ptr->id << std::endl;
    std::cout << "Name     : "<< ptr->name << std::endl << std::endl;

    Data* newPtr = Serializer::deserialize(raw);
    
    std::cout << "=== Deserialized Data ===" << std::endl;
    std::cout << "New Id   : "<< newPtr->id << std::endl;
    std::cout << "New Name : "<< newPtr->name << std::endl << std::endl;

    std::cout << "Pointer comparison: ";
    if (ptr == newPtr)
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;

    return 0;
}
