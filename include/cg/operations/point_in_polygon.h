#pragma once

#include <cg/primitives/contour.h>
#include <cg/operations/segments_intersect.h>

namespace cg{
	template<class Scalar>
	bool point_in_polygon(contour_2t<Scalar> const& contour, point_2t<Scalar> const& point){
		auto it = std::max_element(contour.begin(), contour.end(), 
			[&contour](point_2t<Scalar> const& x, point_2t<Scalar> const& y){
				return x.x < y.x;
			});
		Scalar tmp_x = it->x;
		tmp_x = tmp_x + tmp_x;; 
		Scalar tmp_y = point.y;
		Scalar h_y;
		segment_2t<Scalar> line(point, point_2t<Scalar>(tmp_x, tmp_y));
		int kol = 0;
		for (size_t i = 0; i < contour.vertices_num(); i++){
			point_2t<Scalar> down(contour[i]), up(contour[(i + 1) % contour.vertices_num()]);
			segment_2t<Scalar> seg(up, down);
			if (is_intersecting_lines(seg, segment_2t<Scalar>(point, point))){
				return true;
			}
			auto t1 = orientation(up, line[0], line[1]);
			auto t2 = orientation(down, line[0], line[1]);
			if (t1 == 0 || t2 == 0){
				if (t1 == 0 && t2 == 0) continue;
				if (t1 == 0){ 
					kol++;
					h_y = down.y;
				}else{
					if ((h_y > down.y && up.y > down.y) || (h_y < down.y && up.y < down.y)) kol++;
				}
				
			}else if (is_intersecting_lines(line, seg)) kol++;
		}
		return kol % 2 == 1;
	}
}