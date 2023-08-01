#include "Ground.h"

Ground::Ground(sf::RenderWindow* window, Player* player, Player* jump_speed)
{
	this->player = player;
	this->jump_speed = jump_speed;

	InitGround(window);
	InitVariables();
}

void Ground::InitGround(sf::RenderWindow* window)
{
	m_GroundTexture.loadFromFile("textures/ground.png");
	m_Ground.setTexture(&m_GroundTexture);
	m_Ground.setSize(sf::Vector2f(1141, 281));
	m_Ground.setOrigin(0, 0);
	m_Ground.setPosition(m_Ground.getPosition().x, 315.0f);
	m_GroundHeight = m_Ground.getSize().y;
}

void Ground::Making_player_stand_on_ground()
{
	if (player->m_PlayerSprite.getPosition().y > m_GroundHeight)
	{
		player->m_PlayerSprite.setPosition(player->m_PlayerSprite.getPosition().x, m_GroundHeight);
		player->player_velocity.y = 0;
		std::cout << "PLAYER::INTERSECTING::GROUND" << std::endl;
	}
	else if (player->m_PlayerSprite.getPosition().y < m_GroundHeight)
		InitGravity();

	if (player->m_PlayerSprite.getPosition().y >= m_GroundHeight)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			player->player_velocity.y -= 15.0f;
			player->m_PlayerSprite.move(player->player_velocity);
		}
	}
}

void Ground::InitGravity()
{	
	player->player_velocity.y += m_Gravity;
	player->m_PlayerSprite.move(player->player_velocity);
	std::cout << "PLAYER::FALLING" << std::endl;
}

void Ground::UpdateGravity()
{
}

void Ground::InitPlatform()
{
	platform = new Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 200.0f));
}

void Ground::Render(sf::RenderWindow* window)
{
	for (int i = 0; i <= 5; i++)
	{
		m_Ground.setPosition(m_Ground.getSize().x * i, 315);
		window->draw(m_Ground);
	}
	platform->Render(window);
}

void Ground::InitVariables()
{
	m_Gravity = 1.0f;
}
