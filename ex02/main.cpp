#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "== Basic stack test ==" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n == Forward iteration ==" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while(it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n == Reverse iteration ==" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while(rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n == Const iteration == " << std::endl;

    const MutantStack<int> constStack(mstack); /// ??

    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();

    while(cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\n== Copy to std::stack ==" << std::endl;

    std::stack<int> s(mstack);

    std::cout << "std::stack size: " << s.size() << std::endl;
    std::cout << "std::stack top: " << s.top() << std::endl;

    std::cout << "\n == Comparison with std::list ==" << std::endl;

    std::list<int> list;

    list.push_back(5);
    // list.push_back(17);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::cout << "MutantStack: ";
    for(MutantStack<int>::iterator i = mstack.begin();
        i != mstack.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    std::cout << "std::list: ";
    for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    return 0;
}

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
    
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }