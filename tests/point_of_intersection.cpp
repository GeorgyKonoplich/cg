#include <gtest/gtest.h>

#include <cg/operations/point_of_intersection_segments.h>

using namespace cg;
TEST(point_of_intersection_segments, good){
	point_2 a(-1, 0), b(1, 0), c(0, - 1), d(0, 1), f(0, 0);
	EXPECT_EQ(point_of_int(segment_2(a, b), segment_2(c, d)), f);
}
TEST(point_of_intersection_segments, good1){
	point_2 a(-1, 0), b(1, 0), c(-1, - 1), d(-1, 1), f(-1, 0);
	EXPECT_EQ(point_of_int(segment_2(a, b), segment_2(c, d)), f);
}
TEST(point_of_intersection_segments, good2){
	point_2 a(-1, 3), b(-1, -3), c(-2, 0), d(0, 2), f(-1, 1	);
	EXPECT_EQ(point_of_int(segment_2(a, b), segment_2(c, d)), f);
}
TEST(point_of_intersection_segments, good2s){
	point_2 a(0, 0), b(-2, 2), c(-2, 0), d(0, 2), f(-1, 1	);
	EXPECT_EQ(point_of_int(segment_2(a, b), segment_2(c, d)), f);
}