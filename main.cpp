#include <SFML/Graphics.hpp>
#include <ctime>
#include "Game.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;


//void createBack(RenderWindow& window) {
//	//Drawing the background
//	Image map_image;
//	map_image.loadFromFile("Images/Backgrounds/level1.png");
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//	window.draw(s_map);
//}
//
//////Drawing the map
////void createMap(RenderWindow& window) {
////	//Drawing a map
////	Image map_image;//объект изображения для карты
////	map_image.loadFromFile("Images/grid.png");//load the file for the map
////	Texture map;
////	map.loadFromImage(map_image);
////	Sprite s_map;
////	s_map.setTexture(map);
////	s_map.setPosition(300, 160);
////
////	window.draw(s_map);
////}


int main()
{
	RenderWindow window(VideoMode(1014, 600), "My Window");

	Game game;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.setSize(sf::Vector2u(1014, 600));

		game.render(window);

		window.display();
	}
	return 0;
}
