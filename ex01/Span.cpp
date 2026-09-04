#include "Span.hpp"
#include <iterator>
#include <algorithm>
#include <climits>

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
    if (numbers.size() >= N)
        throw NoSpaceException();
    numbers.push_back(number);
}

int Span::shortestSpan() 
{
    if(numbers.size() < 2)
        throw cannotFindException();

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int shortest = INT_MAX;
    for(std::vector<int>::size_type i = 1; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() 
{
    if(numbers.size() < 2)
        throw cannotFindException();
    
    int smallest = *std::min_element(numbers.begin(), numbers.end());
    int largest = *std::max_element(numbers.begin(), numbers.end());

    return largest - smallest;
}


const char* Span::NoSpaceException::what() const throw()
{
    return "Error: Already full. Cannot add more";
}


const char* Span::cannotFindException::what() const throw()
{
    return "Error: No numbers stored or only one; no span can be found.";
}

