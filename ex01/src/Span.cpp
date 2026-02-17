#include "Span.hpp"

Span::Span()
    : _n(0)
{
}

Span::~Span()
{
}

Span::Span(unsigned int n)
    : _n(n)
{
}

Span::Span(const Span &other)
{
    this->_n = other._n;
    this->_numbers = other._numbers;
}

Span& Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->_n = other._n;
        this->_numbers = other._numbers;
        return(*this);
    }
    return(*this);
}

unsigned int Span::shortestSpan() const
{
    if(this->_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp = this->_numbers;
    std::sort(tmp.begin(), tmp.end());

    unsigned int minSpan = -1;
    for(size_t i = 0; i < tmp.size() - 1; ++i)
    {
        unsigned int diff = tmp[i + 1] - tmp[i];
        if(diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}

unsigned int Span::longestSpan() const
{
    if(this->_numbers.size() < 2)
        throw NoSpanException();
    
    int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    
	return (static_cast<unsigned int>(max - min));
}

void	Span::addNumber(int number)
{
	if(this->_numbers.size() >= this->_n)
		throw FullSpanException();
	this->_numbers.push_back(number);
}
