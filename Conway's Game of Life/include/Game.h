#pragma once

#include <SFML/Graphics.hpp>


class Game
{
private:
	sf::RenderWindow m_Window;
	sf::Event m_Event;

public:
	Game();

	void run();

	void handleEvents();
	void update();
	void draw();
};
