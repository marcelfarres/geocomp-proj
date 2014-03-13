#include "edgeError.h"

Plane getPlane(Ei edge) {
    return Plane( edge->vertex()->point(),
                  edge->next()->vertex()->point(),
                  edge->next()->next()->vertex()->point());
}

double init_q (Ei edge){
  Plane p1 = getPlane(edge);
  float plane1[4] = {to_double(p1.a()), to_double(p1.b()), to_double(p1.c()), to_double(p1.d()) }; 
  matrix4x4f m1(plane1);

  Facet_circulator i = edge->facet_begin();
  Facet_circulator initial = i;
  do {
      matrices[i->vertex()] = matrices[i->vertex()] + m1;
      i++;
  } while ( i != initial);

  return 0;
}

void deleteEdge(void) {
    std::pair<double, Halfedge_handle> edge = edges.back();
    edges.pop_back();
    std::cout << "deleting edge with error " << edge.first << std::endl;
    p.join_vertex(edge.second);
}
