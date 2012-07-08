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

#include "../include/Level.hpp"
#include <sstream>

namespace game
{
    void Level::SetupBlocks(int width)
    {
	_blocks.clear();

	// create a list of colors
	std::list<sf::Color> color;
	color.push_back(sf::Color::Blue);
	color.push_back(sf::Color::Cyan);
	color.push_back(sf::Color::Green);
	color.push_back(sf::Color::Magenta);
	color.push_back(sf::Color::Yellow);
	color.push_back(sf::Color::Red);

	typedef std::list<sf::Color>::const_iterator list_c_iter;
	// create blocks
	int y = 0;
	for(list_c_iter color_iter = color.begin(); color_iter != color.end(); color_iter++)
	{
	    for(int x = 0; x < width - 95; x += 100 )
	    {
		game::Block blk(*color_iter);
		blk.SetPosition(sf::Vector2f(x + 5, y + 5));
		_blocks.push_back(blk);
	    }
	    y += 35;
	}
    }

    void Level::SetupBounds(sf::Vector2f const * const extents)
    {
	sf::RectangleShape bound;

        // create bottom bound
	bound.setPosition(0, extents->y);
	bound.setSize(sf::Vector2f(extents->x, 10));
	_bounds.push_back(bound);

	// create top bound
	bound.setPosition(0, 0 - bound.getSize().y);
	_bounds.push_back(bound);

	// create left bound
	bound.setSize(sf::Vector2f(10, extents->y));
	bound.setPosition(0 - bound.getSize().x, 0);
	_bounds.push_back(bound);

	// create right bound
	bound.setPosition(extents->x, 0);
	_bounds.push_back(bound);	
    }

    void Level::SetupScene(sf::RenderWindow const * const App)
    {
	_ballsLeft = 3;
	_yVelocity = 500;

	// setup blocks
	SetupBlocks(App->getSize().x);

	// set paddle position and velocity
	_paddle.SetVelocity(sf::Vector2f(0,0));
	_paddle.SetPosition(sf::Vector2f(App->getView().getCenter().x,
					 App->getView().getSize().y - 30));

	// set ball position and velocity
	_ball.SetVelocity(sf::Vector2f(0,_yVelocity));
	_ball.SetPosition(App->getView().getCenter());

	// setup bounds
	SetupBounds(&App->getView().getSize());
    }

    void Level::HandleEvents(sf::Event const * const evt)
    {
	if(evt->type == sf::Event::KeyPressed)
	{
	    if(evt->key.code == sf::Keyboard::Left) _paddle.SetVelocity(sf::Vector2f(-450, 0));
	    if(evt->key.code == sf::Keyboard::Right) _paddle.SetVelocity(sf::Vector2f(450, 0));
	}

	if(evt->type == sf::Event::KeyReleased)
	{
	    if(evt->key.code == sf::Keyboard::Left || evt->key.code == sf::Keyboard::Right)
		_paddle.SetVelocity(sf::Vector2f(0,0));
	}
    }

    void Level::CollisionBounds(sf::RenderWindow const * const App)
    {
	std::list<sf::RectangleShape>::const_iterator iter = _bounds.begin();
	
	// ball.Collide(bottom.getGlobalBounds());
	// test if ball collides with the lowest boundary
	// if it does reduce the number of balls the player
	// has left by one
	if(_ball.GetAABB().intersects(iter->getGlobalBounds()))
	{
	    _ballsLeft--;
	    _ball.SetPosition(sf::Vector2f(App->getView().getCenter().x, App->getView().getCenter().y));

	    // send ball towards paddle
	    sf::Vector2f vel;
	    vel.y = _yVelocity;
	    
	    // work out x component neccessary to send ball toward paddle
	    sf::Vector2f dist;
	    dist.y = _paddle.GetAABB().top - _ball.GetAABB().top;
	    dist.x = (_paddle.GetAABB().left + _paddle.GetAABB().width/2) - _ball.GetAABB().left;

	    float time = dist.y / vel.y;
	    vel.x = dist.x / time;

	    _ball.SetVelocity(vel);
	}
	iter++;
	
	while(iter != _bounds.end())
	{
	    _ball.Collide(iter->getGlobalBounds());
	    _paddle.Collide(iter->getGlobalBounds());
	    iter++;
	}
    }

    void Level::UpdatePosition(sf::RenderWindow const * const App, sf::Time const * const time)
    {
	_ball.UpdatePosition(*time);
	_paddle.UpdatePosition(*time);

	CollisionBounds(App);
	
	_ball.Collide(_paddle.GetAABB());
	
	typedef std::list<game::Block>::iterator block_iter;
	block_iter iter = _blocks.begin();
	while(iter != _blocks.end())
	{
	    iter->Collide(_ball.GetAABB());
	    if(iter->isBlockHit())
	    {
		_ball.Collide(iter->GetAABB());
		iter = _blocks.erase(iter);
	    }
	    else
	    {
		iter++;
	    }
	}
    }

    void Level::Draw(sf::RenderWindow * const App)
    {
	_ball.OnDraw(App);
	_paddle.OnDraw(App);
	
	for(std::list<Block>::iterator iter = _blocks.begin(); iter != _blocks.end(); iter++)
	{
	    iter->OnDraw(App);
	}

	std::stringstream sstr;
	sstr << "Balls:" << _ballsLeft;
	sf::Text BallsLeftText(sstr.str());
	BallsLeftText.setPosition(5.0f, 5.0f);
	App->draw(BallsLeftText);
    }

    bool Level::HasPlayerWon()
    {
	if(_blocks.size() == 0)
	    return true;
	else
	    return false;
    }

    bool Level::HasPlayerLost()
    {
	if(_ballsLeft < 0)
	    return true;
	else
	    return false;
    }
}
