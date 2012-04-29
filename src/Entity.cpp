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
