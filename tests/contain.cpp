#include <gtest/gtest.h>

#include <cg/operations/point_in_triangle.h>

using namespace cg;

TEST(is_point_in_triangle, touch)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(0, 1);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), true);
}

TEST(is_point_in_triangle, match_with_vertex_of_the_triangle)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(0, 0);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), true);
}

TEST(is_point_in_triangle, in)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(1, 1);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), true);
}

TEST(is_point_in_triangle, out)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(0, -1);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), false);
}

TEST(ATTENTION, ATTENTION)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), x(-0.0001, 0);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), false);
}
TEST(ATTENTION1, ATTENTION1)
{
    point_2 a(0, 0), b(-1, 2), c(-1, 1), x(-0.0001, 0);
    EXPECT_EQ(contain(triangle<double>(a, b, c), x), false);
}
