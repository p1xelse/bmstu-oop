#include <gtest/gtest.h>
#include "Set.h"

TEST(CombineTest, EmptyWithConst) {
    auto a = Set<int>();
    auto t = a.combine(6);
    EXPECT_EQ(t, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithVariable) {
    auto a = Set<int>();
    auto v = 6;
    auto t = a.combine(v);
    EXPECT_EQ(t, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithSet) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    auto t = a.combine(b);
    EXPECT_EQ(t, (Set<int>{1, 2, 3, 4}));
}

TEST(CombineTest, EmptyWithConstOperator) {
    auto a = Set<int>();
    auto t = a | 6;
    EXPECT_EQ(t, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithVariableOperator) {
    auto a = Set<int>();
    auto v = 6;
    auto t = a | v;
    EXPECT_EQ(t, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithSetOperator) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    auto t = a | b;
    EXPECT_EQ(t, (Set<int>{1, 2, 3, 4}));
}

TEST(CombineTest, EmptyWithConstOperator2) {
    auto a = Set<int>();
    a |= 6;
    EXPECT_EQ(a, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithVariableOperator2) {
    auto a = Set<int>();
    auto v = 6;
    a |= v;
    EXPECT_EQ(a, (Set<int>{6}));
}

TEST(CombineTest, EmptyWithSetOperator2) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    a |= b;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}
