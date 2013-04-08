#pragma once

#include <cg/operations/orientation.h>
#include <cg/primitives/pole.h>
#include <vector>
#include <algorithm>
#include <cg/common/range.h>

namespace cg{
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
}
