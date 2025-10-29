#include <iostream>
#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "Sample Data";
    original.value = 3.14159;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "ID: " << original.id << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Value: " << original.value << std::endl;
    std::cout << "Address: " << &original << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "\nSerialized value (uintptr_t): " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    
    if (&original == deserialized)
        std::cout << "\nSuccess! Original and deserialized pointers match." << std::endl;
    else
        std::cout << "\nError! Pointers don't match." << std::endl;
    
    return 0;
}