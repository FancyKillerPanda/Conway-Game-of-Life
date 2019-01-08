#include "Game.h"

#include <random>
#include <iostream>

#include "Core.h"


Game::Game()
	: m_Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Conway's Game of Life!"),
		m_AliveCell(sf::Vector2f(CELL_WIDTH, CELL_WIDTH)),
		m_DeadCell(sf::Vector2f(CELL_WIDTH, CELL_WIDTH))
{
#ifndef SHOW_FRAME_RATE
	m_Window.setFramerateLimit(3);
#endif // SHOW_FRAME_RATE

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10);

	for (unsigned int i = 0; i < NUM_OF_CELLS; i++)
	{

		if (dist(rng) == 1)
		{
			m_Cells.push_back(true);
		}

		else
		{
			m_Cells.push_back(false);
		}
	}

	m_AliveCell.setFillColor(sf::Color::Black);
	m_DeadCell.setFillColor(sf::Color::White);
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
#ifdef SHOW_FRAME_RATE
	float currentTime = m_FpsClock.restart().asSeconds();
	std::cout << 1.0f / currentTime << " FPS" << std::endl;
#endif

	std::vector<bool> updates;

	for (unsigned int row = 0; row < NUM_OF_CELL_ROWS; row++)
	{
		for (unsigned int col = 0; col < NUM_OF_CELL_COLS; col++)
		{
			bool cell = getCellFromLoc(m_Cells, row, col);
			unsigned int numOfNeighbours = 0;

			for (const sf::Vector2i &move : m_NeighbourCells)
			{
				if (row > 0 && row < NUM_OF_CELL_ROWS - 1 &&
					col > 0 && col < NUM_OF_CELL_COLS - 1 &&
					getCellFromLoc(m_Cells, row + move.y, col + move.x))
				{
					numOfNeighbours += 1;
				}
			}

			bool update;

			if (!cell)
			{
				update = (numOfNeighbours == 3) ? true : false;
			}

			else
			{
				update = (numOfNeighbours == 2 || numOfNeighbours == 3) ? true : false;
			}

			updates.push_back(update);
		}
	}

	m_Cells = updates;
}

void Game::draw()
{
	m_Window.clear(sf::Color::Red);

	for (unsigned int row = 0; row < NUM_OF_CELL_ROWS; row++)
	{
		for (unsigned int col = 0; col < NUM_OF_CELL_COLS; col++)
		{
			if (!getCellFromLoc(m_Cells, row, col))
			{
				m_DeadCell.setPosition((float) (col * CELL_WIDTH), (float) (row * CELL_WIDTH));
				m_Window.draw(m_DeadCell);
			}

			else
			{
				m_AliveCell.setPosition((float) (col * CELL_WIDTH), (float) (row * CELL_WIDTH));
				m_Window.draw(m_AliveCell);
			}
		}
	}

	m_Window.display();
}
