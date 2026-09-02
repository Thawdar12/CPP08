*this is more like a personal note than a readme*

# CPP08 — STL, Containers, Iterators & Algorithms

## Introduction

CPP08 is mainly about the **STL (Standard Template Library)**.

The STL gives us ready-made tools for working with:

* Data structures → **containers**
* Walking through data → **iterators**
* Operating on data → **algorithms**
* Generic code → **templates**

The main idea is:

```text
                    STL
                     |
        +------------+------------+
        |            |            |
    Containers    Iterators   Algorithms
        |            |            |
     store data   walk data    process data
```

---

# 1. What is STL?

**STL = Standard Template Library**

It is a collection of generic C++ tools that we can use instead of writing common data structures and algorithms ourselves.

For example, instead of creating our own dynamic array:

```cpp
std::vector<int> numbers;
```

We can use the STL `vector`.

```cpp
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Now we have:

```text
10  20  30
```

The STL is built around **templates**, so the same container can work with different types:

```cpp
std::vector<int>
std::vector<double>
std::vector<std::string>
```

---

# 2. The 3 Most Important STL Concepts

Remember:

```text
Container = stores the data

Iterator = walks through the data

Algorithm = does something with the data
```

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(30);
numbers.push_back(10);
numbers.push_back(20);
```

The vector stores the data:

```text
30  10  20
```

An iterator walks through it:

```text
     |
     v
30  10  20
```

An algorithm can process it:

```cpp
std::sort(numbers.begin(), numbers.end());
```

Result:

```text
10  20  30
```

---

# 3. Templates

Templates allow us to write code that works with different types.

Instead of creating:

```cpp
class IntStack
{
    // only int
};
```

We can create:

```cpp
template <typename T>
class MyStack
{
    // T can be different types
};
```

Then:

```cpp
MyStack<int> a;
MyStack<double> b;
MyStack<std::string> c;
```

Think:

```text
MyStack<T>

T = int
T = double
T = string
```

This is why STL containers look like:

```cpp
std::vector<int>
std::vector<double>
std::vector<std::string>
```

---

# 4. Containers

A container is an object that **stores a collection of data**.

Important STL containers for CPP08:

```text
Sequence containers:
    vector
    list
    deque

Associative containers:
    map
    set
    multimap
    multiset

Container adapters:
    stack
    queue
    priority_queue
```

---

# 5. Sequence Containers

Sequence containers store elements in a sequence/order.

## 5.1 vector

Think:

> Dynamic array.

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Conceptually:

```text
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
  0    1    2
```

We can access by index:

```cpp
numbers[0]; // 10
numbers[1]; // 20
numbers[2]; // 30
```

Useful functions:

```cpp
push_back()
pop_back()
size()
empty()
begin()
end()
```

---

## 5.2 list

Think:

> A chain of nodes.

Conceptually:

```text
+----+      +----+      +----+
| 10 | ---> | 20 | ---> | 30 |
+----+      +----+      +----+
```

Example:

```cpp
std::list<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Unlike `vector`, a `list` does not support:

```cpp
numbers[2];
```

Use iterators to move through it.

Useful functions:

```cpp
push_back()
push_front()
pop_back()
pop_front()
insert()
erase()
begin()
end()
size()
empty()
```

---

## 5.3 deque

`deque` means:

> Double-ended queue.

It allows efficient insertion/removal from both ends.

```cpp
std::deque<int> numbers;

numbers.push_back(20);
numbers.push_front(10);
numbers.push_back(30);
```

Result:

```text
10  20  30
```

It also supports indexing:

```cpp
numbers[1]; // 20
```

---

# 6. Associative Containers

**Associative** means that data is organized around a **key**.

Think:

```text
Sequence container:

position -> value


Associative container:

key -> value
```

Important associative containers:

```text
map
set
multimap
multiset
```

---

# 7. map

A `map` stores:

```text
KEY -> VALUE
```

Example:

```cpp
std::map<std::string, int> ages;

ages["Alice"] = 25;
ages["Bob"] = 30;
ages["Charlie"] = 20;
```

Conceptually:

```text
Alice   -> 25
Bob     -> 30
Charlie -> 20
```

Access using the key:

```cpp
std::cout << ages["Alice"];
```

Output:

```text
25
```

Think:

> `map` = dictionary.

Like:

```text
name -> phone number
student -> grade
country -> capital
```

---

# 8. set

A `set` stores **unique values**.

```cpp
std::set<int> numbers;

numbers.insert(10);
numbers.insert(20);
numbers.insert(10);
numbers.insert(30);
```

Result:

```text
10 20 30
```

The second `10` is not added.

Think:

```text
set = unique values
```

---

# 9. multiset

A `multiset` is like a `set`, but duplicates are allowed.

```cpp
std::multiset<int> numbers;

numbers.insert(10);
numbers.insert(10);
numbers.insert(20);
```

Result:

```text
10 10 20
```

Think:

```text
set      -> unique
multiset -> duplicates allowed
```

---

# 10. multimap

A `map` associates keys with values.

A `multimap` allows the same key multiple times.

```cpp
std::multimap<std::string, int> students;

students.insert(std::make_pair("Bob", 90));
students.insert(std::make_pair("Bob", 80));
students.insert(std::make_pair("Alice", 95));
```

Conceptually:

```text
Alice -> 95
Bob   -> 90
Bob   -> 80
```

Think:

```text
map      -> one key can identify one entry
multimap -> duplicate keys allowed
```

---

# 11. Container Adapters

Adapters provide a specific interface/behavior using another container internally.

Main adapters:

```text
stack
queue
priority_queue
```

What container is underneath?
This is where the word adapter becomes clearer.

stack
By default:
```text
stack
  ↓
deque
```

queue
By default:
```text
queue
  ↓
deque
```

priority_queue
By default:
```text
priority_queue
  ↓
vector
```

You can even specify another underlying container in some cases.
For example:
```cpp
std::stack<int, std::vector<int> > s;
```

Now:
```text
stack
  ↓
vector
```
The stack behavior stays the same.

---

# 12. stack

A stack follows:

> LIFO = Last In, First Out

Think about a stack of plates:

```text
     +----+
     | 30 | <- top
     +----+
     | 20 |
     +----+
     | 10 |
     +----+
```

Code:

```cpp
std::stack<int> s;

s.push(10);
s.push(20);
s.push(30);
```

Top:

```cpp
s.top(); // 30
```

Then:

```cpp
s.pop();
```

removes `30`.

Now:

```text
     +----+
     | 20 | <- top
     +----+
     | 10 |
     +----+
```

Important functions:

```cpp
push()
pop()
top()
size()
empty()
```

---

# 13. queue

A queue follows:

> FIFO = First In, First Out

Think about people waiting in line:

```text
First                          Last
  |                              |
  v                              v
+----+    +----+    +----+
| 10 | -> | 20 | -> | 30 |
+----+    +----+    +----+
```

The first person enters first and leaves first.

Important functions:

```cpp
push()
pop()
front()
back()
size()
empty()
```

---

# 14. Iterators

This is one of the most important STL concepts.

An iterator is like a **pointer that lets us walk through a container**.

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

We have:

```text
10  20  30
^
iterator
```

Create an iterator:

```cpp
std::vector<int>::iterator it;

it = numbers.begin();
```

Now:

```cpp
*it
```

means:

```text
10
```

---

# 15. Dereferencing an Iterator

An iterator behaves somewhat like a pointer.

Pointer:

```cpp
int *ptr;

*ptr
```

gets the value pointed to.

Iterator:

```cpp
std::vector<int>::iterator it;

*it
```

gets the current element.

So:

```cpp
std::cout << *it;
```

means:

> Print the element that the iterator currently points to.

---

# 16. ++it

If:

```text
10  20  30
^
it
```

then:

```cpp
++it;
```

moves the iterator:

```text
10  20  30
    ^
    it
```

Now:

```cpp
*it
```

is:

```text
20
```

Another:

```cpp
++it;
```

gives:

```text
10  20  30
         ^
         it
```

Now:

```cpp
*it
```

is:

```text
30
```

---

# 17. begin() and end()

This is very important.

Suppose:

```text
10  20  30
```

`begin()` points to the first element:

```text
begin()
   |
   v
10  20  30
```

`end()` points **one position after the last element**:

```text
10  20  30
         |
        end()
```

There is no valid element at `end()`.

Therefore, the standard loop is:

```cpp
for (std::vector<int>::iterator it = numbers.begin();
     it != numbers.end();
     ++it)
{
    std::cout << *it << std::endl;
}
```

---

# 18. The Standard Iterator Pattern

Memorize this:

```cpp
for (iterator it = container.begin();
     it != container.end();
     ++it)
{
    // use *it
}
```

Conceptually:

```text
begin()
  |
  v
[10] [20] [30]
              |
             end()
```

The iterator walks from `begin()` until it reaches `end()`.

---

# 19. const_iterator

A `const_iterator` lets us read elements but not modify them.

Normal iterator:

```cpp
std::vector<int>::iterator it;

*it = 42;
```

Allowed.

Const iterator:

```cpp
std::vector<int>::const_iterator it;
```

We can:

```cpp
std::cout << *it;
```

But not:

```cpp
*it = 42;
```

Think:

```text
iterator
    |
    +-- read
    +-- modify


const_iterator
    |
    +-- read only
```

---

# 20. Reverse Iterators

Normal iteration:

```text
10 20 30
^
begin()
```

goes:

```text
10 -> 20 -> 30
```

Reverse iteration goes:

```text
30 -> 20 -> 10
```

Use:

```cpp
rbegin()
rend()
```

Example:

```cpp
std::vector<int>::reverse_iterator it;

for (it = numbers.rbegin();
     it != numbers.rend();
     ++it)
{
    std::cout << *it << std::endl;
}
```

---

# 21. Algorithms

STL also provides algorithms that work with iterators.

Common ones:

```cpp
std::find()
std::sort()
std::count()
std::for_each()
```

The important idea:

```text
Container
    |
    | provides iterators
    v
Iterator range
    |
    v
Algorithm
```

---

# 22. std::find()

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Find `20`:

```cpp
std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 20);
```

If found:

```cpp
if (it != numbers.end())
    std::cout << "Found!" << std::endl;
```

If not found:

```text
it == numbers.end()
```

Important:

> Algorithms usually work on a range defined by `[begin, end)`.

That means:

```text
begin included
end NOT included
```

---

# 23. std::sort()

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(30);
numbers.push_back(10);
numbers.push_back(20);
```

Sort:

```cpp
std::sort(numbers.begin(), numbers.end());
```

Result:

```text
10 20 30
```

Again, `sort()` uses iterators:

```cpp
std::sort(
    numbers.begin(),
    numbers.end()
);
```

---

# 24. Predicates

A predicate is basically a function that answers:

```text
true / false
```

Example:

```cpp
bool isGreaterThan10(int n)
{
    return n > 10;
}
```

For:

```cpp
isGreaterThan10(20)
```

we get:

```text
true
```

For:

```cpp
isGreaterThan10(5)
```

we get:

```text
false
```

Predicates are commonly used with STL algorithms.

---

# 25. Functors

A functor is an object that behaves like a function.

Example:

```cpp
class IsGreaterThan10
{
public:
    bool operator()(int n) const
    {
        return n > 10;
    }
};
```

Now:

```cpp
IsGreaterThan10 check;

check(20);
```

works because we overloaded:

```cpp
operator()
```

Think:

```text
Object
  |
  +-- operator()
          |
          v
     behaves like
       a function
```

This becomes useful in later STL exercises.

---

# 26. std::pair

A `pair` stores two related values.

Example:

```cpp
std::pair<std::string, int> student;

student.first = "Bob";
student.second = 42;
```

Conceptually:

```text
first  -> Bob
second -> 42
```

You will often see:

```cpp
std::make_pair(...)
```

Example:

```cpp
std::make_pair("Bob", 42);
```

`std::map` uses pairs internally because each map element is basically:

```text
key + value
```

---

# 27. CPP08 Exercise Map

The three exercises are connected.

```text
CPP08
 |
 +-- ex00
 |     |
 |     +-- easyfind
 |          |
 |          +-- templates
 |          +-- containers
 |          +-- iterators
 |          +-- std::find
 |
 +-- ex01
 |     |
 |     +-- Span
 |          |
 |          +-- containers
 |          +-- iterators
 |          +-- algorithms
 |          +-- std::sort
 |          +-- exceptions
 |
 +-- ex02
       |
       +-- MutantStack
            |
            +-- templates
            +-- inheritance
            +-- std::stack
            +-- underlying container
            +-- iterators
```

---

# 28. CPP08 ex00 — easyfind

The goal is to create:

```cpp
easyfind(container, value)
```

which searches for an integer.

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

easyfind(numbers, 20);
```

The natural STL tool is:

```cpp
std::find()
```

Conceptually:

```text
easyfind
   |
   v
container.begin()
   |
   v
[10] [20] [30]
       ^
       |
      find
```

Main concepts:

```text
template
iterator
container
std::find
```

---

# 29. CPP08 ex01 — Span

The `Span` class stores numbers and calculates:

```cpp
shortestSpan()
longestSpan()
```

Example:

```cpp
Span sp(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
```

Numbers:

```text
6 3 17 9 11
```

After sorting:

```text
3 6 9 11 17
```

Shortest span:

```text
6 - 3 = 3
```

Longest span:

```text
17 - 3 = 14
```

Important STL concepts:

```text
container
iterator
std::sort
```

---

# 30. CPP08 ex02 — MutantStack

The normal:

```cpp
std::stack<int>
```

is not iterable.

We can:

```cpp
push()
pop()
top()
size()
```

But we cannot:

```cpp
begin()
end()
```

The exercise asks us to create:

```cpp
MutantStack<T>
```

which behaves like a stack but also provides iterators.

---

# 31. Why MutantStack works

`std::stack` is a **container adapter**.

Conceptually:

```text
std::stack
     |
     v
underlying container
     |
     v
std::deque
```

The underlying container is normally a `std::deque`.

The stack has an internal container, commonly represented as:

```cpp
protected:
    Container c;
```

Because it is `protected`, a derived class can access it.

So:

```cpp
template <typename T>
class MutantStack : public std::stack<T>
```

can use:

```cpp
this->c
```

Therefore:

```cpp
begin()
{
    return this->c.begin();
}
```

and:

```cpp
end()
{
    return this->c.end();
}
```

That's the main trick of ex02.

---

# 32. MutantStack Mental Model

Normal stack:

```text
      +----+
      |  30| <- top
      +----+
      |  20|
      +----+
      |  10|
      +----+

Can access:
top()
pop()
push()

Cannot iterate.
```

MutantStack:

```text
      +----+
      |  30| <- top
      +----+
      |  20|
      +----+
      |  10|
      +----+

Can access:
top()
pop()
push()

AND:

begin()
end()
iterator
```

The iterator accesses the underlying container.

---

# 33. Why the MutantStack Output Looks Like This

Suppose:

```cpp
mstack.push(5);
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
```

The top is:

```text
0
```

But the underlying container is:

```text
5 3 5 737 0
```

Therefore:

```cpp
for (MutantStack<int>::iterator it = mstack.begin();
     it != mstack.end();
     ++it)
{
    std::cout << *it << std::endl;
}
```

prints:

```text
5
3
5
737
0
```

Reverse iteration:

```text
0
737
5
3
5
```

---

# 34. Important: Stack vs Underlying Container

This is a common point of confusion.

The stack interface is:

```text
TOP
 |
 v
0
5
737
5
3
5
```

But the underlying container is stored in its own order:

```text
5 3 5 737 0
```

`top()` gives:

```text
0
```

Iteration through `c.begin()` starts at:

```text
5
```

So:

```text
top() != *begin()
```

This is normal for a stack.

---

# 35. Why std::list and MutantStack Have the Same Iteration Output

The exercise asks us to compare:

```cpp
MutantStack<int>
```

with something like:

```cpp
std::list<int>
```

If both contain:

```text
5 3 5 737 0
```

then:

```cpp
begin()
end()
```

iteration gives:

```text
5 3 5 737 0
```

The containers have different interfaces:

```cpp
MutantStack:
push()

std::list:
push_back()
```

But their iterators can both be used like:

```cpp
begin()
end()
++it
*it
```

This demonstrates the power of generic STL algorithms and iterators.

---

# 36. The Most Important Iterator Vocabulary

| Term             | Meaning                        |
| ---------------- | ------------------------------ |
| `begin()`        | Iterator to first element      |
| `end()`          | Iterator one past last element |
| `*it`            | Get current element            |
| `++it`           | Move to next element           |
| `--it`           | Move to previous element       |
| `iterator`       | Can read and modify            |
| `const_iterator` | Read only                      |
| `rbegin()`       | Start reverse iteration        |
| `rend()`         | End reverse iteration          |

Remember:

```text
begin()
  |
  v
[10] [20] [30]
              |
             end()
```

---

# 37. The STL Pattern to Remember

Most STL code follows this pattern:

```text
1. Create a container
        |
        v
2. Put data inside
        |
        v
3. Get iterators
        |
        v
4. Give iterator range to algorithm
        |
        v
5. Process the data
```

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(30);
numbers.push_back(10);
numbers.push_back(20);

std::sort(numbers.begin(), numbers.end());
```

Think:

```text
vector
  |
  v
30 10 20
  |
  | begin() / end()
  v
[ iterator range ]
  |
  v
std::sort()
  |
  v
10 20 30
```

---

# 38. STL Cheat Sheet

## Containers

```cpp
std::vector<int>
std::list<int>
std::deque<int>

std::map<std::string, int>
std::set<int>

std::stack<int>
std::queue<int>
```

## Common functions

```cpp
push_back()
push_front()
push()
pop_back()
pop_front()
pop()
top()
front()
back()

insert()
erase()

size()
empty()

begin()
end()
rbegin()
rend()
```

## Algorithms

```cpp
std::find()
std::sort()
std::count()
std::for_each()
```

## Iterator

```cpp
container.begin()
container.end()

*it
++it
--it
```

## Template

```cpp
template <typename T>
```

---

# 39. The Big Picture

If you forget everything else, remember this:

```text
                         STL
                          |
            +-------------+-------------+
            |             |             |
       Containers      Iterators    Algorithms
            |             |             |
        store data      walk data    process data
            |             |             |
            +-------------+-------------+
                          |
                      Templates
                          |
                   generic code
```

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(30);
numbers.push_back(10);
numbers.push_back(20);

std::sort(numbers.begin(), numbers.end());
```

Breakdown:

```text
std::vector<int>
      |
      +-- container
      |
      +-- stores integers

numbers.begin()
numbers.end()
      |
      +-- iterators
      |
      +-- define the range

std::sort()
      |
      +-- algorithm
      |
      +-- sorts the range
```

---

# 40. CPP08 — What I Need to Know

Before starting the exercises, I should understand:

### Templates

```cpp
template <typename T>
```

### Containers

```text
vector
list
deque
map
set
stack
queue
```

### Iterators

```cpp
begin()
end()
*it
++it
```

### Const iterators

```cpp
const_iterator
```

### Reverse iterators

```cpp
rbegin()
rend()
```

### Algorithms

```cpp
std::find()
std::sort()
```

### Associative containers

```text
map
set
multimap
multiset
```

### Container adapters

```text
stack
queue
priority_queue
```

### Functors / predicates

```cpp
operator()
```

### Pair

```cpp
std::pair
std::make_pair()
```

---

# 41. Final Mental Model

When I see STL code, I should ask:

```text
1. What container is being used?
              |
              v
2. What type does it store?
              |
              v
3. How do I access its elements?
              |
              v
          iterator
              |
              v
4. What algorithm is being used?
              |
              v
        find / sort / etc.
```

For CPP08:

```text
EX00
easyfind
   ↓
find something
   ↓
std::find + iterators


EX01
Span
   ↓
store numbers
   ↓
sort / calculate spans


EX02
MutantStack
   ↓
make stack iterable
   ↓
inherit from std::stack
   ↓
access underlying container
   ↓
provide begin() / end()
```

**Main idea:**

> **Containers hold the data, iterators let us move through the data, and algorithms operate on the data. Templates make all of this reusable for different types.**
