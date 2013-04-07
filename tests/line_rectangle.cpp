#include <gtest/gtest.h>

#include <cg/operations/line_rectangle.h>

using namespace cg;

TEST(is_line_cross_rectangle, point_touch)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(2, 2), y(2, 2);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), true);
}

TEST(is_line_cross_rectangle, line_match_side)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(-2, 2), y(2, 2);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), true);
}

TEST(is_line_cross_rectangle, in)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(1, 1), y(1, 1.5);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), true);
}

TEST(is_line_cross_rectangle, out)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(0, 3), y(3, 3);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), false);
}

TEST(is_line_cross_rectangle, cross_point_to_point)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(-1, -1), y(3, 3);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), true);
}

TEST(is_line_cross_rectangle, cross_line_to_line)
{
    point_2 a(0, 0), b(2, 0), c(0, 2), d(2, 2), x(1, -1), y(1, 3);
    EXPECT_EQ(rectangle_line(pole<double>({a, b ,c, d}), segment_2t<double>(x, y)), true);
}