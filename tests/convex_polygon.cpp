#include <gtest/gtest.h>

#include <cg/operations/point_in_convex_polygon.h>

using namespace cg;

TEST(is_point_in_convex_polygon, small_test)
{
    point_2 a(0, 0), b(2, 0), c(2, 2), d(0, 2), x(1, 1);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d}), x), true);
}

TEST(is_point_in_convex_polygon, on_polygon_diagonal)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, -1), x(1, 1);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), true);
}

TEST(is_point_in_convex_polygon, match_with_vertex_of_polygon)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1), x(-1, 1);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), true);
}

TEST(is_point_in_convex_polygon, point_near_vertex)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1), x(-0.0001, 0.0001);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), true);
}

TEST(is_point_in_convex_polygon, out_of_polygon)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1), x(-0.0001, 0);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), false);
}

TEST(is_point_in_convex_polygon, point_on_side_of_polygon)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1), x(0.0001, 0);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), true);
}
TEST(is_point_in_convex_polygon, must_error)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, -1), x(1, 0.9);
    EXPECT_EQ(convex_polygon_point(contour_2({a, b ,c, d, e, f, g, h}), x), true);
}
