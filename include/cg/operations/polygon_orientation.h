#pragma once

#include <cg/operations/orientation.h>
#include <cg/primitives/contour.h>
#include <vector>
#include <algorithm>

namespace cg{
	enum c_orientation_t{
		COUNTERCLOCKWISE = -1,
		CLOCKWISE = 1
	};
	template<class Scalar>
	c_orientation_t polygon_orient(contour_2t<Scalar> const& contour){
		auto it = std::min_element(contour.begin(), contour.end());
		auto circ = contour.circulator(it);
		auto circ1 = circ; --circ1;
		auto circ2 = circ; ++circ2;
		return orientation(*circ, *circ1, *circ2) == CG_RIGHT ? COUNTERCLOCKWISE : CLOCKWISE;
	}
}

