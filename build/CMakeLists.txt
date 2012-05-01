
#=============================================================================
#
# BreakoutClone GPL Source Code
# Copyright (C) 2012 Leo Walsh
#
# This file is part of the BreakoutClone GPL Source Code.  
#
# BreakoutClone Source Code is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# BreakoutClone Source Code is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with BreakoutClone Source Code.  If not, see <http://www.gnu.org/licenses/>.
#
#==============================================================================


CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(breakout_clone)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

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
