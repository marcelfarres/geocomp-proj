#include "edgeError.h"
float vertex_error(matrix4x4f q, float x, float y, float z){
        return q.m[0]*x*x + 2*q.m[1]*x*y + 2*q.m[2]*x*z + 2*q.m[3]*x + q.m[5]*y*y + 2*q.m[6]*y*z + 2*q.m[7]*y + q.m[10]*z*z + 2*q.m[11]*z + q.m[15];
}

Plane getPlane(Ei edge) {
    return Plane( edge->vertex()->point(),
                  edge->next()->vertex()->point(),
                  edge->next()->next()->vertex()->point());
}

void  init_q (Ei edge){
  Plane p1 = getPlane(edge);
  float plane1[4] = {to_double(p1.a()), to_double(p1.b()), to_double(p1.c()), to_double(p1.d()) }; 
  matrix4x4f m1(plane1);

  Facet_circulator i = edge->facet_begin();
  Facet_circulator initial = i;
  do {
      matrices[i->vertex()] = matrices[i->vertex()] + m1;
      i++;
  } while ( i != initial);
}

double getError (Ei edge){
    matrix4x4f Q1 = matrices[edge->vertex()];
    matrix4x4f Q2 = matrices[edge->next()->vertex()];
    double x = to_double(edge->vertex()->point().x() + edge->next()->vertex()->point().x())/2 ;
    double y = to_double(edge->vertex()->point().y() + edge->next()->vertex()->point().y())/2 ;
    double z = to_double(edge->vertex()->point().z() + edge->next()->vertex()->point().z())/2 ;
    return vertex_error (Q1+Q2,x,y,z);
}
void deleteEdge(void) {
    std::pair<double, Halfedge_handle> edge = edges.back();
    edges.pop_back();
    std::cout << "deleting edge with error " << edge.first << std::endl;
    p.join_vertex(edge.second);
}
