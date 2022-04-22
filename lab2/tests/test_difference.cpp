#include <gtest/gtest.h>
#include "Set.h"

TEST(DifferenceTest, EmptySets) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a.difference(b), Set<int>());
}

TEST(DifferenceTest, EmptySetsOperator) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a - b, Set<int>());
}

TEST(DifferenceTest, EmptySetsOperator2) {
    auto a = Set<int>();
    auto b = Set<int>();
    a -= b;
    EXPECT_EQ(a, Set<int>());
}

TEST(DifferenceTest, NonAndEmptySet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    EXPECT_EQ(a.difference(b), (Set<int>{1, 2, 3, 4}));
}

TEST(DifferenceTest, NonAndEmptySetOperator) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    EXPECT_EQ(a - b, (Set<int>{1, 2, 3, 4}));
}

TEST(DifferenceTest, NonAndEmptySetOperator2) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    a -= b;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

// TEST(DifferenceTest, EmptyAndNonSet) {
//     auto a = Set<int>();
//     auto b = Set<int>{1, 2, 3, 4};
//     EXPECT_EQ(a.difference(b), Set<int>());
// }

// TEST(DifferenceTest, EmptyAndNonSetOperator) {
//     auto a = Set<int>();
//     auto b = Set<int>{1, 2, 3, 4};
//     EXPECT_EQ(a - b, Set<int>());
// }

// TEST(DifferenceTest, EmptyAndNonSetOperator2) {
//     auto a = Set<int>();
//     auto b = Set<int>{1, 2, 3, 4};
//     a -= b;
//     EXPECT_EQ(a, Set<int>());
// }

// TEST(DifferenceTest, NonEmptySet) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{1, 2, 3, 4};
//     EXPECT_EQ(a.difference(b), Set<int>{5});
// }

// TEST(DifferenceTest, NonEmptySetOperator) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{1, 2, 3, 4};
//     EXPECT_EQ(a - b, Set<int>{5});
// }

// TEST(DifferenceTest, NonEmptySetOperator2) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{1, 2, 3, 4};
//     a -= b;
//     EXPECT_EQ(a, Set<int>{5});
// }

// TEST(DifferenceTest, NonEmptySet_2) {
//     auto a = Set<int>{3, 4, 5, 6};
//     auto b = Set<int>{1, 2, 3, 4, 5};
//     EXPECT_EQ(a.difference(b), (Set<int>{6}));
// }

// TEST(DifferenceTest, NonEmptySetOperator_2) {
//     auto a = Set<int>{3, 4, 5, 6};
//     auto b = Set<int>{1, 2, 3, 4, 5};
//     EXPECT_EQ(a - b, (Set<int>{6}));
// }

// TEST(DifferenceTest, NonEmptySetOperator_2_2) {
//     auto a = Set<int>{3, 4, 5, 6};
//     auto b = Set<int>{1, 2, 3, 4, 5};
//     a -= b;
//     EXPECT_EQ(a, (Set<int>{6}));
// }

// TEST(DifferenceTest, NonEmptySet_3) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{3, 4, 5, 6};
//     EXPECT_EQ(a.difference(b), (Set<int>{1, 2}));
// }

// TEST(DifferenceTest, NonEmptySetOperator_3) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{3, 4, 5, 6};
//     EXPECT_EQ(a - b, (Set<int>{1, 2}));
// }

// TEST(DifferenceTest, NonEmptySetOperator_32) {
//     auto a = Set<int>{1, 2, 3, 4, 5};
//     auto b = Set<int>{3, 4, 5, 6};
//     a -= b;
//     EXPECT_EQ(a, (Set<int>{1, 2}));
// }

