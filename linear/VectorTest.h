#ifndef ALGORITHMS_VECTORTEST_H
#define ALGORITHMS_VECTORTEST_H

#include <gtest/gtest.h>
#include "Vector.h"

TEST(Vector, Create) {
    Vector<int> v;
    ASSERT_EQ(0, v.size());
}

TEST(Vector, push_back) {
    const std::size_t ITEMS = 10000;
    Vector<int> v;

    for (int i = 0; i < ITEMS; ++i) {
        v.push_back(i);
    }
}

TEST(Vector, for_range) {
    const std::size_t ITEMS = 10000;
    Vector<int> v;

    for (int i = 0; i < ITEMS; ++i) {
        v.push_back(i);
    }

    for (auto & x : v) {
        x += 1;
    }

    int i = 1;
    for (auto x : v) {
        ASSERT_EQ(x, i++);
    }
}

TEST(Vector, ElementAccess) {
    const std::size_t ITEMS = 100000;
    Vector<int> v;

    for (int i = 0; i < ITEMS; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < ITEMS; ++i) {
        ASSERT_EQ(i, v[i]);
    }
}

TEST(Vector, PopBack) {
    const std::size_t ITEMS = 100000;
    Vector<int> v;

    for (int i = 0; i < ITEMS; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < ITEMS; ++i) {
        ASSERT_EQ(v.size(), ITEMS - i);
        v.pop_back();
        ASSERT_EQ(v.size(), ITEMS - i - 1);
    }
}

#endif //ALGORITHMS_VECTORTEST_H
