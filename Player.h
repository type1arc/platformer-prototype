#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"
#include "Collision.h"

#include <iostream>

class Player
{
	private:
	public:
		Player();
		~Player();

		sf::RectangleShape m_PlayerSprite;
		sf::Texture m_PlayerTexture;

		Animation* animation;

		float m_DeltaTime;
		sf::Clock m_Clock;

		bool isIdle;
		sf::Vector2f player_velocity;

		Collision GetCollision() { return Collision(m_PlayerSprite); }

		float jump_speed;

		sf::Vector2f GetPosition();

		void InitVariables();
		void UpdateAnimation();
		void InitTextures();
		void InitAnimation();
		void Update();
		void Render(sf::RenderTarget* target);
		
};

