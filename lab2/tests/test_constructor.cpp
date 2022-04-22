#include <gtest/gtest.h>
#include "Set.h"

TEST(ConstructorTest, Default) {
    Set<int> a;
    EXPECT_EQ(a.empty(), true);
}

TEST(ConstructorTest, Copy) {
    Set<int> a{1, 2, 3, 4, 5};
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));

    auto b = a;
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, SortedInitList) {
    auto c = Set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(c, (Set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, ReversedInitList) {
    auto d = Set<int>{5, 4, 3, 2, 1};
    EXPECT_EQ(d, Set<int>({1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, RandomInitList) {
    auto e = Set<int>{5, 10, 1, 12, 4};
    EXPECT_EQ(e, (Set<int>{1, 4, 5, 10, 12}));
}

TEST(ConstructorTest, RepeatedInitList) {
    auto f = Set<int>{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    EXPECT_EQ(f, (Set<int>{1, 2, 3, 4, 5}));
}
