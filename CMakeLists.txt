PROJECT(genfunop)

cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS " $ENV{CFLAGS} -std=gnu++0x -Wall -Wextra -pedantic ") 
SET(CMAKE_CXX_FLAGS_DEBUG " -O0 -g3 -ggdb3 ")
SET(CMAKE_CXX_FLAGS_RELEASE " $ENV{CXXFLAGS} -O2 -fomit-frame-pointer ")  

find_package( Boost 1.37.0 )
   if(Boost_FOUND)
      include_directories(${Boost_INCLUDE_DIRS})
else()
	message(FATAL_ERROR "No boost")
endif()

INCLUDE(TestForSTDNamespace)
IF( CMAKE_NO_STD_NAMESPACE )
	message(FATAL_ERROR "No 'std::' namespace support")
endif()

ADD_SUBDIRECTORY( src )