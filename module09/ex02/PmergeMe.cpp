#include "PmergeMe.hpp"

bool PmergeMe::isPositiveNumber(const std::string &s) const
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    return std::atoll(s.c_str()) > 0;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;

    size_t mid = v.size() / 2;
    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());

    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
        v[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return;

    size_t mid = d.size() / 2;
    std::deque<int> left(d.begin(), d.begin() + mid);
    std::deque<int> right(d.begin() + mid, d.end());

    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
        d[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < left.size()) d[k++] = left[i++];
    while (j < right.size()) d[k++] = right[j++];
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        if (!isPositiveNumber(s))
            throw std::runtime_error("Error");

        int num = std::atoi(s.c_str());
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

void PmergeMe::sortAndDisplay()
{
    // Before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    // Sort vector
    clock_t startVec = clock();
    mergeInsertSortVector(_vec);
    clock_t endVec = clock();
    double durVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    // Sort deque
    clock_t startDeq = clock();
    mergeInsertSortDeque(_deq);
    clock_t endDeq = clock();
    double durDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    // After
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    // Time
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << durVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << durDeq << " us" << std::endl;
}
