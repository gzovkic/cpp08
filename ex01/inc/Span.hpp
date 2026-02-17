#pragma once 

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iterator>
#include <exception>
#include <vector>

class Span
{
    public:
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
    
		Span(unsigned int n);
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename T>
		void addRange(T begin, T end);

		class FullSpanException : public std::exception
		{
            virtual const char* what() const throw()
			{
				return "Span is already full";
			}
        };
        class NoSpanException : public std::exception
		{
            virtual const char* what() const throw()
			{
				return "Not enough numbers to find a span";
			}
        };
    private:
		unsigned int _n;
		std::vector<int> _numbers;
		Span();
};

template <typename T>
void Span::addRange(T begin, T end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_n)
		throw FullSpanException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}
