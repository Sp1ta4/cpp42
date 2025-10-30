#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate()
{
    int randomValue = std::rand() % 3;

    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base* obj)
{
    if (dynamic_cast<A*>(obj))
        std::cout << "is A";
    else if (dynamic_cast<B*>(obj))
        std::cout << "is B";
    else if (dynamic_cast<C*>(obj))
        std::cout << "is C";
    else
        std::cout << "unknown";
}

void Base::identify(Base& obj)
{
    try {
        (void)dynamic_cast<A&>(obj);
        std::cout << "is A";
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(obj);
        std::cout << "is B";
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(obj);
        std::cout << "is C";
        return;
    } catch (std::bad_cast&) {}

    std::cout << "unknown";
}
