#include "edgeError.h"

double getError (Ei edge, Polyhedron p){
  Plane p1 = edge->facet()->plane();
  Plane p2 = edge->opposite()->facet()->plane();
  float plane1[4] = {to_double(p1.a()), to_double(p1.b()), to_double(p1.c()), to_double(p1.d()) }; 
  float plane2[4] = {to_double(p2.a()), to_double(p2.b()), to_double(p2.c()), to_double(p2.d()) };
}

void deleteEdge(void) {
    std::pair<double, Halfedge_handle> edge = edges.back();
    edges.pop_back();
    std::cout << "deleting edge with error " << edge.first << std::endl;
    p.join_vertex(edge.second);
}
