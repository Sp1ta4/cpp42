#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_inputData = other._inputData;
		_stack = other._stack;
	}
	return (*this);
}

bool	RPN::_isOperation(const std::string &element) const
{
	return (element.size() == 1
		&& std::string("+-*/").find(element[0]) != std::string::npos);
}

bool	RPN::_isAllSpace(const std::string &input) const
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(input[i])))
			return (false);
	}
	return (true);
}

void	RPN::_trimElement(std::string &element) const
{
	size_t	start = element.find_first_not_of(" \t");
	size_t	end = element.find_last_not_of(" \t");

	if (start == std::string::npos)
		element.clear();
	else
		element = element.substr(start, end - start + 1);
}

bool	RPN::_elementIsValid(const std::string &element) const
{
	if (element.size() != 1)
		return (false);

	if (_isOperation(element))
		return (true);

	return (std::isdigit(static_cast<unsigned char>(element[0])));
}

void	RPN::_splitInput(const std::string &input)
{
	std::stringstream	ss(input);
	std::string			element;

	_inputData.clear();

	while (ss >> element)
	{
		if (!_elementIsValid(element))
			throw std::runtime_error("Error");
		_inputData.push_back(element);
	}
}

int	RPN::_calculate(int num1, int num2, const std::string &operand) const
{
	if (operand == "+")
		return (num1 + num2);
	if (operand == "-")
		return (num1 - num2);
	if (operand == "*")
		return (num1 * num2);
	if (operand == "/")
	{
		if (num2 == 0)
			throw std::runtime_error("Error");
		return (num1 / num2);
	}
	throw std::runtime_error("Error");
}

void	RPN::_processInput()
{
	int	num1;
	int	num2;

	while (!_stack.empty())
		_stack.pop();

	for (std::list<std::string>::const_iterator it = _inputData.begin();
		it != _inputData.end(); ++it)
	{
		if (_isOperation(*it))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			num2 = _stack.top();
			_stack.pop();
			num1 = _stack.top();
			_stack.pop();

			_stack.push(_calculate(num1, num2, *it));
		}
		else
		{
			_stack.push((*it)[0] - '0');
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	std::cout << _stack.top() << std::endl;
}

void	RPN::start(const std::string &input)
{
	try
	{
		if (input.empty() || _isAllSpace(input))
			throw std::runtime_error("Error");

		_splitInput(input);
		_processInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
