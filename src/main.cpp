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
#include "../include/Level.hpp"
#include <list>
#include <iostream>
#include <sstream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum GAME_STATE{START, RUNNING, LOSE, WIN};

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

void writeScreen(sf::RenderWindow* const App, char const * str)
{
    sf::Text text(str);
    text.setPosition(App->getView().getCenter().x - text.getGlobalBounds().width/2, App->getView().getCenter().y - text.getGlobalBounds().height/2);
    App->clear();
    App->draw(text);
    App->display();
}

int main(int argc, char** argv)
{
    sf::RenderWindow App(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Breakout Clone");
    GAME_STATE state = START;
  
    sf::View GameView(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
  
    // Set the view
    App.setView(GameView);

    // Create level
    game::Level level;
    
    sf::Clock clock;
    clock.restart();

    sf::Clock gameOverClock;
  
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
		if(evt.key.code == sf::Keyboard::Return) 
		{
		    if(state == START)
		    {
			state = RUNNING; 
			level.SetupScene(&App);
		    }
		}
	    }
	    
	    if(evt.type == sf::Event::Resized)
	    {
		std::cout << "width:" << evt.size.width << " height:" << evt.size.height << std::endl;
		resizeWindow(&App);
		sf::FloatRect viewRect = App.getView().getViewport();
		std::cout << "vp.left:" << viewRect.left << " vp.top:" << viewRect.top << " vp.width:" << viewRect.width << " vp.height:" << viewRect.height << std::endl;
	    }

	    level.HandleEvents(&evt);
	}
	
	if(state == START)
	{
	    writeScreen(&App, "Press \"return\" to start");
	    continue;
	}

	if(state == LOSE || state == WIN)
	{
	    if(state == LOSE)
		writeScreen(&App, "Game Over");
	    else
		writeScreen(&App, "You Won");

	    if(gameOverClock.getElapsedTime().asSeconds() > 10)
	    {
		state = START;
	    } 

	    continue;
	}

	if(level.HasPlayerLost())
	{
	    state = LOSE;
	    gameOverClock.restart();
	}

	if(level.HasPlayerWon())
	{
	    state = WIN;
	    gameOverClock.restart();
	}

	level.UpdatePosition(&App, &time);
	
	App.clear();
	level.Draw(&App);
	App.display();
    }
    
    return 0;
}

