#pragma once

#include <cg/operations/segments_intersect.h>
#include <iostream>

namespace cg{
	template<class Scalar>
	point_2t<Scalar> point_of_int(segment_2t<Scalar> const& xx, segment_2t<Scalar> const& yy){
		if (is_intersecting_lines(xx, yy)){
			point_2t<Scalar> a(xx[0]), b(xx[1]), c(yy[0]), d(yy[1]);
			Scalar p_x = (a.x*(c.x-d.x)*(a.y-b.y)+(c.x-d.x)*(c.y-a.y)*(a.x-b.x)-c.x*(c.y-d.y)*(a.x-b.x))
						  /((c.x-d.x)*(a.y-b.y) - (a.x-b.x)*(c.y-d.y));
			Scalar p_y = (p_x-a.x)*(a.y-b.y)+a.y*(a.x-b.x);
			if (a.x-b.x == 0){
				p_y = c.y*(c.x - d.x) + (p_x - c.x)*(c.y-d.y);
				p_y = p_y / (c.x - d.x);
			} else p_y = p_y / (a.x - b.x);
			point_2t<Scalar> point(p_x, p_y);
			//std::cout << p_x << " " << p_y << std::endl;
			return point;
		}
	}
}