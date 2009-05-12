SET(EXECUTABLE_OUTPUT_PATH ".") 

SET(SRCS 
	genfunop
	World
	Population
	Creature
)


ADD_EXECUTABLE(genfunop ${SRCS} )