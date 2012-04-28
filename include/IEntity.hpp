/*
 * IEntity.hpp
 *
 *  Created on: Apr 6, 2012
 *      Author: leo
 */

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <SFML/Graphics.hpp>

namespace game
{
	class IEntity
	{
	public:
		virtual ~IEntity(){};
		virtual void OnDraw(sf::RenderWindow*)=0;
		virtual void SetPosition(sf::Vector2f)=0;
		virtual sf::Rect<float> GetAABB()=0;
	};
};

#endif /* IENTITY_HPP_ */
