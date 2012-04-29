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

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "IEntity.hpp"

namespace game
{

	class Entity : public IEntity
	{
	public:
		Entity();
		virtual ~Entity();

		virtual void OnDraw(sf::RenderWindow*);
		virtual void SetPosition(sf::Vector2f);
		virtual sf::Rect<float> GetAABB();
		virtual void Init()=0;

	protected:
		sf::Sprite m_sprite;
	};

} /* namespace game */
#endif /* ENTITY_HPP_ */
