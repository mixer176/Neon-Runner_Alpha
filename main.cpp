#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <iostream>
#include <vector>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800.0f, 600.0f), "GRA", sf::Style::Close | sf::Style::Titlebar); // ustaiwnie wielkoœci okna i nadanie w³aœciwoœci "guzik do zamykania i pasek tyt³u"

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));//ustawienie widoku

		 ///////////tworzenie tektury///////////////////////
	sf::Texture playerTexture;
	playerTexture.loadFromFile("animacja.png");//wczytanie z pliku
											   //player.setTexture(&playerTexture);//nadanie graczowi tekstury
	//koniec tektury///////////////////////////////////////////////////////

	std::vector<Platform> platforms; //grupowanie platform zeby nie pisac miliona linij przy zderzeniu

	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 20.0f), sf::Vector2f(500.0f, 300.0f))); // d³ugosc / wysokosc // pozycje
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(0.0f, 500.0f)));
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f, 200.0f);// wczytanie gracza z klasy Player //pierwsze wartoœci (3,9) podanie wielkosci pliku tj. ilosc linij i kolumn a drugie 0.3f to szybkosc zmiany // 100.0f predkosc poruszania



	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;


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

			case sf::Event::Resized:
				break;

			}//Switch

		}//while

		player.Update(deltaTime);

		sf::Vector2f direction;

		for (Platform& platform : platforms) // to jest to samo co for(int i = 0; i <platforms.size(); i++) { Platform& platform = platforms[i]; }
		{
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 2.0f)) //0.0f ozacza czy moge przesuwac o dziwo zero moze 2 juz nie XD
			{
				player.OnCollision(direction);
			}
		}
			
		//platform1.GetCollider().CheckCollision(player.GetCollider(), 0.0f); //0.0f ozacza czy moge przesuwac



		view.setCenter(player.GetPosition());//ustawiania œrodka widoku na gracza

		window.clear(sf::Color::Green);
		window.setView(view);

		player.Draw(window);//wywo³anie funkcji rysujacej gracza z klasy Player


		for (Platform& platform : platforms)
			platform.Draw(window);
		//platform1.Draw(window);//wywo³anie platformy z klasy Platform

		window.display();
	}//while

}//main
