#include <gtest/gtest.h>

#include <cg/operations/polygon_orientation.h>
using namespace cg;

TEST(polygon_orient, one_test){
    point_2 a(0, 0), b(1, 0), c(2, 1), d(2, 2), e(1, 3), f(0, 3), g(-1, 2), h(-1, 1);
    EXPECT_EQ(polygon_orient(contour_2({a, b ,c, d, e, f, g, h})), -1);
}
