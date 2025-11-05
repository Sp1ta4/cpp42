#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>
# include <list>
# include <deque>
# include <cstdlib>
# include <ctime>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_data;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		template <typename T>
		void addNumbers(T begin, T end);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
};

template <typename T>
void Span::addNumbers(T begin, T end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

#endif