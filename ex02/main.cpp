#include "Base.hpp"
#include <iostream>

int main() {
    Base* instance = generate();
    
    std::cout << "Identifying using pointer: ";
    identify(instance);
    
    std::cout << "Identifying using reference: ";
    identify(*instance);
    
    delete instance;
    
    return 0;
}