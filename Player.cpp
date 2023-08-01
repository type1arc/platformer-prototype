#include "Player.h"

Player::Player()
{
	InitTextures();
	InitAnimation();
}

Player::~Player()
{
}

sf::Vector2f Player::GetPosition()
{
	return m_PlayerSprite.getPosition();
}

void Player::InitVariables()
{
	m_DeltaTime = 0;
	isIdle = true;
	player_velocity = sf::Vector2f(0.0f, 0.0f);
	jump_speed = 20.0f;
}

void Player::UpdateAnimation()
{
	m_PlayerSprite.setTextureRect(animation->uvRect);

	if (isIdle)
	{
		animation->Update(0, m_DeltaTime);
		m_PlayerSprite.setTextureRect(sf::IntRect(sf::Vector2i(450, 0), sf::Vector2i(474, 550)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		animation->Update(0, m_DeltaTime);
		m_PlayerSprite.setTextureRect(sf::IntRect(sf::Vector2i(450, 0), sf::Vector2i(474, 550)));
		isIdle = true;
	}

	if (!isIdle)
		m_PlayerSprite.setTextureRect(animation->uvRect);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		sf::Vector2f position = m_PlayerSprite.getPosition();
		position.x -= 10;
		m_PlayerSprite.setPosition(position);

		animation->Update(2, m_DeltaTime);
		isIdle = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		isIdle = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		sf::Vector2f position = m_PlayerSprite.getPosition();
		position.x += 10;
		m_PlayerSprite.setPosition(position);

		animation->Update(1, m_DeltaTime);
		isIdle = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		isIdle = true;
	}

}

void Player::InitTextures()
{
	m_PlayerTexture.loadFromFile("textures/character.png");
	m_PlayerSprite.setTexture(&m_PlayerTexture);
	m_PlayerSprite.setSize(sf::Vector2f(50.0f, 75.0f));
	m_PlayerSprite.setOrigin(0, 0);
	m_PlayerSprite.setPosition(2480, 0);
}

void Player::InitAnimation()
{
	animation = new Animation(&m_PlayerTexture, sf::Vector2u(4, 4), 0.1f);
}

void Player::Update()
{
	UpdateAnimation();
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(m_PlayerSprite);
}
