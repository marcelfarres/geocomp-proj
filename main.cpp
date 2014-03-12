// C++ libraries
#include <iostream>
#include <fstream>

// 3D libraries
#include <GL/glut.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h> 

typedef  CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Vertex_iterator Vertex_iterator;

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "This program requires an argument" << std::endl;
    }
    std::ifstream polystream(argv[1]);
    Polyhedron p;
    polystream >> p;
    CGAL::set_ascii_mode(std::cout);
    for (Vertex_iterator v = p.vertices_begin(); v != p.vertices_end(); v++) {
        std::cout << v->point() << std::endl;
    }

    
    return 0;
} 