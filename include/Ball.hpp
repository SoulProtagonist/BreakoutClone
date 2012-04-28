/*
 * Ball.hpp
 *
 *  Created on: Apr 7, 2012
 *      Author: leo
 */

#ifndef BALL_HPP_
#define BALL_HPP_

#include "DynamicEntity.hpp"
#include "ICollidable.hpp"

namespace game {

	class Ball: public game::DynamicEntity, ICollidable
	{
	public:
		Ball();
		virtual ~Ball();

		virtual void Init();
		virtual void Collide(sf::Rect<float>);
	};

} /* namespace game */
#endif /* BALL_HPP_ */
