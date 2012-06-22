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

#include <SFML/Graphics.hpp>
#include "../include/Ball.hpp"
#include "../include/Paddle.hpp"
#include "../include/Block.hpp"
#include <list>
#include <iostream>
#include <sstream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void setupBlocks(std::list<game::Block>& list, int ScreenWidth)
{
	list.clear();

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
		for(int x = 0; x < ScreenWidth - 95; x += 100 )
		{
			game::Block blk(*color_iter);
			blk.SetPosition(sf::Vector2f(x + 5, y + 5));
			list.push_back(blk);
		}
		y += 35;
	}
}

void resizeWindow(sf::RenderWindow * App)
{
    static const float viewRatio = (float)SCREEN_WIDTH / SCREEN_HEIGHT;
    float windowRatio = (float)App->getSize().x / App->getSize().y;
    std::cout << "viewRatio:" << viewRatio << " windowRatio:" << windowRatio << std::endl; 

    sf::View newView = App->getView();
    if(windowRatio > viewRatio)
    {
		newView.setViewport(sf::FloatRect((1 - (viewRatio/windowRatio))/2, 0, (viewRatio/windowRatio), 1));
    } 
    else if(viewRatio > windowRatio)
    {
		newView.setViewport(sf::FloatRect(0, (1 - (windowRatio/viewRatio))/2, 1, (windowRatio/viewRatio)));
    }
    else
    {
		newView.setViewport(sf::FloatRect(0, 0, 1, 1));
    }
    App->setView(newView);
}

int main(int argc, char** argv)
{
	sf::RenderWindow App(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Breakout Clone");
	const int NUM_BALLS_TO_START=3;
	int BallsLeft = 0;
	bool startGame = false;

	sf::View GameView(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	// Set the view
	App.setView(GameView);

	game::Ball ball;
	ball.SetVelocity(sf::Vector2f(300,300));
	ball.SetPosition(App.getView().getCenter());
	game::Paddle paddle;
	paddle.SetVelocity(sf::Vector2f(0,0));
	paddle.SetPosition(sf::Vector2f(App.getView().getCenter().x,
			App.getView().getSize().y - 30));

	// create blocks
	std::list<game::Block> blocks;
	setupBlocks(blocks, SCREEN_WIDTH);

	// create boundaries for the screen
	sf::RectangleShape left;
	left.setSize(sf::Vector2f(10, App.getView().getSize().y));
	left.setPosition(0 - left.getSize().x, 0);

	sf::RectangleShape right = left;
	right.setPosition(App.getView().getSize().x, 0);

	sf::RectangleShape top;
	top.setSize(sf::Vector2f(App.getView().getSize().x, 10));
	top.setPosition(0, 0 - top.getSize().y);

	sf::RectangleShape bottom = top;
	bottom.setPosition(0, App.getView().getSize().y);

	sf::Clock clock;
	clock.restart();

	while(App.isOpen())
	{
		sf::Time time = clock.getElapsedTime();
		clock.restart();

		sf::Event evt;
		while(App.pollEvent(evt))
		{
			if(evt.type == sf::Event::Closed)
				App.close();

			if(evt.type == sf::Event::KeyPressed)
			{
				if(evt.key.code == sf::Keyboard::Escape) App.close();
				if(evt.key.code == sf::Keyboard::Left) paddle.SetVelocity(sf::Vector2f(-450, 0));
				if(evt.key.code == sf::Keyboard::Right) paddle.SetVelocity(sf::Vector2f(450, 0));
				if(evt.key.code == sf::Keyboard::Return) {startGame = true; BallsLeft = NUM_BALLS_TO_START;}
			}

			if(evt.type == sf::Event::KeyReleased)
			{
				if(evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::Right)
					paddle.SetVelocity(sf::Vector2f(0,0));
			}

			if(evt.type == sf::Event::Resized)
			{
			    std::cout << "width:" << evt.size.width << " height:" << evt.size.height << std::endl;
			    resizeWindow(&App);
			    sf::FloatRect viewRect = App.getView().getViewport();
			    std::cout << "vp.left:" << viewRect.left << " vp.top:" << viewRect.top << " vp.width:" << viewRect.width << " vp.height:" << viewRect.height << std::endl;
			}
		}

		if(BallsLeft == 0)
		{
			startGame = false;
		}

		if(startGame == false)
		{
			sf::Text text("Press \"return\" to start");
			text.setPosition(App.getView().getCenter().x - text.getGlobalBounds().width/2, App.getView().getCenter().y - text.getGlobalBounds().height/2);
			App.clear();
			App.draw(text);
			App.display();
		    continue;
		}

		ball.UpdatePosition(time);
		paddle.UpdatePosition(time);

		// ball.Collide(bottom.getGlobalBounds());
		// test if ball collides with the lowest boundary
		// if it does reduce the number of balls the player
		// has left by one
		if(ball.GetAABB().intersects(bottom.getGlobalBounds()))
		{
		        BallsLeft--;
			ball.SetPosition(sf::Vector2f(App.getView().getCenter().x, App.getView().getCenter().y));
		}

		ball.Collide(paddle.GetAABB());
		ball.Collide(top.getGlobalBounds());
		ball.Collide(left.getGlobalBounds());
		ball.Collide(right.getGlobalBounds());

		paddle.Collide(left.getGlobalBounds());
		paddle.Collide(right.getGlobalBounds());

		typedef std::list<game::Block>::iterator block_iter;
		block_iter iter = blocks.begin();
		while(iter != blocks.end())
		{
			iter->Collide(ball.GetAABB());
			if(iter->isBlockHit())
			{
				ball.Collide(iter->GetAABB());
				iter = blocks.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		App.clear();

		ball.OnDraw(&App);
		paddle.OnDraw(&App);

		for(block_iter iter = blocks.begin(); iter != blocks.end(); iter++)
		{
			iter->OnDraw(&App);
		}

		// add number of balls left to screen
		std::stringstream sstr;
		sstr << "Balls:" << BallsLeft;
		sf::Text BallsLeftText(sstr.str());
		BallsLeftText.setPosition(5.0f, 5.0f);
		App.draw(BallsLeftText);

		// display screen
		App.display();
	}

	return 0;
}

