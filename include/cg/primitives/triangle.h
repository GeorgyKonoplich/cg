#pragma once

#include "cg/primitives/point.h"

namespace cg{
    template <class Scalar>
    struct triangle{
        point_2t<Scalar> a, b, c;
        triangle(point_2t<Scalar> x, point_2t<Scalar> y, point_2t<Scalar> z)
    	   :a(x)
    	   ,b(y)
           ,c(z)
        {}

        triangle()
            :triangle(0, 0, 0)
        {}
    };
}
