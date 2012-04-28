/*
 * DynamicEntity.cpp
 *
 *  Created on: Apr 7, 2012
 *      Author: leo
 */

#include "../include/DynamicEntity.hpp"

namespace game {

	DynamicEntity::DynamicEntity():m_velocity(sf::Vector2f(0,0))
	{
		// TODO Auto-generated constructor stub
	}

	DynamicEntity::~DynamicEntity()
	{
		// TODO Auto-generated destructor stub
	}

    void DynamicEntity::SetVelocity(sf::Vector2f vec)
    {
    	m_velocity = vec;
    }

    sf::Vector2f DynamicEntity::GetVelocity()
    {
    	return m_velocity;
    }

    void DynamicEntity::UpdatePosition(sf::Time time)
    {
    	m_sprite.setPosition(m_sprite.getPosition().x + (m_velocity.x * time.asSeconds()), m_sprite.getPosition().y + (m_velocity.y * time.asSeconds()));
    }

} /* namespace game */
