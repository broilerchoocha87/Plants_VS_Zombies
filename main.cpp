#include <SFML/Graphics.hpp>
#include <ctime>
#include "Game.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(1014, 600), "My Window");
	window.setSize(sf::Vector2u(1014, 600));

	Game game;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}



		game.handleInput(window);
		//game.update();
		game.render(window);
        game.handleInput(window);
		window.display();
		window.clear();
	}
	return 0;
}
