#pragma once
#include <iostream>

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};       // capacity of the array
    int sz{0};        // number of actual entries
    T* data{nullptr}; // pointer to array of elements

public:
    //empty
    Vector() = default;
    
    //capacity
    int capacity() const {
        // ToDo
    }

    //elements stored
    int size() const {
        // ToDo
    }
    
    // True is empty
    bool empty() const {
        // ToDo 
    }
    
    //element at index when vector is const
    const T& operator[](int i) const { 
        // ToDo 
    }
    
    //element at index when vector is non-const
    T& operator[](int i) { 
        // ToDo 
    }
    
    // at function for const
    const T& at(int i) const{
        // ToDo
    }
    
    // at function for non const
    T& at(int i){
        // ToDo
    }
    
    // first element
    const T& front() const { 
        // ToDo
    }

    // first element
    T& front() {
        // ToDo
    }
    
    // last element
    const T& back() const { 
        // ToDo
    }

    // last element
    T& back() {
        // ToDo
    }
    
    // insert at end
    // double array size
    void push_back(const T& elem){
        // ToDo
    }

    // remove from end
    void pop_back() { 
        // ToDo
    }

    // insert at index
    void insert(int i, const T& elem){
        // ToDo
    }

    // removes at index
    void erase(int i){
        // ToDo
    }

    //capacity >= minimum
    void reserve(int minimum){
        // ToDo
    }

    // nested iterator class
    class iterator {
        // needed by Vector's insert and erase
        friend class Vector;
        
        private:
            Vector* vec;
            int ind;   // index within the vector
        public:
            // constructor
            iterator(Vector* v=nullptr, int i=-1){ 
                vec = v; ind=i; 
            }

            T& operator*() const { 
                // ToDo 
            }

            T* operator->() const { 
                // ToDo
            }

            //pre increment overloaded without param
            iterator& operator++(){
                // ToDo
            }

            //post increment overloaded with parameter
            iterator operator++(int){ 
                // ToDo
            }

            //pre decrementr overloaded without param
            iterator& operator--(){
                // ToDo
            }
            
            //post decrement overloaded with parameter
            iterator operator--(int){
                // ToDo
            }

            bool operator==(iterator rhs) const{
                // ToDo
            }

            bool operator!=(iterator rhs) const{
                // ToDo
            }
    };

    // nested const_iterator class
    class const_iterator {
        private:
            const Vector* vec;
            int ind;   // index within the vector
        
        public:
            const_iterator(const Vector* v=nullptr, int i=-1){
                vec = v; ind=i;
            }

            const T& operator*() const { 
                // ToDo
            }
            
            const T* operator->() const { 
                // ToDo
            }

            //pre
            const_iterator& operator++(){
                // ToDo
            }

            //post
            const_iterator operator++(int){
                // ToDo
            }

            //pre
            const_iterator& operator--(){
                // ToDo
            }

            //post
            const_iterator operator--(int){
                // ToDo
            }

            bool operator==(const_iterator rhs) const{
                // ToDo
            }

            bool operator!=(const_iterator rhs) const{
                // ToDo
            }
    };
public:
    // additional functions of Vector class
    
    //return vector and index 0
    iterator begin(){
        return iterator(this, 0);
    }

    //return vector and index sz
    iterator end(){
        // ToDo
    }

    //return vector and index 0
    const_iterator begin() const{
        // ToDo
    }

    //return vector and index sz
    const_iterator end() const{
        // ToDo
    }

    // Inserts an element immediately before iterator position
    iterator insert(iterator it, const T& elem){
        // ToDo
    }

    // Removes the element at the given iterator position
    iterator erase(iterator it){
        // ToDo
    }
    

    // Rule of Five
    private:

        void clone(const Vector& other){
            // ToDo
        }

        void transfer(Vector& other){
            // ToDo
        }

    public:
        // Copy constructor
        Vector(const Vector& other){ 
            clone(other); 
        }

        // Copy assignment
        Vector& operator=(const Vector& other){
            // nothing to be done if self-assignment
            if (this != &other) {
                // ToDo
            }
            return *this;
        }

        // Move constructor
        Vector(Vector&& other){ 
            transfer(other); 
        }

        // Move assignment
        Vector& operator=(Vector&& other){
            // nothing to be done for self-assignment
            if (this != &other) {
                // ToDo
            }
            return *this;
        }

        // Destructor suffices
        ~Vector(){
            delete[] data; 
        }

    // additional assignment functions
    // Reallocate storage to exactly new_cap (>= sz), moving elements.
    void reallocate(int new_cap){ // optional helper
        // ToDo
    }

    void shrink(){
        // ToDo
    }
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit(){
        // ToDo
    }

}; //end class Vector
}//end namespace dsa

