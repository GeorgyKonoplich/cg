#pragma once

#include <cg/operations/line_triangle.h>
#include <cg/primitives/pole.h>

namespace cg{
	template<class Scalar>
    bool rectangle_line(pole<Scalar> const & a, segment_2t<Scalar> const & b){
        return (triangle_line(triangle<Scalar>(a[0], a[1], a[2]), b)
                || triangle_line(triangle<Scalar>(a[0], a[2], a[3]), b));
    }
}