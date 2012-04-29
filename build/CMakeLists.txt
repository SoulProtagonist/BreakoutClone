CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(breakout_clone)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

FIND_PACKAGE(SFML COMPONENTS system window graphics)

INCLUDE_DIRECTORIES(
	../include
	${SFML_INCLUDE_DIR}
)

SET(SRC 
	../src/Ball.cpp
	../src/Block.cpp
	../src/DynamicEntity.cpp
	../src/Entity.cpp
	../src/main.cpp
	../src/Paddle.cpp
)

ADD_EXECUTABLE(BreakoutClone 
	${SRC} 
)

TARGET_LINK_LIBRARIES(BreakoutClone ${SFML_LIBRARIES})
