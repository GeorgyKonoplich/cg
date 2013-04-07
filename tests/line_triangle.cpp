#include <gtest/gtest.h>

#include <cg/operations/line_triangle.h>
using namespace cg;

TEST(is_line_crossing_triangle, in)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(1, 1), y(-1, -1);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), true);
}

TEST(is_line_crossing_triangle, touch)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(0, 1), y(-1, -1);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), true);
}

TEST(is_line_crossing_triangle, out)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(-2, -2), y(-1, -1);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), false);
}

TEST(is_line_crossing_triangle, cross_point_to_line)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(-2, -2), y(3, 3);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), true);
}

TEST(is_line_crossing_triangle, cross_line_to_line)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(1, 1), y(5, 1);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), true);
}

TEST(is_line_crossing_triangle, cross_point)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), x(-2, 2), y(2, 2);
    EXPECT_EQ(triangle_line(triangle<double>(a, b, c), segment_2t<double>(x, y)), true);
}

