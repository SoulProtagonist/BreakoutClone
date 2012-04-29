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
