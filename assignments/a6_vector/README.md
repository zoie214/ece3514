# A6: Vector (Part 1)

* You will implement a simplified, std::vector like dynamic array called dsa::Vector<T>. 
* This is part 1 to implement functions declared in .hpp. You will also write test cases.
* std::vector must not be used to implement any of these functions.

Starter Code: https://github.com/naneja/ece3514/tree/main/assignments/a6_vector

Please refer to slides 5.4 Vector to see pseudocode as how these functions should be implemented.



```cpp
//vector.h

#pragma once
#include <iostream>

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};
    int sz{0};
    T* data{nullptr};

public:
    //empty
    Vector();
    
    //capacity
    int capacity() const;

    //elements stored
    int size() const;
    
    // True is empty
    bool empty() const;
    
    //element at index when vector is const
    const T& operator[](int i) const;
    
    //element at index when vector is non-const
    T& operator[](int i);
    
    // at function for const
    const T& at(int i) const;
    
    // at function for non const
    T& at(int i);
    
    // first element
    const T& front() const;

    // first element
    T& front();
    
    // last element
    const T& back() const;

    // last element
    T& back();
    
    // insert at end
    void push_back(const T& elem);

    // remove from end
    void pop_back();

    // insert at index
    void insert(int i, const T& elem);

    // removes at index
    void erase(int i);

    //capacity >= minimum
    void reserve(int minimum);

    // called by other functions to reduce cap by half 
    // when sz <= cap/4 
    void shrink();
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit();

}; //end class Vector
}//end namespace dsa
```



# Pseudocode

```ps
Procedure Vector()   // default constructor
    // Automatically construct all data members
    // Do not add any custom logic here.
End Procedure

Function capacity() -> integer
    return capacity

Function size() -> integer
    return size

Function empty() -> boolean
    return (size == 0)
```



```ps
Function operator[](i:integer) -> T&
    return data[i]

Function at(i:integer) -> T&
    if i < 0 or i >= size then
        throw "out of bounds error"
    return data[i]
```



```ps
Function front() -> T&
    return data[0]

Function back() -> T&
    return data[size-1]
```



```pseudocode
Procedure push_back(element : T)
    if size==capacity then
        reserve(max(1, 2*capacity))
    data[size] <- element
    size <- size + 1

Procedure pop_back()
// No validation check on size required rather pop_back must be called when size >=1 else can be undefined
    size <- size-1
```



```pseudocode
Procedure insert(i:integer, element:T)
    if size == capacity then
        reserve(max(1, 2*capacity))

    for k ← size-1 downto i do
        data[k+1] <- data[k]

    data[i] <- element
    size <- size+1
```



```pseudocode
Procedure erase(i:integer)
    for k <- i+1 to size-1 do
        data[k-1] <- data[k]

    size <- size-1
```



```pseudocode
Procedure reserve(minimum:integer)

    if capacity < minimum then
        new_array <- new array of T[minimum]

        for k <- 0 to size - 1 do
            new_array[k] <- data[k]

        delete data
        data <- new_array
        capacity <- minimum
```



