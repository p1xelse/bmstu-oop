#include <gtest/gtest.h>
#include "Set.h"


TEST(OperatorsTest, Assigment) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = a;
    EXPECT_EQ(b, a);
}

TEST(OperatorsTest, SelfAssigment) {
    auto a = Set<int>{1, 2, 3, 4};
    // cppcheck-suppress selfAssignment
    a = a;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

TEST(OperatorsTest, AssigmentClearing) {
    auto a = Set<int>{1, 2, 3, 4};
    Set<int> b;
    b = a;
    b.clear();
    EXPECT_EQ(b, Set<int>());
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

TEST(OperatorsTest, AddConst) {
    auto a = Set<int>{1, 2, 3, 4};
    a += 10;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 10}));
}

TEST(OperatorsTest, AddVariable) {
    auto a = Set<int>{1, 2, 3, 4};

    auto val = 21;
    a += ++val;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 22}));
}

TEST(OperatorsTest, AddSet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{11, 12, 13, 14};
    a += b;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 11, 12, 13, 14}));
}

TEST(OperatorsTest, SumSet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{5, 6, 7, 8};
    EXPECT_EQ(a + b, (Set<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(OperatorsTest, SumConst) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a + 10 + 23, (Set<int>{1, 2, 3, 4, 10, 23}));
}

TEST(OperatorsTest, SumVariable) {
    auto a = Set<int>{1, 2, 3, 4};
    auto val = 10;
    // cppcheck-suppress unknownEvaluationOrder
    EXPECT_EQ(a + (val++) + val, (Set<int>{1, 2, 3, 4, 10, 11}));
}

TEST(OperatorsTest, StringifyEmpty) {
    auto a = Set<int>();
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "\n");
}

TEST(OperatorsTest, StringifyConstEmpty) {
    const auto a = Set<int>();
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "\n");
}

TEST(OperatorsTest, Stringify) {
    auto a = Set<int>{1, 2, 3, 4};
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1 2 3 4 \n");
}

TEST(OperatorsTest, StringifyConst) {
    const auto a = Set<int>{1, 2, 3, 4};
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1 2 3 4 \n");
}
