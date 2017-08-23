#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedList, Empty) {
    LinkedList list;
    ASSERT_EQ(true, list.empty());
}
