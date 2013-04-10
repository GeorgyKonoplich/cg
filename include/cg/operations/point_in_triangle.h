#pragma once

#include "cg/primitives/triangle.h"
#include "cg/operations/orientation.h"
using namespace cg;

namespace cg{
	template<class Scalar>
	bool contain(const triangle_2t<Scalar> & a, const point_2t<Scalar> & b){
    	orientation_t t1 = orientation(a[0], a[1], b);
    	orientation_t t2 = orientation(a[1], a[2], b);
    	orientation_t t3 = orientation(a[2], a[0], b);
    	return ((t1 <= 0 && t2 <= 0 && t3 <= 0) || (t1 >= 0 && t2 >= 0 && t3 >= 0));
	}
}
