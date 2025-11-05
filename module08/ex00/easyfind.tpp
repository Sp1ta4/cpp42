template <typename T>
typename T::const_iterator easyfind(const T &a, int b)
{
	typename T::const_iterator it = a.begin();

	for (; it != a.end(); it++)
	{
		if (*it == b)
			return (it);
	}
	throw std::runtime_error("Not Found!");
}

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator it = a.begin();

	for (; it != a.end(); it++)
	{
		if (*it == b)
			return (it);
	}
	throw std::runtime_error("Not Found!");
}