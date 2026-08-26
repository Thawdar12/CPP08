#pragma once
#include <exception>
#include <algorithm>

class ContainerException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Cannot find!";
        }
};


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    
    it = std::find(
        container.begin(),
        container.end(),
        value
    );

    if (it == container.end())
        throw ContainerException();
    return it;
}
