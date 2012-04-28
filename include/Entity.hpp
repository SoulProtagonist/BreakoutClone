/*
 * Entity.h
 *
 *  Created on: Apr 6, 2012
 *      Author: leo
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
