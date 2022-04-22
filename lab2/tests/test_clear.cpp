#include <gtest/gtest.h>
#include "Set.h"

TEST(ClearTest, Empty) {
    auto a = Set<int>();
    a.clear();
    EXPECT_EQ(a.empty(), true);
}

TEST(ClearTest, NonEmpty) {
    auto b = Set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.clear();
    EXPECT_EQ(b.empty(), true);
}
