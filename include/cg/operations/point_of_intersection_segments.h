#pragma once

#include <cg/operations/segments_intersect.h>

namespace cg{
	template<class Scalar>
	point_2t<Scalar> point_of_int(segment_2t<Scalar> const& xx, segment_2t<Scalar> const& yy){
		if (is_intersecting_lines(xx, yy)){
			point_2t<Scalar> a(xx[0]), b(xx[1]), c(yy[0]), d(yy[1]);
			//Scalar pp = a * b;
			point_2t<Scalar> l(a.x - b.x, a.y - b.y);
			Scalar alpha = l * d;
			alpha = alpha / (a.x - b.x);
			Scalar beta = (a.y - b .y) / (a.x - b.x);
			point_2t<Scalar> r(c.x - c.x, d.y - d.y);
			Scalar p_x = ((a * r) - (alpha * (c.x - d.x))) / ((beta * (c.x - d.x)) - (c.y - d.y));
			Scalar p_y = alpha + (p_x * beta);
			point_2t<Scalar> point(p_x, p_y);
			//point_2t<Scalar> point(0, 0);
			return point;
		}
	}
}