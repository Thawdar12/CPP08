#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    // VECTOR TESTS
    std::cout << "========== VECTOR TESTS ==========" << std::endl;

    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(20);
    numbers.push_back(40);

    std::cout << "Vector: ";
    std::vector<int>::iterator vectorPrint = numbers.begin();
    while (vectorPrint != numbers.end())
    {
        std::cout << *vectorPrint << " ";
        ++vectorPrint;
    }
    std::cout << std::endl;

    try
    {
        std::vector<int>::iterator it;

        it = easyfind(numbers, 20);
        std::cout << "Find 20: " << *it << std::endl;
        std::cout << "Index: " << it - numbers.begin() << std::endl;

        it = easyfind(numbers, 10);
        std::cout << "Find first element (10): " << *it << std::endl;

        it = easyfind(numbers, 40);
        std::cout << "Find last element (40): " << *it << std::endl;
        
        it = easyfind(numbers, 30);
        std::cout << "Find middle element (30): " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test value not found
    try
    {
        std::vector<int>::iterator it;

        it = easyfind(numbers, 100);
        std::cout << "Find 100: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Find 100: Error: " << e.what() << std::endl;
    }


    // EMPTY VECTOR TEST
    std::cout << "\n========== EMPTY VECTOR TEST ==========" << std::endl;

    std::vector<int> empty;

    std::cout << "Vector: empty" << std::endl;

    try
    {
        std::vector<int>::iterator it;

        it = easyfind(empty, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    // LIST TESTS
    std::cout << "\n========== LIST TESTS ==========" << std::endl;

    std::list<int> numbersList;

    numbersList.push_back(1);
    numbersList.push_back(2);
    numbersList.push_back(3);
    numbersList.push_back(2);
    numbersList.push_back(5);

    std::cout << "List: ";

    std::list<int>::iterator listPrint = numbersList.begin();
    while (listPrint != numbersList.end())
    {
        std::cout << *listPrint << " ";
        ++listPrint;
    }
    std::cout << std::endl;

    try
    {
        std::list<int>::iterator it;


        it = easyfind(numbersList, 2);
        std::cout << "Find 2: " << *it << std::endl;

        // Show position
        std::cout << "Distance from begin: "
                  << std::distance(numbersList.begin(), it)
                  << std::endl;

        it = easyfind(numbersList, 1);
        std::cout << "Find first element (1): " << *it << std::endl;

        it = easyfind(numbersList, 5);
        std::cout << "Find last element (5): " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test value not found
    try
    {
        std::list<int>::iterator it;

        it = easyfind(numbersList, 100);
        std::cout << "Find 100: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Find 100: Error: " << e.what() << std::endl;
    }


    // DEQUE TESTS
    std::cout << "\n========== DEQUE TESTS ==========" << std::endl;

    std::deque<int> numbersDeque;

    numbersDeque.push_back(10);
    numbersDeque.push_back(20);
    numbersDeque.push_back(30);
    numbersDeque.push_back(20);
    numbersDeque.push_back(40);

    std::cout << "Deque: ";

    std::deque<int>::iterator dequePrint = numbersDeque.begin();
    while (dequePrint != numbersDeque.end())
    {
        std::cout << *dequePrint << " ";
        ++dequePrint;
    }
    std::cout << std::endl;

    try
    {
        std::deque<int>::iterator it;

        it = easyfind(numbersDeque, 20);
        std::cout << "Find 20: " << *it << std::endl;

        // Deque supports random access like vector
        std::cout << "Index: "
                  << it - numbersDeque.begin()
                  << std::endl;

        it = easyfind(numbersDeque, 10);
        std::cout << "Find first element (10): " << *it << std::endl;

        it = easyfind(numbersDeque, 40);
        std::cout << "Find last element (40): " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test value not found
    try
    {
        std::deque<int>::iterator it;

        it = easyfind(numbersDeque, 100);
        std::cout << "Find 100: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Find 100: Error: " << e.what() << std::endl;
    }

    return 0;
}
