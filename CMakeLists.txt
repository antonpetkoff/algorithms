cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES linked_list/LinkedList.cpp linked_list/LinkedList.h stack/Stack.cpp stack/Stack.h stack/StackTest.h linked_list/LinkedListTest.h tests.cpp sorting/Sorting.cpp sorting/SortingTest.h trees/Heap.cpp trees/Heap.h linear/Vector.h linear/VectorTest.h)
add_library(algorithms ${SOURCE_FILES})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(tests tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
