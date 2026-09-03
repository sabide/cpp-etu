#include "int_array.hpp"

#include <cassert>
#include <iostream>
#include <utility>

int main()
{
    IntArray original{4};
    original.push_back(1);

    IntArray copy{original};
    copy.fill(9);
    assert(original.at(0) == 1);
    assert(copy.at(0) == 9);

    IntArray assigned{8};
    assigned.push_back(7);
    original = assigned;
    original.fill(0);
    assert(assigned.at(0) == 7);

    IntArray& same_object{original};
    original = same_object;
    assert(original.at(0) == 0);

    IntArray source{4};
    source.push_back(42);
    IntArray moved{std::move(source)};
    assert(source.size() == 0);
    assert(moved.at(0) == 42);

    source.push_back(3);
    assert(source.at(0) == 3);

    IntArray destination{2};
    destination.push_back(99);
    destination = std::move(moved);
    assert(moved.size() == 0);
    assert(destination.at(0) == 42);

    IntArray empty_copy{moved};
    assert(empty_copy.size() == 0);
    assert(empty_copy.capacity() == 0);

    destination[0] = 12;
    const IntArray& frozen{destination};
    assert(frozen[0] == 12);

    std::cout << "TD4 correction: all tests passed\n";
}
