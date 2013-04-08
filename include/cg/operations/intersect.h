#pragma once

#include "cg/operations/orientation.h"
#include "cg/primitives/segment.h"
#include <iostream>

namespace cg{
	template<class Scalar>
	bool is_intersecting_lines(segment_2t<Scalar> a, segment_2t<Scalar> const & b){
		int t1 = orientation(a[0], a[1], b[0]);
		orientation_t t2 = orientation(a[0], a[1], b[1]);
		orientation_t t3 = orientation(b[0], b[1], a[0]);
		orientation_t t4 = orientation(b[0], b[1], a[1]);
		point_2t<Scalar> x;
		if (a[0] > a[1]){
			x = a[0];
			a[0] = a[1];
			a[1] = x;
		}
		if (t1 == CG_COLLINEAR && t2 == CG_COLLINEAR)
			return (a[0] <= b[0] && a[1] >= b[0])
			|| (a[0] <= b[1] && a[1] >= b[1]);
		return t1 != t2 && t3 != t4;
	}
}
