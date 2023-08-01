#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Platform.h"

class Ground
{
	private:
		Player* player;
		Player* jump_speed;
	public:
		sf::RectangleShape m_Ground;
		sf::Texture m_GroundTexture;
		float m_GroundHeight;

		Platform* platform;

		Ground(sf::RenderWindow* window, Player* player, Player* jump_speed);
		~Ground();

		float m_Gravity;

		void InitGround(sf::RenderWindow* window);
		void Making_player_stand_on_ground();
		void InitGravity();
		void UpdateGravity();
		void InitVariables();
		void MovePlayer();
		void InitPlatform();

		void Render(sf::RenderWindow* window);

		
};