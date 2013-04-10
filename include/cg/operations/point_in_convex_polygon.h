#pragma once

#include "cg/primitives/contour.h"
#include "cg/operations/orientation.h"
#include "cg/operations/point_in_triangle.h"
#include <iostream>
namespace cg{
	template<class Scalar>
	bool convex_polygon_point(contour_2t<Scalar> const& contour, point_2t<Scalar> const& point){
		auto first = contour[0];
		auto itr = std::lower_bound(contour.begin() + 2, contour.end(), point,
                                  [&] (point_2 const& x, point_2 const& y){
    		auto t = orientation(first, x, y);
        	return t == CG_LEFT;
     	});
     	if (itr == contour.end()){
     		return false;
     	}
     	return contain(triangle<double>(first, *itr, *(itr - 1)), point);
     }
}
