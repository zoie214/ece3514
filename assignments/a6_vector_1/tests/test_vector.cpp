// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

TEST_CASE("Default constructor creates empty vector") {
    dsa::Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("push_back increases size and stores elements")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 5; ++i)
    {
        v.push_back(i);
        REQUIRE(v.size() == i + 1);
        REQUIRE(v.back() == i);
    }

    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 4);
}

TEST_CASE("reserve increases capacity but not size")
{
    dsa::Vector<int> v;
    v.reserve(10);
    REQUIRE(v.capacity() >= 10);
    REQUIRE(v.size() == 0);
}

TEST_CASE("at provides bounds checking")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 3; ++i)
    {
        v.push_back(i);
    }

    REQUIRE_NOTHROW(v.at(0));
    REQUIRE(v.at(1) == 1);

    REQUIRE_THROWS_AS(v.at(-1), std::out_of_range);
    REQUIRE_THROWS_AS(v.at(3), std::out_of_range);
}

TEST_CASE("pop_back reduces size and shrinks")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 16; ++i)
    {
        v.push_back(i);
    }

    int old_cap = v.capacity();

    for (int i = 0; i < 15; ++i)
    {
        v.pop_back();
    }

    REQUIRE(v.size() == 1);
    REQUIRE(v.back() == 0);
    REQUIRE(v.capacity() <= old_cap);
}

TEST_CASE("insert shifts correctly")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 3; ++i)
    {
        v.push_back(i);
    }

    v.insert(1, 99);

    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 99);
    REQUIRE(v[2] == 1);
    REQUIRE(v[3] == 2);
}

TEST_CASE("erase removes and shifts")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 5; ++i)
    {
        v.push_back(i);
    }

    v.erase(2);

    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 1);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
}

TEST_CASE("shrink_to_fit reduces capacity to equal size")
{
    dsa::Vector<int> v;
    for (int i = 0; i < 8; ++i)
    {
        v.push_back(i);
    }

    v.reserve(32);
    REQUIRE(v.capacity() >= 32);

    v.shrink_to_fit();
    REQUIRE(v.capacity() == v.size());
}
