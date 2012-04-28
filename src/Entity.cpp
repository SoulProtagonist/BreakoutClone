/*
 * Entity.cpp
 *
 *  Created on: Apr 6, 2012
 *      Author: leo
 */

#include "Entity.hpp"

namespace game {

	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

    void Entity::OnDraw(sf::RenderWindow *win)
    {
    	if(m_sprite.getTexture() == NULL)
    	{
    		Init();
    	}
    	win->draw(m_sprite);
    }

    void Entity::SetPosition(sf::Vector2f pos)
    {
    	m_sprite.setPosition(pos);
    }

    sf::Rect<float> Entity::GetAABB()
    {
    	return m_sprite.getGlobalBounds();
    }

} /* namespace game */
