#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _inputData(other._inputData) {}

RPN::~RPN() {}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_inputData = other._inputData;
	return (*this);
}

bool	RPN::_isOperation(std::string &element) const
{
	return (element.find_first_of("+-*/") != std::string::npos);
}

bool	RPN::_isAllSpace(std::string &input) const
{
	for (size_t i = 0; i < input.size(); i++)
		if (!std::isspace(input[i]))
			return (false);
	return (true);
}

void	RPN::_trimElement(std::string &element) const
{
	size_t	start = element.find_first_not_of(" \t");
	size_t	end = element.find_last_not_of(" \t");

	if (start == std::string::npos)
		element = "";
	else
		element = element.substr(start, end - start + 1);
}

bool	RPN::_elementIsValid(std::string &element) const
{	
	if (element.size() != 1)
		return (false);
	
	if (_isOperation(element))
		return (true);
	
	if (!std::isdigit(element[0]))
		return (false);

	int	number = element[0] - '0';
	return (!(number < 0 || number > 9));
}

void	RPN::_splitInput(std::string &input)
{
	std::string			element;
	std::stringstream	ss(input);

	while (std::getline(ss, element, ' '))
	{
		_trimElement(element);
		if (element.empty())
			continue;
		
		if (_elementIsValid(element))
			_inputData.push_back(element);
		else
			throw std::runtime_error("Error");
	}
}

int	RPN::_calculate(int num1, int num2, std::string &operand) const
{
	if (operand == "+") return (num1 + num2);
	if (operand == "-") return (num1 - num2);
	if (operand == "*") return (num1 * num2);
	
	if (num2 == 0)
		throw std::runtime_error("Error");
	return (num1 / num2);
}

void	RPN::_processInput()
{
	int	num1, num2, result;

	for (std::list<std::string>::iterator it = _inputData.begin(); it != _inputData.end(); ++it)
	{
		if (_isOperation(*it))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			
			num2 = _stack.top();
			_stack.pop();
			num1 = _stack.top();
			_stack.pop();

			result = _calculate(num1, num2, *it);
			_stack.push(result);
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

void	RPN::start(std::string input)
{
	try
	{
		if (input.empty() || _isAllSpace(input))
			throw std::runtime_error("Error");

		_splitInput(input);
		_processInput();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}