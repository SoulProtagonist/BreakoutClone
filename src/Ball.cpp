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


#include "../include/Ball.hpp"

namespace game {

	Ball::Ball() {
	// TODO Auto-generated constructor stub

	}

	Ball::~Ball() {
	// TODO Auto-generated destructor stub

	}

    void Ball::Init()
    {
    	sf::Image img;
    	img.create(15, 15, sf::Color(255,255,255,255));
    	sf::Texture tex;
    	tex.loadFromImage(img);
    	m_sprite.setTexture(tex);
    }

    void Ball::Collide(sf::Rect<float> rect)
    {
    	// check if objects intersect
    	if(!m_sprite.getGlobalBounds().intersects(rect))
    		return;

    	// move ball back to correct position and change velocity
    	sf::Vector2f vel = GetVelocity();

    	// keep moving the ball small increments until it no longer intersects
    	// in the opposite direction of the velocity
    	while(m_sprite.getGlobalBounds().intersects(rect))
    	{
    		float inc = -1/2000.0f;
    		m_sprite.setPosition(m_sprite.getPosition().x + (inc * vel.x), m_sprite.getPosition().y + (inc * vel.y));
    	}

    	// figure out whether it was a collision in x or y
    	float xdist;
    	xdist = abs(m_sprite.getGlobalBounds().left - (rect.left + rect.width));
    	if(abs((rect.left - (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width))) < xdist)
    	{
    		xdist = abs(rect.left - (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width));
    	}

    	float ydist;
    	ydist = abs(m_sprite.getGlobalBounds().top - (rect.top + rect.height));
    	if(abs((rect.top - (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height))) < ydist)
    	{
    		ydist = abs(rect.top - (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height));
    	}

    	// the smallest of xdist or ydist will specify which axis the collision was on
    	if(xdist < ydist)
    	{
    		SetVelocity(sf::Vector2f(-GetVelocity().x, GetVelocity().y));
    	}
    	else
    	{
    		SetVelocity(sf::Vector2f(GetVelocity().x, -GetVelocity().y));
    	}
    }

} /* namespace game */
