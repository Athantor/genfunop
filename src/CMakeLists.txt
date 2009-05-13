SET(SRCS 
	genfunop
	World
	Population
	Creature
	Chromosome
	World_3df
)

if(NOT CHROMSIZE)
	message(STATUS "As CHROMSIZE is not given, default size of 50 bits is going to be used.")
	SET(CHROMSIZE 50)
else()
	message(STATUS "Got CHROMSIZE = ${CHROMSIZE}")
endif()

add_definitions(-DCHROMSIZE=${CHROMSIZE})

ADD_EXECUTABLE(genfunop ${SRCS} )
