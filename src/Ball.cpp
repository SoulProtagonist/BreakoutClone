/*
 * Ball.cpp
 *
 *  Created on: Apr 7, 2012
 *      Author: leo
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
    		float inc = -1/200.0f;
    		m_sprite.setPosition(m_sprite.getPosition().x + (inc * vel.x), m_sprite.getPosition().y + (inc * vel.y));
    	}

    	// figure out whether it was a collision in x or y
    	float xdist;
    	xdist = m_sprite.getGlobalBounds().left - (rect.left + rect.width);
    	if((rect.left - (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width)) < xdist)
    	{
    		xdist = rect.left - (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width);
    	}

    	float ydist;
    	ydist = m_sprite.getGlobalBounds().top - (rect.top + rect.height);
    	if((rect.top - (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height)) < ydist)
    	{
    		ydist = rect.top - (m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height);
    	}

    	// the smallest of xdist or ydist will specify which axis the collision was on
    	if(xdist < 0) xdist *= -1;
    	if(ydist < 0) ydist *= -1;
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
