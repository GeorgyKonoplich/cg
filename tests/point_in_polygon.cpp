#include <gtest/gtest.h>

#include <cg/operations/point_in_polygon.h>
using namespace cg;
TEST(point_in_polygon, light_test){
	point_2 a(0, 0), b(1, 1), c(0, 2), d(-1 , 1), f(0.5, 0.8);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d}), f), true);
}

TEST(point_in_polygon, cont_primer){
	point_2 a(0, 0), b(3, 7), c(2, 9), d(1 , 7), e(0, 9), f(-1, 3), g(-2, 9), h(-4, 2), x(-2, 7);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), true);
}
TEST(point_in_polygon, cont_primer1){
	point_2 a(0, 0), b(3, 7), c(2, 9), d(1 , 7), e(0, 9), f(-1, 3), g(-2, 9), h(-4, 2), x(-6, 7);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), false);
}
TEST(point_in_polygon, cont_primer2){
	point_2 a(0, 0), b(3, 7), c(2, 9), d(1 , 7), e(0, 9), f(-1, 3), g(-2, 9), h(-4, 2), x(0, 0);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), true);
}
TEST(point_in_polygon, cont_primer3){
	point_2 a(0, 0), b(7, 7), c(2, 9), d(1 , 7), e(0, 9), f(-1, 3), g(-2, 9), h(-4, 2), x(1, 1);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), true);
}
TEST(point_in_polygon, cont_primer4){
	point_2 a(0, 0), b(7, 7), c(2, 9), d(1 , 7), e(0, 9), f(-1, 3), g(-2, 9), h(-4, 2), x(-1, 7);
	EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), false);
}
TEST(is_point_in_polygon, small_test)
{
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, -1), x(1, 1);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h}), x), true);
}

TEST(is_point_in_polygon, close_enough)
{
    point_2 a(0, 0), b(5, 0), c(7, 3), d(0, .1), e(7, 5), f(0, 10), g(0, .11), h(-3, 5), i(-3, 2), x(-0.001, 1);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h, i}), x), false);
}

TEST(is_point_in_polygon, begin_from_vertex1)
{
    point_2 a(0, 0), b(5, 0), c(7, 3), d(0, .1), e(7, 5), f(0, 10), g(0, .11), h(-3, 5), i(-3, 2), x(0, 10);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e, f, g, h, i}), x), true);
}

TEST(is_point_in_polygon, begin_from_vertex2)
{
    point_2 a(0, 0), b(1, 0), c(1, 1), d(0, 1), x(0, 0);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d}), x), true);
}

TEST(is_point_in_polygon, point_match_with_side1)
{
    point_2 a(0, 0), b(1, 0), c(1, 1), d(0, 1), x(0.5, 0);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d}), x), true);
}

TEST(is_point_in_polygon, point_match_with_side2)
{
    point_2 a(0, 0), b(0.5, 0), c(1, 0), d(1, 1), e(1, 0), x(0.4, 0);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e}), x), true);
}

TEST(is_point_in_polygon, out_of_polygon1)
{
    point_2 a(0, 0), b(0.5, 0), c(1, 0), d(1, 1), e(1, 0), x(-1, 0);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d, e}), x), false);
}

TEST(is_point_in_polygon, out_of_polygon2)
{
    point_2 a(0, 0), b(2, 0), c(2, 2), d(0, 2), x(-1, 0);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c, d}), x), false);
}

TEST(is_point_in_polygon, point_in_triangle)
{
    point_2 a(0, 0), b(5, 0), c(2.5, .0000000001), x(1, .0000000000000001);
    EXPECT_EQ(point_in_polygon(contour_2({a, b, c}), x), true);
}
