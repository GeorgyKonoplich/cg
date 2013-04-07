#include <gtest/gtest.h>

#include <cg/operations/intersect.h>

using namespace cg;

TEST(crossing_lines, match_two_points)
{
    point_2 a(1, 1), b(1, 1), x(1, 1), y(1, 1);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, match_point_and_line)
{
    point_2 a(1, 1), b(2, 2), x(1.5, 1.5), y(1.5, 1.5);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, match_two_lines_1)
{
    point_2 a(1, 1), b(2, 2), x(1, 1), y(2, 2);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, match_two_lines_2)
{
    point_2 a(1, 1), b(2, 2), x(1.5, 1.5), y(2.5, 2.5);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, touch_perpendicular_two_lines)
{
    point_2 a(1, 1), b(3, 1), x(2, 1), y(0, 0);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, cross_two_lines)
{
    point_2 a(1, 1), b(5, 5), x(2, 2), y(0, 0);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), true);
}

TEST(crossing_lines, not_cross_two_points)
{
    point_2 a(1, 1), b(1, 1), x(0, 0), y(0, 0);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), false);
}

TEST(crossing_lines, not_cross_point_and_lines)
{
    point_2 a(1, 1), b(2, 1), x(0, 0), y(0, 0);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), false);
}

TEST(crossing_lines, not_cross_two_lines)
{
    point_2 a(1, 1), b(2, 1), x(0, 0), y(1, 0);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), false);
}

TEST(crossing_lines, not_cross_perpendicular_two_lines)
{
    point_2 a(-1, -1), b(-2, -2), x(0, 0), y(0, 2);
    EXPECT_EQ(is_intersecting_lines(segment_2t<double>(a, b), segment_2t<double>(x, y)), false);
}