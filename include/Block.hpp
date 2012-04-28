/*
 * Block.hpp
 *
 *  Created on: Apr 11, 2012
 *      Author: leo
 */

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "Entity.hpp"
#include "ICollidable.hpp"

namespace game {

class Block: public game::Entity, public game::ICollidable {
public:
	Block(sf::Color col = sf::Color());
	virtual ~Block();

	virtual void Init();
	virtual void Collide(sf::Rect<float>);
	bool isBlockHit();

private:
	sf::Color m_color;
	sf::Texture m_tex;
	bool isHit;
};

} /* namespace game */
#endif /* BLOCK_HPP_ */
