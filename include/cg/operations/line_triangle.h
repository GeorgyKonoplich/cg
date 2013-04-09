#pragma once

#include <cg/operations/point_in_triangle.h>
#include <cg/primitives/segment.h>
#include <cg/operations/segments_intersect.h>
using namespace cg;

namespace cg{
	template<class Scalar>
	bool triangle_line(const triangle<Scalar> & a, const segment_2t<Scalar> & b){
		return contain(a, b[0]) || contain(a, b[1]) 
		|| is_intersecting_lines(segment_2t<Scalar>(a.a, a.b),b) || is_intersecting_lines(segment_2t<Scalar>(a.b, a.c), b);
	}
}
