#include <iostream>
#include <vector>
#include <cassert>
#include "sorting/quick_sort.hpp"
#include <algorithm>
#include <random>

template <class T>
bool operator==(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    if (lhs.size() != rhs.size())
        return false;

    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}

template <class T>
void test(std::vector<T> input) {
    std::vector<T> expect(input);
    std::sort(expect.begin(), expect.end());

    auto output = std::move(quick_sort(input));
    assert(output == expect);
}

int main() {
    std::mt19937 gen;
    std::uniform_int_distribution<> dist(-100000, 100000);

    std::vector<int> test_vector(100000);

    std::cout << "Testing...\n";
    for (int i = 0; i < 250; ++i) {
        for (auto& a : test_vector)
            a = dist(gen);
        test(test_vector);
    }
    std::cout << "Success\n";

    return 0;
}




