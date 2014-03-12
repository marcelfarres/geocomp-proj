#include "cgal_render.h"

void cgal_render(const Polyhedron & p) {
    for (Facet_const_iterator f = p.facets_begin(); f != p.facets_end(); ++f) {
        glBegin(GL_POLYGON);
        draw_facet(f);
        glEnd();
    }
}

void draw_facet(const Facet_const_iterator & f) {
}
