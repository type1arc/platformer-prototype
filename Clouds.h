#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <random>

class Clouds
{
	private:

	public:
		Clouds(sf::RenderWindow* window);
		~Clouds();

		sf::RectangleShape m_Cloud;
		std::vector<sf::RectangleShape> clouds;

		sf::Texture m_CloudTexture;



		void InitCloud();
		void SpawnClouds(sf::RenderWindow* window);
		void Update();
		void Render(sf::RenderWindow* window);
};