/*
 * Paddle.hpp
 *
 *  Created on: Apr 8, 2012
 *      Author: leo
 */

#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include "DynamicEntity.hpp"
#include "ICollidable.hpp"

namespace game {

class Paddle: public game::DynamicEntity, ICollidable {
public:
	Paddle();
	virtual ~Paddle();

	virtual void Init();
	virtual void Collide(sf::Rect<float>);
};

} /* namespace game */
#endif /* PADDLE_HPP_ */
