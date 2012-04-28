/*
 * DynamicEntity.hpp
 *
 *  Created on: Apr 7, 2012
 *      Author: leo
 */

#ifndef DYNAMICENTITY_HPP_
#define DYNAMICENTITY_HPP_

#include "Entity.hpp"
#include "IMovable.hpp"

namespace game
{

	class DynamicEntity: public game::Entity, IMovable
	{
	public:
		DynamicEntity();
		virtual ~DynamicEntity();

		virtual void SetVelocity(sf::Vector2f);
		virtual sf::Vector2f GetVelocity();
		virtual void UpdatePosition(sf::Time);

	private:
		sf::Vector2f m_velocity;
	};

} /* namespace game */
#endif /* DYNAMICENTITY_HPP_ */
