# A7: Vector (Part 2)

* You will complete the implementation of a simplified, std::vector like dynamic array called dsa::Vector<T>. 
* This is part 2 to implement functions declared in .hpp. You will also write test cases.
* std::vector must not be used to implement any of these functions (No points if std::vector is used even all test cases are passed at Gradescope).

Please refer to slides 5.4 Vector, 5.5 Iterators, and 5.7 Clone Move Deallocate

Please also see below pseudocode as how these functions should be implemented.

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



```pseudocode
// helper function not mentioned but you may define for shrink
procedure REALLOCATE(new_cap):
    if new_cap == cap: 
    	return
    allocate TEMP array of length new_cap
    for k from 0 to sz-1:
        move/copy DATA[k] into TEMP[k]
    delete DATA
    DATA <- TEMP
    cap  <- new_cap


procedure SHRINK():
    if cap > 0 and sz <= cap / 4:
        new_cap <- max(1, cap/2)
        if new_cap < sz:
            new_cap <- sz
        REALLOCATE(new_cap)

procedure SHRINK_TO_FIT():
    if cap > sz:
        new_cap <- max(1, sz)
        REALLOCATE(new_cap)
```









Testing Quality with Catch 2 (12 pts)

- Coverage of edge cases; negative tests
- Meaningful Test description and tags