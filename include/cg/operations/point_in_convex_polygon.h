#pragma once

#include "cg/primitives/contour.h"
#include "cg/operations/orientation.h"
#include "cg/operations/point_in_triangle.h"

namespace cg{
	template<class Scalar>
	bool convex_polygon_point(contour_2t<Scalar> const& contour, point_2t<Scalar> const& point){
		auto first = contour[0];
		auto itr = std::lower_bound(contour.begin(), contour.end(), point,
                                  [&] (point_2 const& x, point_2 const& y){
    		auto t = orientation(first, x, y);
        	return t == CG_LEFT;
     	});
     	auto circ = contour.circulator(itr); 
     	return contain(triangle<double>(first, *itr, *(++circ)), point);
   }
}
/*

namespace cg{
	template<class Scalar>
	bool convex_polygon_point(pole<Scalar> const& a, point_2t<Scalar> const& b){
		std::vector<point_2t<Scalar>> p = a.get_vector();
		auto m = std::lower_bound(p.begin(), p.end(), b, 
				[&] (point_2t<Scalar> const& x, point_2t<Scalar> const& y){
					return orientation(p[0], x, y) == CG_RIGHT;
				}
			);
		return contain(triangle<Scalar>(p[0], *m, *(m - 1)), b);
	}
}*/
