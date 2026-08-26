*this is more like a personal note than a readme*

# ex00 — `easyfind`

## 1. What is this exercise teaching?

`ex00` introduces the **STL (Standard Template Library)**, especially:

* Containers
* Iterators
* `begin()` / `end()`
* `std::find()`
* Function templates
* Exceptions

The goal is to write:

```cpp
easyfind(container, value);
```

It searches a container of integers and returns an iterator to the **first occurrence** of the value. If the value isn't found, we throw an exception.

---

# 2. Containers

A **container** stores multiple values.

For this exercise, the important sequence containers are:

```text
std::vector
std::list
std::deque
```

---

# 3. Important difference between containers

The interesting thing is that containers don't all access their elements in the same way.

### `vector`

```text
[10] [20] [30] [40]
  0    1    2    3
```

Has indexes:

```cpp
v[2];  // 30
```

It also has iterators.

---

### `deque` - double-ended queue

Similar to vector:

```text
[10] [20] [30] [40]
  0    1    2    3
```

It also supports:

```cpp
d[2];  // 30
```

and iterators.

So:

```text
vector → index ✅
deque  → index ✅
```

---

### `list`

A list is different:

```text
[10] → [20] → [30] → [40]
```

It does **not** have indexes:

```cpp
list[2];  // ❌
```

Instead, we use an iterator to move through it:

```cpp
std::list<int>::iterator it = list.begin();

++it;
```

Now `it` points to `20`.

If we want to know how far `it` is from the beginning:

```cpp
std::distance(list.begin(), it);
```

This gives a **distance**, not technically an index.

### Remember

```text
vector → index
deque  → index
list   → no index, use iterators/distance
```

---

# 4. Iterator

An **iterator is like a pointer that represents a position inside a container.**

For:

```text
[10] [20] [30] [40]
```

if `it` points to `20`:

```text
[10] [20] [30] [40]
       ↑
       it
```

### `it`

Means the **position**.

### `*it`

Means the **value at that position**.

```cpp
std::cout << *it;
```

prints:

```text
20
```

Generally cannot do:

```cpp
std::cout << it;
```

because `it` is an iterator, not the integer value.

---

# 5. `begin()` and `end()`

### `begin()`

Points to the first element.

```text
begin()
   ↓
[10] [20] [30] [40]
```

### `end()`

Points **one position after the last element**.

```text
[10] [20] [30] [40] [END]
                         ↑
                       end()
```

`end()` does **not** point to an actual value.

Therefore:

```cpp
*container.end(); // ❌
```

is invalid.

---

# 6. `std::find()`

`std::find()` searches between two iterators:

```cpp
std::find(
    container.begin(),
    container.end(),
    value
);
```

It starts at `begin()` and moves forward.

For:

```text
10 20 30 20 40
```

searching for `20`:

```text
10 → 20 → 30 → 20 → 40
     ↑
   found
```

It stops at the **first `20`**.

If nothing is found:

```cpp
std::find(...)
```

returns:

```cpp
container.end()
```

That's why `easyfind` checks:

```cpp
if (it == container.end())
    throw ContainerException();
```

---

# 7. Why return an iterator?

function returns:

```cpp
typename T::iterator
```

because different containers have different iterator types.

For example:

```text
vector<int> → vector<int>::iterator
list<int>   → list<int>::iterator
deque<int>  → deque<int>::iterator
```

Using:

```cpp
typename T::iterator
```

lets the template automatically use the correct iterator type.

This is one of the main reasons `easyfind` is a **template**.

---

# 8. Why is `easyfind` in the `.hpp`?

Templates need their **full implementation visible** when the compiler instantiates them.

Therefore:

```cpp
template <typename T>
typename T::iterator easyfind(...)
{
    ...
}
```

belongs in the `.hpp`, or in a `.tpp` that is included by the `.hpp`.

---

# 9. Why is `what()` implemented in the `.hpp`?

Exception does contain a function implementation.

That's okay because the function is defined **inside the class**, which makes it implicitly `inline`.

Therefore it is safe to define it in the header.

> “`what()` is a member function. Since it's defined inside the class, it's implicitly inline, so it's safe to put in the header. The problem with headers is mainly non-inline function definitions that can cause multiple definitions.”

---

# 10. `test.sh`

`test.sh`:

```text
Compile
   ↓
If compilation fails → KO
   ↓
Run program
   ↓
If program crashes → KO
   ↓
Check expected output
   ↓
Each test → OK / KO
   ↓
Final result
```

For example:

```text
======================================
       EASYFIND AUTOMATED TESTS
======================================

Compilation: OK
Program execution: OK

Vector first occurrence: OK
Vector first element: OK
Vector last element: OK
Vector missing value: OK
Empty vector: OK

List find: OK
List missing value: OK

Deque find: OK
Deque missing value: OK

======================================
          ALL TESTS PASSED
======================================
```

---

## ⭐ The most important things to remember

```text
Container = stores multiple values

Iterator = represents a position in a container

begin() = first element

end() = one past the last element

*it = value at the iterator's position

std::find() = searches from begin() to end()

find() returns end() = value wasn't found

vector/deque = support indexes

list = doesn't support indexes

easyfind is a template = works with different containers

Template implementation = must be visible in the header

what() inside the class = implicitly inline
```

That is the **core knowledge of `ex00`**.
