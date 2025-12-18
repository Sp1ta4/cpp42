#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    bool isPositiveNumber(const std::string &s) const;
    void mergeInsertSortVector(std::vector<int> &v);
    void mergeInsertSortDeque(std::deque<int> &d);

public:
    PmergeMe() {}
    ~PmergeMe() {}

    void parseArguments(int argc, char **argv);
    void sortAndDisplay();
};
