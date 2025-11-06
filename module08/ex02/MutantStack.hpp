#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <vector>
# include <deque>
# include <iostream>
# include <exception>
# include <list>

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define RESET		"\033[0m"


template <typename T>
class MutantStack : public std::stack<T> {
	public:

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other); 
		~MutantStack();

		typedef	std::deque<T> container;
		typedef	typename container::iterator iterator;
		typedef	typename container::const_iterator const_iterator;
		typedef	typename container::reverse_iterator reverse_iterator;
		typedef	typename container::const_reverse_iterator const_reverse_iterator;

		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

};

#include "MutantStack.tpp"


#endif