#pragma once

#include "cg/primitives/contour.h"
#include "cg/operations/orientation.h"
#include "cg/operations/containp.h"

namespace cg{
	template<class Scalar>
	bool convex_polygon_point(contour_2t<Scalar> const& contour, point_2t<Scalar> const& point){
		auto first = *contour.begin();
		auto itr = std::lower_bound(contour.begin(), contour.end(), point,
                                  [&] (point_2 const& l, point_2 const& val){
    		auto o = orientation(first, l, val);
        	return o == CG_RIGHT || o == CG_COLLINEAR;
     	});
     	auto circ = contour.circulator(itr); 
     	if (first != *(--circ) && first != *(circ) && contain(triangle<Scalar>(first, *circ, *(--circ)), point)) return true;
		if (first != *(++circ) && first != *(circ) && contain(triangle<Scalar>(first, *circ, *(++circ)), point)) return true;	
   		auto circ1 = contour.circulator(contour.begin());
   		auto t1 = orientation(first, *(++circ1), point);
   		auto t2 = orientation(first, *(--circ1), point);
   		if (t1 >= 0 && t2 >= 0 || t1 <= 0 && t2 <= 0) return true;
   		return false;
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
