#include "PmergeMe.hpp"

//Use ./PmergeMe $(shuf -i 1-100000 -n 3000) for testing with large input

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
    {
        sorter.parseArguments(argc, argv);
        sorter.sortAndDisplay();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
