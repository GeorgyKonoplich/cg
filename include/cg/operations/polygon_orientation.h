#pragma once

#include <cg/operations/orientation.h>
#include <cg/primitives/contour.h>
#include <vector>
#include <algorithm>

namespace cg{
	enum c_orientation_t{
		CG_CLEFT = 1,
		CG_CRIGHT = -1
	};
	c_orientation_t polygon_orient(contour_2 const& contour){
		auto it = std::min_element(contour.begin(), contour.end());
		auto circ = contour.circulator(it);
		return orientation(*it, *(--circ), *(++circ)) == CG_LEFT ? CG_CLEFT : CG_CRIGHT;
	}
}
/*namespace cg{
	template<class Scalar>
	int polygon_orient(pole<Scalar> const& a){
		std::vector<point_2t<Scalar>> points = a.get_vector();
		auto rc = std::min_element(points.begin(), points.end(), 
            [] (point_2t<Scalar> const& l, point_2t<Scalar> const& r){ 
            	return l < r; 
        	});
		 
		//return 1;
		//common::range_circulator <Scalar > rc(points.begin(), points.end(), _it);
		return orientation(*rc, *(rc + 1), *(rc - 1));
	}
}*/
