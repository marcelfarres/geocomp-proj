#include "cgal_render.h"

void cgal_render(const Polyhedron & p) {
    for (Facet_const_iterator f = p.facets_begin(); f != p.facets_end(); ++f) {
        glBegin(GL_POLYGON);
        draw_facet(f);
        glEnd();
    }
}

void draw_facet(const Facet_const_iterator & f) {
    Halfedge_const_handle h = f->halfedge();
    Halfedge_const_handle initial = h;
    do {
        Point p = h->vertex()->point();
        glVertex3d(to_double(p.x()), to_double(p.y()), to_double(p.z()));
        h = h->next();
    } while (h != initial);
}
