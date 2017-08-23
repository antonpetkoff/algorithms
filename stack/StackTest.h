#include <gtest/gtest.h>
#include "Stack.h"

TEST(Stack, Empty) {
    Stack stack;
    ASSERT_EQ(true, stack.empty());
}
