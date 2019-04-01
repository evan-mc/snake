#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>

class Food
{
public:

	Food();

	void generateFood(const std::vector<sf::RectangleShape>& snake);

	void draw(sf::RenderWindow& window);

	const sf::CircleShape& getSprite() const;

	~Food();
private:
	sf::CircleShape foodShape;

};

#endif