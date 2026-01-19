#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

bool PmergeMe::isPositiveNumber(const std::string &s) const
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    std::istringstream iss(s);
    long long value;
    iss >> value;

    return (!iss.fail() && iss.eof() && value > 0);
}


std::vector<size_t> PmergeMe::buildJacobsthalSequence(size_t n)
{
    std::vector<size_t> j;
    j.push_back(1);
    j.push_back(3);

    while (j.back() < n)
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);

    return j;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;

    bool hasStraggler = (v.size() % 2 != 0);
    int straggler = 0;

    if (hasStraggler)
    {
        straggler = v.back();
        v.pop_back();
    }

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (v[i] < v[i + 1])
        {
            pend.push_back(v[i]);
            mainChain.push_back(v[i + 1]);
        }
        else
        {
            pend.push_back(v[i + 1]);
            mainChain.push_back(v[i]);
        }
    }

    fordJohnsonSortVector(mainChain);
    insertPendVector(mainChain, pend);

    if (hasStraggler)
    {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    v = mainChain;
}

void PmergeMe::insertPendVector(std::vector<int> &mainChain,
                                const std::vector<int> &pend)
{
    if (pend.empty())
        return;

    mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<size_t> jacob = buildJacobsthalSequence(pend.size());

    size_t inserted = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t limit = std::min(jacob[i], pend.size());
        while (inserted < limit)
        {
            std::vector<int>::iterator it =
                std::lower_bound(mainChain.begin(),
                                 mainChain.begin() + inserted + i,
                                 pend[inserted]);
            mainChain.insert(it, pend[inserted]);
            ++inserted;
        }
    }
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return;

    bool hasStraggler = (d.size() % 2 != 0);
    int straggler = 0;

    if (hasStraggler)
    {
        straggler = d.back();
        d.pop_back();
    }

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i < d.size(); i += 2)
    {
        if (d[i] < d[i + 1])
        {
            pend.push_back(d[i]);
            mainChain.push_back(d[i + 1]);
        }
        else
        {
            pend.push_back(d[i + 1]);
            mainChain.push_back(d[i]);
        }
    }

    fordJohnsonSortDeque(mainChain);
    insertPendDeque(mainChain, pend);

    if (hasStraggler)
    {
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    d = mainChain;
}

void PmergeMe::insertPendDeque(std::deque<int> &mainChain,
                               const std::deque<int> &pend)
{
    if (pend.empty())
        return;

    mainChain.push_front(pend[0]);

    std::vector<size_t> jacob = buildJacobsthalSequence(pend.size());

    size_t inserted = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t limit = std::min(jacob[i], pend.size());
        while (inserted < limit)
        {
            std::deque<int>::iterator it =
                std::lower_bound(mainChain.begin(),
                                 mainChain.begin() + inserted + i,
                                 pend[inserted]);
            mainChain.insert(it, pend[inserted]);
            ++inserted;
        }
    }
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        if (!isPositiveNumber(s))
            throw std::runtime_error("Error");

        std::istringstream iss(s);
        int value;
        iss >> value;

        _vec.push_back(value);
        _deq.push_back(value);
    }
}


void PmergeMe::sortAndDisplay()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t vStart = clock();
    fordJohnsonSortVector(_vec);
    clock_t vEnd = clock();

    clock_t dStart = clock();
    fordJohnsonSortDeque(_deq);
    clock_t dEnd = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double vecTime =
        static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1000000.0;
    double deqTime =
        static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : "
              << deqTime << " us" << std::endl;
}
