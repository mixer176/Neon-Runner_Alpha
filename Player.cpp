#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)//lista inicjalizacyjna dla konstruktora animacji
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(200.0f, 200.0f);
	body.setTexture(texture);//nadanie graczowi tekstury
}



void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
	}//if
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
	}//if

	if (movement.x == 0.0f)
	{
		row = 0;
	}//if
	else
	{
		row = 1;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}//if
		else
		{
			faceRight = false;
		}//else
	}//else

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);




}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
