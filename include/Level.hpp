/*
=============================================================================

BreakoutClone GPL Source Code
Copyright (C) 2012 Leo Walsh

This file is part of the BreakoutClone GPL Source Code.  

BreakoutClone Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BreakoutClone Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BreakoutClone Source Code.  If not, see <http://www.gnu.org/licenses/>.

==============================================================================
*/

#ifndef __LEVEL_HPP__
#define __LEVEL_HPP__

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include <SFML/Graphics.hpp>
#include <list>

namespace game 
{
    class Level
    {
    private:
	Ball _ball;
	Paddle _paddle;
	std::list<Block> _blocks;
	std::list<sf::RectangleShape> _bounds;
	int _ballsLeft;

	void SetupBlocks(int width);
	void SetupBounds(sf::Vector2f const * const extents);
	void CollisionBounds(sf::RenderWindow const * const App);

    public:
	Level(){};
	~Level(){};

	void SetupScene(sf::RenderWindow const * const);
	void HandleEvents(sf::Event const * const);
	void UpdatePosition(sf::RenderWindow const * const App, sf::Time const * const);
	void Draw(sf::RenderWindow * const);
	bool HasPlayerWon();
	bool HasPlayerLost();
    };
}

#endif
