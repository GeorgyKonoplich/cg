#pragma once

#include "cg/primitives/point.h"
#include <vector>

namespace cg{
    template<class Scalar>
    struct pole{
        std::vector<point_2t<Scalar> > points;
        pole(std::vector<point_2t<Scalar> > points)
            :points(points)
        {}

        point_2t<Scalar> const & operator[](size_t i) const{
            return points[i];
        }

        point_2t<Scalar> & operator[](size_t i){
            return points[i];
        }

        int size() const{
            return points.size();
        }

        std::vector<point_2t<Scalar> > const & get_vector() const{
            return points;
        }
    };
}
