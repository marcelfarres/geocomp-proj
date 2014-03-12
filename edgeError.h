#ifndef _edgeError_H
#define _edgeError_H

// typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
// typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
// typedef Polyhedron::Vertex_iterator Vertex_iterato
// typedef K::Point_2 P;
// typedef T::Vertex_handle Vh;
// typedef T::Vertex_iterator Vi;
// typedef T::Edge_iterator Ei;
// C++ libraries
#include <iostream>
#include <fstream>
#include "edgeError.h"

// 3D libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h> 

// our libraries
#include "cgal_render.h"

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Edge_iterator Ei;


int getError (Ei edges, Polyhedron p);
#endif 
