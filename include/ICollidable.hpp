/*
 * ICollidable.hpp
 *
 *  Created on: Apr 6, 2012
 *      Author: leo
 */

#ifndef ICOLLIDABLE_HPP_
#define ICOLLIDABLE_HPP_

namespace game
{
	class ICollidable
	{
	public:
		virtual ~ICollidable(){}
		virtual void Collide(sf::Rect<float>)=0;
	};
};


#endif /* ICOLLIDABLE_HPP_ */
