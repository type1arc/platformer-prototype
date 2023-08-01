#pragma once

#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Ground.h"
#include "Platform.h"
#include "Clouds.h"

class Game
{
	private:

		const int screen_width = 640;
		const int screen_height = 480;

		int VIEW_WIDTH;
		int VIEW_HEIGHT;

		Player player;
		Player jump_speed;

		sf::RectangleShape m_Cloud;

		Clouds* cloud;

	public:
		sf::RenderWindow* window;
		sf::Event event;
		sf::View* view;

		Ground* ground;

		Game();
		~Game();

		void Run();
		void InitWindow();
		void InitVariables();
		void InitCloud();
		void InitGround();
		void InitView();
		void PollEvents();
		void Update();
		void Render();
};

