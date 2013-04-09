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