#pragma once

#include "cg/primitives/point.h"

namespace cg{
    template <class Scalar> struct triangle;
    typedef triangle<double> triangle_2;
    
    template <class Scalar>
    struct triangle{
        point_2t<Scalar> a, b, c;
        triangle(point_2t<Scalar> x, point_2t<Scalar> y, point_2t<Scalar> z)
    	   :a(x)
    	   ,b(y)
           ,c(z)
        {}
        point_2t<Scalar> & operator[] (size_t i){
            switch (i){
            case 0: return a;
            case 1: return b;
            case 2: return c;
            default: break;
            }
        }
        point_2t<Scalar> const& operator[](size_t i) const{
            switch (i){
            case 0: return a;
            case 1: return b;
            case 2: return c;
            default: break;
        }
      }

        triangle()
            :triangle(0, 0, 0)
        {}
    };
}
