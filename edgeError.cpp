#include "edgeError.h"

double getError (Ei edges, Polyhedron p){
	return rand()*10;
}

void deleteEdge(void) {
    std::pair<double, Halfedge_handle> edge = edges.back();
    edges.pop_back();
    std::cout << "deleting edge with error " << edge.first << std::endl;
    p.join_vertex(edge.second);
}
