#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &a, int b)
{
    typename T::const_iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::runtime_error("Not Found!");
    return it;
}

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::runtime_error("Not Found!");
    return it;
}