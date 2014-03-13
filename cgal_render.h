#ifndef _cgal_render_H
#define _cgal_render_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/number_utils.h>

typedef  CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Facet_const_iterator Facet_const_iterator;
typedef Polyhedron::Halfedge_const_handle Halfedge_const_handle;
typedef Kernel::Point_3 Point;

void cgal_render(const Polyhedron & p);

void draw_facet(const Facet_const_iterator & f);

#endif
