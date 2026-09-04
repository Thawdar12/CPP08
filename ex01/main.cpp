#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

// testing with 10000 numbers and exceptions
// #include "Span.hpp"
// #include <iostream>
// #include <vector>

// int main()
// {
//     try
//     {
//         Span bigSpan(10000);
//         std::vector<int> values;

//         for (int i = 0; i < 10000; ++i)
//             values.push_back(i * 2);

//         bigSpan.addNumber(values.begin(), values.end());

//         std::cout << "Shortest: "
//                   << bigSpan.shortestSpan()
//                   << std::endl;

//         std::cout << "Longest: "
//                   << bigSpan.longestSpan()
//                   << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     // no space exception
//     try
//     {
//         Span smallSpan(3);
//         std::vector<int> values;

//         values.push_back(1);
//         values.push_back(2);
//         values.push_back(3);
//         values.push_back(4);

//         std::cout << std::endl;
//         std::cout << "TEST 2" << std::endl;

//         smallSpan.addNumber(values.begin(), values.end());

//         // We should NEVER reach here
//         std::cout << "ERROR: No exception was thrown!" << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }

//     // empty/ only one exception
//     try
//     {
//         Span smallSpan(3);
//         std::vector<int> values;

//         values.push_back(1);
//         // values.push_back(2);
//         // values.push_back(3);
//         // values.push_back(4);

//         std::cout << std::endl;
//         std::cout << "TEST 3" << std::endl;

//         smallSpan.addNumber(values.begin(), values.end());
//         std::cout << smallSpan.shortestSpan() << std::endl;
//         std::cout << smallSpan.longestSpan() << std::endl;
//         // We should NEVER reach here
//         std::cout << "ERROR: No exception was thrown!" << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }

//     return 0;
// }


