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
#include "input.h"


typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Edge_iterator Ei;

// input inputinstance;
// int g_width, g_height;

void drawAxis() {
    // XYZ correspond to RGB. 
    // Negative coordinates are the inverse color.
    
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(2,0,0);
        glColor3f(0,1,1);
        glVertex3f(-2,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,2,0);
        glColor3f(1,0,1);
        glVertex3f(0,-2,0);
        glColor3f(0,0,1);
        glVertex3f(0,0,2);
        glColor3f(1,1,0);
        glVertex3f(0,0,-2);
    glEnd();
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  //glShadeModel(GL_FLAT);
  // setup camera
//  inputinstance.updateProjection();
//  inputinstance.updateView();
//  inputinstance.updateModel();

  //render here

  //draw  a square centered at 0,0
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_QUADS);
  glVertex3f(-3,0,3);
  glVertex3f(3,0,3);
  glVertex3f(3, 0, -3);
  glVertex3f(-3, 0, -3);
  glEnd();

  // draw axis centered at 0,0,0
  drawAxis();
  
  glFlush();
  glutSwapBuffers();
}

void onReshape(int w, int h){
//  inputinstance.onReshape(w, h);
}

void onKeyboard(unsigned char k, int x, int y){
//  inputinstance.MyKeyboardFunc(k, x, y);
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
  glutKeyboardFunc(onKeyboard);
  glutReshapeFunc(onReshape);
  glutIdleFunc(idle);

  std::ifstream polystream(argv[1]);
  Polyhedron p;
  polystream >> p;
  CGAL::set_ascii_mode(std::cout);
  for (Vertex_iterator v = p.vertices_begin(); v != p.vertices_end(); v++) {
      std::cout << v->point() << std::endl;
  }
  
  cgal_render(p);
  
  for (Ei ei = p.edges_begin(); ei != p.edges_end(); ei++) {
    double test = getError (ei, p);
  }
  
  // load a model
  
  glutSwapBuffers();
  glutMainLoop();
  return 0;
} 
