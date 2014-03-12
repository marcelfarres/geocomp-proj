# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( geocomp-proj_demo )

cmake_minimum_required(VERSION 2.6.2)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 2.8.4)
  else()
    cmake_policy(VERSION 2.6)
  endif()
endif()

find_package(CGAL QUIET COMPONENTS Core ) 
INCLUDE (${CMAKE_ROOT}/Modules/FindOpenGL.cmake)
INCLUDE (${CMAKE_ROOT}/Modules/FindGLU.cmake)
INCLUDE (${CMAKE_ROOT}/Modules/FindGLUT.cmake)
if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )
  
    # Make sure the compiler can find generated .moc files
  include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR} ${OPENGL_INCLUDE_PATH} ${GLUT_INCLUDE_PATH})  
  add_executable  (geocomp-proj_demo  cgal_render.cpp main.cpp
      edgeError.cpp)
  
  add_to_cached_list( CGAL_EXECUTABLE_TARGETS geocomp-proj_demo )
  
  
    # Link the executable to CGAL and third-party libraries
  target_link_libraries(geocomp-proj_demo ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} ${OPENGL_LIBRARIES})
  
    message(STATUS "NOTICE: This demo requires Qt3 and the CGAL Qt3 library, and will not be compiled.")
  
else()
  
    message(STATUS "NOTICE: This demo requires the CGAL library, and will not be compiled.")
  
endif()

