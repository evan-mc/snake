#include "Player.h"

Player::Player()
{
	player.push_back(sf::RectangleShape(sf::Vector2f(30, 30)));
	playerPos.push_back(player[0].getPosition());
}

void Player::draw(sf::RenderWindow& window)
{
	for (const auto& idx : player)
	{
		window.draw(idx);
	}
}

void Player::movePlayer(float x, float y)
{
	player[0].move(x, y);
	for (size_t i = player.size()-1; i > 0; --i)
	{
		player[i].setPosition(player[i - 1].getPosition());
	}
}

const std::vector<sf::RectangleShape>& Player::getBody() const
{
	return player;
}

const sf::RectangleShape& Player::getSprite() const
{
	return player[0];
}

void Player::growSnake()
{
	for (int i = 0; i < 5; ++i)
	{
		player.push_back(sf::RectangleShape(sf::Vector2f(30, 30)));

		size_t lastIdx = player.size() - 1;
		player[lastIdx].setPosition(player[lastIdx-1].getPosition());
	}
}

Player::~Player()
{
}