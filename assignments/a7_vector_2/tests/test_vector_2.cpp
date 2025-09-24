// test_vector_iterator.cpp
//#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <algorithm>  //for std::max
#include "vector.hpp"
#include <type_traits> // is_same_v, is_assignable_v, etc.
#include <utility>     // declval

struct abc {
    int x;
    int y;
};


TEST_CASE("non-const iterator dereference") {
    dsa::Vector<int> v; 
    bool ok{true};

    REQUIRE(ok);
}

