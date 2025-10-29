#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void) {
    std::srand(std::time(nullptr));
    
    int random = std::rand() % 3;
    switch (random) {
        case 0:
            std::cout << "Generated an A instance" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated a B instance" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated a C instance" << std::endl;
            return new C();
        default:
            return nullptr;
    }
}
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}