#include "Game.h"

#include "Core.h"


Game::Game()
	: m_Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Conway's Game of Life!")
{
}


void Game::run()
{
	while (m_Window.isOpen())
	{
		handleEvents();
		update();
		draw();
	}
}


void Game::handleEvents()
{
	while (m_Window.pollEvent(m_Event))
	{
		switch (m_Event.type)
		{
		case sf::Event::Closed:
			m_Window.close();
			break;
		}
	}
}

void Game::update()
{
}

void Game::draw()
{
	m_Window.clear(sf::Color::Red);

	m_Window.display();
}
