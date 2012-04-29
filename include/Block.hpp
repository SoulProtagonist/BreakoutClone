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

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "Entity.hpp"
#include "ICollidable.hpp"

namespace game {

class Block: public game::Entity, public game::ICollidable {
public:
	Block(sf::Color col = sf::Color());
	virtual ~Block();

	virtual void Init();
	virtual void Collide(sf::Rect<float>);
	bool isBlockHit();

private:
	sf::Color m_color;
	sf::Texture m_tex;
	bool isHit;
};

} /* namespace game */
#endif /* BLOCK_HPP_ */
