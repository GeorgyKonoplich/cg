#pragma once

#include <cg/operations/line_triangle.h>
#include <cg/primitives/rectangle.h>

namespace cg{
	template<class Scalar>
	bool rectangle_line(rectangle_2t<Scalar> const & a, segment_2t<Scalar> const & b){
        return (triangle_line(triangle<Scalar>(a.aa(), a.bb(), a.cc()), b)
                || triangle_line(triangle<Scalar>(a.aa(), a.dd(), a.cc()), b));
    }
}