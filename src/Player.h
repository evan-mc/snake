#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Player
{
public:
	Player();

	void draw(sf::RenderWindow& window);
	void movePlayer(float x, float y);
	const std::vector<sf::RectangleShape>& getBody() const;
	const sf::RectangleShape& getSprite() const;
	void growSnake();
	

	~Player();
private:
	std::vector<sf::RectangleShape> player;
};

#endif
