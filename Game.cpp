#include "Game.h"

Game::Game()
{
	InitWindow();
	InitVariables();
	InitView();
	InitGround();
	InitCloud();
	
}

Game::~Game()
{
}

void Game::Run()
{
	Update();
	Render();
}

void Game::InitWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), "Game", sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::InitView()
{
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(window->getSize().x * 1.3, window->getSize().y * 1.3));
}

void Game::InitVariables()
{
	VIEW_WIDTH = window->getSize().x;
	VIEW_HEIGHT = window->getSize().y;



}

void Game::InitCloud()
{
	cloud = new Clouds(window);
}

void Game::InitGround()
{
	ground = new Ground(window, &player, &jump_speed);
}

void Game::PollEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
	}
	
}

void Game::Update()
{
	player.m_DeltaTime = player.m_Clock.restart().asSeconds();

	PollEvents();
	view->setCenter(player.GetPosition());
	player.Update();

	cloud->Update();

	ground->Making_player_stand_on_ground();
}

void Game::Render()
{
	window->clear(sf::Color(0, 123, 255));

	ground->InitPlatform();
	ground->platform->GetCollision().CheckCollision(player.GetCollision(), 1.0f);

	window->setView(*view);

	ground->Render(window);
	cloud->SpawnClouds(window);

	player.Render(window);

	window->display();
}
