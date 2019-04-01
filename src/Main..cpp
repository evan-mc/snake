#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Food.h"
#include <utility>
int main() 
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML Application", sf::Style::Close);
	window.setFramerateLimit(60);

	std::pair<float, float> moveLeft = std::make_pair(-5.f, 0.0f);
	std::pair<float, float> moveRight = std::make_pair(5.f, 0.0f);
	std::pair<float, float> moveUp = std::make_pair(0.0f, -5.f);
	std::pair<float, float> moveDown = std::make_pair(0.0f, 5.f);
	std::pair<float, float> direction = moveRight;

	Player player;
	Food* foodPtr = new Food;
	foodPtr->generateFood(player.getBody());

	while (window.isOpen()) 
	{

		sf::Event evnt;
		while (window.pollEvent(evnt)) 
		{

			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (direction != moveDown)
			{
				direction = moveUp;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (direction != moveUp)
			{
				direction = moveDown;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (direction != moveRight)
			{
				direction = moveLeft;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (direction != moveLeft)
			{
				direction = moveRight;
			}
		}

		if (player.getSprite().getGlobalBounds().intersects(foodPtr->getSprite().getGlobalBounds()))
		{
			foodPtr->generateFood(player.getBody());
			player.growSnake();
		}

		player.movePlayer(direction.first, direction.second);

		window.clear();
		player.draw(window);
		foodPtr->draw(window);
		window.display();
	}

		delete foodPtr;

}