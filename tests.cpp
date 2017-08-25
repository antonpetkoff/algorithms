#include <gtest/gtest.h>
#include "stack/StackTest.h"
#include "linked_list/LinkedListTest.h"
#include "sorting/SortingTest.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
