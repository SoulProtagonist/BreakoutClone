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

#include "../include/Block.hpp"

namespace game {

	Block::Block(sf::Color col)
    {
		m_color = col;
		isHit = false;
    }

    Block::~Block()
    {
        // TODO Auto-generated destructor stub
    }

    void Block::Init()
    {
    	sf::Image img;
    	img.create(90, 25, m_color);
    	m_tex.loadFromImage(img);
    	m_sprite.setTexture(m_tex);
    }

    void Block::Collide(sf::Rect<float> rect)
    {
    	if(m_sprite.getGlobalBounds().intersects(rect))
    	{
    		isHit = true;
    	}
    }

    bool Block::isBlockHit()
    {
    	return isHit;
    }

} /* namespace game */
