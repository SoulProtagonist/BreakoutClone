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

#include "../include/Paddle.hpp"

namespace game {

	Paddle::Paddle() {
		// TODO Auto-generated constructor stub

	}

	Paddle::~Paddle() {
		// TODO Auto-generated destructor stub
	}

    void Paddle::Init()
    {
    	sf::Image img;
    	img.create(100, 20, sf::Color(255, 255, 255, 255));
    	sf::Texture tex;
    	tex.loadFromImage(img);
    	m_sprite.setTexture(tex);
    }

    void Paddle::Collide(sf::Rect<float> rect)
    {
    	if(!m_sprite.getGlobalBounds().intersects(rect))
    	{
    		return;
    	}

    	// only need to check x collision for sides of screen
    	if(GetVelocity().x < 0)
    	{
    		// move to the right
    		m_sprite.setPosition(rect.left + rect.width, m_sprite.getPosition().y);
    	}
    	else
    	{
    		// move to the left
    		m_sprite.setPosition(rect.left - m_sprite.getGlobalBounds().width, m_sprite.getPosition().y);
    	}

    	// stop paddle
    	SetVelocity(sf::Vector2f(0, 0));
    }

} /* namespace game */
