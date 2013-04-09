#pragma once

#include "cg/primitives/triangle.h"
#include "cg/operations/orientation.h"
using namespace cg;

namespace cg{
	template<class Scalar>
	bool contain(const triangle<Scalar> & a, const point_2t<Scalar> & b){
    	orientation_t t1 = orientation(a.a, a.b, b);
    	orientation_t t2 = orientation(a.b, a.c, b);
    	orientation_t t3 = orientation(a.c, a.a, b);
    	return ((t1 <= 0 && t2 <= 0 && t3 <= 0) || (t1 >= 0 && t2 >= 0 && t3 >= 0));
	}
}
