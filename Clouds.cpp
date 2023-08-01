#include "Clouds.h"

Clouds::Clouds(sf::RenderWindow* window)
{
	InitCloud();

}

Clouds::~Clouds()
{
}

void Clouds::InitCloud()
{
	m_CloudTexture.loadFromFile("Textures/cloud.png");
	m_Cloud.setTexture(&m_CloudTexture);
	m_Cloud.setSize(sf::Vector2f(195.0f, 93.0f));

	clouds.push_back(m_Cloud);
}

void Clouds::SpawnClouds(sf::RenderWindow* window)
{
	for (auto& x : clouds)
	{
		for (int i = 0; i <= 10; i++)
		{
			x.setPosition(x.getSize().x * 3 * i, x.getPosition().y);
			window->draw(x);
		}
	}
}

void Clouds::Update()
{
	for (auto& x : clouds)
	{
		x.move(-10.0f, 0.0f);
	}

	std::cout << "HELLO WORLD" << std::endl;
}

void Clouds::Render(sf::RenderWindow* window)
{
}
