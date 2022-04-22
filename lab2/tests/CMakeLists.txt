cmake_minimum_required(VERSION 3.14)
project(test)

file(GLOB SOURCES_TEST 
    test_clear.cpp
    test_combine.cpp
    test_constructor.cpp
    test_difference.cpp
    test_equal.cpp
    test_operators.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES_TEST})
target_include_directories(${PROJECT_NAME} PUBLIC ${SET_LIB_DIR} ${BASE_CONTAINTER_INC} ${ITER_DIR} ${NODE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BASE_CONTAINTER_LIB} GTest::gtest_main)