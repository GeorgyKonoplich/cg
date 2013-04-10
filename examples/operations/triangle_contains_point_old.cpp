#include <QColor>
#include <QApplication>

#include <boost/optional.hpp>

#include "cg/visualization/viewer_adapter.h"
#include "cg/visualization/draw_util.h"

#include "cg/io/point.h"

#include <cg/primitives/triangle.h>
#include <cg/primitives/point.h>

#include <cg/operations/point_in_triangle.h>

using cg::point_2f;
using cg::point_2;


struct triangle_contains_point_viewer : cg::visualization::viewer_adapter
{
   triangle_contains_point_viewer()
      : t_(point_2(0, 0), point_2(100, 100), point_2(200, 0))
   {}

   void draw(cg::visualization::drawer_type & drawer) const
   {
      drawer.set_color(Qt::white);
      if (current_point_ && cg::contain(t_, *current_point_))
         drawer.set_color(Qt::green);

      //for (size_t l = 0, lp = 2; l != 3; lp = l++)
        drawer.draw_line(t_c, t_a);
		drawer.draw_line(t_a, t_b);
		drawer.draw_line(t_b, t_c);
   }

   void print(cg::visualization::printer_type & p) const
   {
      p.corner_stream() << "press mouse lbutton with CTRL key near triangle vertex to move it"
                        << cg::visualization::endl
                        << "if triangle is green triangle contains cursor point"
                        << cg::visualization::endl;
   }

   bool on_press(const point_2f & p)
   {
	point_2 aa(t_.a), bb(t_.b), cc(t_.c), tmp;
      for (size_t l = 0; l != 3; ++l)
      {
		if (l == 0) tmp = aa;
		if (l == 1) tmp = bb;
		if (l == 2) tmp = cc;

         if (fabs(p.x - tmp.x) < 4 && fabs(p.y - tmp.y) < 4)

         {
            idx_ = l;
            return true;
         }
      }

      return false;
   }

   bool on_release(const point_2f & p)
   {
      idx_.reset();
      return false;
   }

   bool on_move(const point_2f & p)
   {
      current_point_ = p;

      if (!idx_)
         return true;
	  if (*idx == 0) t_.a = p;
	  if (*idx == 1) t_.b = p;
	  if (*idx == 2) t_.c = p;
      return true;
   }

private:
   cg::triangle_2 t_;
   boost::optional<size_t> idx_;
   boost::optional<cg::point_2> current_point_;
};

int main(int argc, char ** argv)
{
   QApplication app(argc, argv);
   triangle_contains_point_viewer viewer;
   cg::visualization::run_viewer(&viewer, "triangle contains point");
}
