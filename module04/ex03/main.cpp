#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>
#include <sstream>

#define TITLE(title, color) \
    std::cout << std::endl << color << "=== " << title << " ===" << RESET << std::endl
#define SUB(title, color) \
    std::cout << color << "--- " << title << " ---" << RESET << std::endl

std::string to_string(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

int main()
{
    TITLE("Materia System Test", MAGENTA);

    SUB("Creating Materia Sources", BLUE);
    IMateriaSource* sources[2];
    for (int i = 0; i < 2; ++i)
    {
        std::cout << GREEN << "Creating source " << (i + 1) << RESET << std::endl;
        sources[i] = new MateriaSource();
    }

    SUB("Learning Materias", BLUE);
    for (int i = 0; i < 2; ++i)
    {
        std::cout << GREEN << "Learning in source " << (i + 1) << RESET << std::endl;
        sources[i]->learnMateria(new Ice());
        sources[i]->learnMateria(new Cure());
    }

    SUB("Creating Characters", BLUE);
    Character* me = new Character("me");
    Character* bob = new Character("bob");

    SUB("Equipping Materias", BLUE);
    AMateria* tmp;
    tmp = sources[0]->createMateria("ice");
    me->equip(tmp);
    tmp = sources[1]->createMateria("cure");
    me->equip(tmp);

    SUB("Using Materias", BLUE);
    me->use(0, *bob);
    me->use(1, *bob);

    SUB("Unequipping and Deleting", BLUE);
    me->unequip(0);
    me->unequip(1);
    delete me;
    delete bob;

    SUB("Deleting Sources", BLUE);
    for (int i = 0; i < 2; ++i)
    {
        std::cout << RED << "Deleting source " << (i + 1) << RESET << std::endl;
        delete sources[i];
    }

    TITLE("Test Complete", MAGENTA);
    return 0;
}