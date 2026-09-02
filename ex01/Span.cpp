#include "Span.hpp"

// unsigned int N;
// std::vector<int> numbers;

Span::Span() : N(0) {}

Span::Span(unsigned int n) 
    : N(n)
{
    // asking to reserve n number of space.
    // with this even after calling this constructor, 
    // the numbers.size() will still be 0
    numbers.reserve(n);
}

Span::Span(const Span& other)
    : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) 
{
    if (this != &other)
    {
        N = other.N;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) 
{
    if (numbers.size() == N)
        throw NoSpaceException();
    numbers.push_back(number);
}

int Span::shortestSpan() 
{

}

int Span::longestSpan() 
{

}


const char* Span::NoSpaceException::what() const throw()
{
    return "Already full. Cannot add more";
}

 
const char* Span::cannotFindException::what() const throw()
{
    return "No numbers stored or only one, no span can be found.";
}
