#pragma once

#include <iostream>
#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        class NoSpaceException : public std::exception
        {
            public:
                const char* what() const throw();

        };
     
        class cannotFindException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (numbers.size()
                + static_cast<unsigned int>(std::distance(begin, end)) > N)
                throw NoSpaceException();

            numbers.insert(numbers.end(), begin, end);
        }
};

