// C++ libraries
#include <iostream>
#include <fstream>

// 3D libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h> 

// our libraries
#include "cgal_render.h"
#include "edgeError.h"

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Edge_iterator Ei;

Polyhedron p;

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  //glShadeModel(GL_FLAT);
  // setup camera
  
  //render here

  //draw  a square centered at 0,0
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_QUADS);
  glVertex3f(-3,0,3);
  glVertex3f(3,0,3);
  glVertex3f(3, 0, -3);
  glVertex3f(-3, 0, -3);
  glEnd();

  cgal_render(p);

  glFlush();
  glutSwapBuffers();
}

void idle(){
  display();
}

int main(int argc, char ** argv) {
  if (argc < 2) {
      std::cout << "This program requires an argument" << std::endl;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(200, 0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Practica 3. Mesh Simpification");
  glutDisplayFunc(display);
  //glutReshapeFunc(onReshape);
  glutIdleFunc(idle);

  std::ifstream polystream(argv[1]);
  polystream >> p;
  CGAL::set_ascii_mode(std::cout);
  for (Ei ei = p.edges_begin(); ei != p.edges_end(); ei++) {
    int test = getError (ei, p);
  }
  
  // load a model
  
  glutSwapBuffers();
  glutMainLoop();
  return 0;
} 
