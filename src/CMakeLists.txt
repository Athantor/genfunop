SET(CMAKE_CXX_FLAGS "-std=gnu++98 -Wall -Wextra " )

SET(SRCS 
	genfunop
	World
	Population
	Creature
	Chromosome
	World_3df
)


ADD_EXECUTABLE(genfunop ${SRCS} )