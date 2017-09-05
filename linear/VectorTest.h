#ifndef ALGORITHMS_VECTORTEST_H
#define ALGORITHMS_VECTORTEST_H

#include <gtest/gtest.h>
#include "Vector.h"

TEST(Vector, Create) {
    Vector<int> v;
    ASSERT_EQ(0, v.size());
}

TEST(Vector, push_back) {
    const std::size_t ITEMS = 7;
    Vector<int> v;

    for (int i = 0; i < ITEMS; ++i) {
        v.push_back(i);
    }
}

#endif //ALGORITHMS_VECTORTEST_H
