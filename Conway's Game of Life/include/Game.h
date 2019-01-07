#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "Core.h"


class Game
{
private:
	sf::RenderWindow m_Window;
	sf::Event m_Event;

	std::vector<bool> m_Cells;
	const std::array<sf::Vector2i, 8> m_NeighbourCells = {
		sf::Vector2i(-1, -1), sf::Vector2i(0, -1), sf::Vector2i(1, -1),
		sf::Vector2i(-1,  0),					   sf::Vector2i(1,  0),
		sf::Vector2i(-1,  1), sf::Vector2i(0,  1), sf::Vector2i(1,  1)
	};

	sf::RectangleShape m_AliveCell;
	sf::RectangleShape m_DeadCell;

private:
	void handleEvents();
	void update();
	void draw();

	inline bool getCellFromLoc(std::vector<bool> cells, unsigned int row, unsigned int col) const
	{
		return cells[row * NUM_OF_CELL_COLS + col];
	}

public:
	Game();

	void run();
};
