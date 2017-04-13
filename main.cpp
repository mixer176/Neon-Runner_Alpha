#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GRA", sf::Style::Close | sf::Style::Titlebar); // ustaiwnie wielkoœci okna i nadanie w³aœciwoœci "guzik do zamykania i pasek tyt³u"

																									 ///////////tworzenie tektury///////////////////////
	sf::Texture playerTexture;
	playerTexture.loadFromFile("animacja.png");//wczytanie z pliku
											   //player.setTexture(&playerTexture);//nadanie graczowi tekstury
											   //koniec tektury///////////////////////////////////////////////////////

	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);// wczytanie gracza z klasy Player //pierwsze wartoœci (3,9) podanie wielkosci pliku tj. ilosc linij i kolumn a drugie 0.3f to szybkosc zmiany // 100.0f predkosc poruszania

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event zdarzenie;
		while (window.pollEvent(zdarzenie))
		{
			switch (zdarzenie.type)
			{
			case sf::Event::KeyPressed:
				if (zdarzenie.key.code == sf::Keyboard::Escape)
				{
					printf("\nOkno jest zamykane...\n");
					window.close();
				}
				break;

			case sf::Event::Closed:
				printf("\nOkno jest zamykane...\n");
				window.close();
				break;

			}//Switch

		}//while

		player.Update(deltaTime);


		window.clear(sf::Color::Black);
		player.Draw(window);//wywo³anie funkcji rysujacej gracza z klasy Player
		window.display();
	}

	return 0;
}
