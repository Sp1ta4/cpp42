#pragma once

#include <iostream>   
#include <cstdlib>
#include <stdexcept>  
#include <cctype>     
#include <string>     
#include <algorithm>
#include <ctime>    
#include <vector>     
#include <deque>      
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        bool isPositiveNumber(const std::string &s) const;

        void fordJohnsonSortVector(std::vector<int> &v);
        void insertPendVector(std::vector<int> &mainChain,
                              const std::vector<int> &pend);
        void fordJohnsonSortDeque(std::deque<int> &d);
        void insertPendDeque(std::deque<int> &mainChain,
                             const std::deque<int> &pend);
        std::vector<size_t> buildJacobsthalSequence(size_t n);

    public:
        PmergeMe();

        void parseArguments(int argc, char **argv);
        void sortAndDisplay();
};