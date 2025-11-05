#include "Span.hpp"

Span::Span() : _N(10)
{
	_data.reserve(_N);
}

Span::Span(unsigned int N) : _N(N)
{
	_data.reserve(_N);
}

Span::Span(const Span &other) 
	: _N(other._N)
	, _data(other._data)
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_data = other._data;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_data.size() >= _N)
		throw std::runtime_error("Span is full");
	_data.push_back(n);
}

int Span::shortestSpan()
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	long shortest = LONG_MAX;
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return static_cast<int>(shortest);
}

int Span::longestSpan()
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());
	return maxVal - minVal;
}


Span::~Span() {}