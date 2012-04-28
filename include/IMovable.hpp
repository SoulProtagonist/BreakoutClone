/*
 * IMovable.hpp
 *
 *  Created on: Apr 6, 2012
 *      Author: leo
 */

#ifndef IMOVABLE_HPP_
#define IMOVABLE_HPP_

#include <SFML/Graphics.hpp>

namespace game
{
	class IMovable
	{
	public:
		virtual ~IMovable(){}
		virtual void SetVelocity(sf::Vector2f)=0;
		virtual sf::Vector2f GetVelocity()=0;
		virtual void UpdatePosition(sf::Time)=0;
	};
};


#endif /* IMOVABLE_HPP_ */
