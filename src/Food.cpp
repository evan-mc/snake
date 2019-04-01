#include "Food.h"

Food::Food()
{
	foodShape.setRadius(13.f);
	foodShape.setFillColor(sf::Color::White);
	foodShape.setPosition(50,50);
}

void Food::generateFood(const std::vector<sf::RectangleShape>& snake)
{
	std::default_random_engine gen(std::random_device{}());
	std::uniform_int_distribution<int> distX(0, 1050);
	std::uniform_int_distribution<int> distY(0, 690);

	int xPos;
	int yPos;
	bool notFree = true;
	while (notFree)
	{
		xPos = distX(gen);
		yPos = distY(gen);

		size_t vecSize = snake.size();
		for (size_t i = 0; i < vecSize; ++i)
		{
			if (xPos != snake[i].getPosition().x || yPos != snake[i].getPosition().y)
			{
				i = vecSize;
				notFree = false;
			}
			else
				std::cerr << "Generating new number.\n";
		}
				
	}
	foodShape.setPosition(xPos, yPos);
	std::cout << "X: " << xPos << " Y: " << yPos << std::endl;
}

void Food::draw(sf::RenderWindow& window)
{
	window.draw(foodShape);
}

const sf::CircleShape& Food::getSprite() const
{
	return foodShape;
}

Food::~Food()
{
}
