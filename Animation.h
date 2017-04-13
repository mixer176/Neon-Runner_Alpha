#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>


class Animation
{
public: //publiczne funkcje
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	Animation();

	void Update(int row, float deltaTime, bool faceRight);

public: //publiczne zmienne
	sf::IntRect uvRect;

private:        //prywatne zmienne
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};

#endif // ANIMATION_H
