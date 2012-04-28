/*
 * Block.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: leo
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
