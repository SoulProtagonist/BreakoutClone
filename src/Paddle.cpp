/*
 * Paddle.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: leo
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
