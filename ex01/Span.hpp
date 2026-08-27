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
 
};

