#pragma once

#include <SFML/Graphics.hpp>

#include "Collision.h"

class Platform
{
	public:
		Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
		~Platform();

		void Render(sf::RenderWindow* window);
		Collision GetCollision() { return Collision(body); }

		sf::RectangleShape body;
};

