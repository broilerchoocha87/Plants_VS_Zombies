#pragma once

#ifndef GAME_H
#define	GAME_H

#include "levels.h"
#include"SFML/Graphics.hpp"

class Game
{
protected:

	beginnerGarden temp;

public:

	//Game();
	void handleInput();
	void update();
	void render(sf::RenderWindow& window);

};

#endif // !GAME_H