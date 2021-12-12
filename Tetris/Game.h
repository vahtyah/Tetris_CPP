#pragma once
#include "Tiles.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::CircleShape cir;

	Tiles* tiles;

	bool endGame;

	void initTiles();
	void initVariables();
	void initWindow();

public:
	Game();
	~Game();

	const bool running() const;
	const bool endgame() const;

	void pollEvent();
	void updateTiles();
	void update();
	void renderTiles();
	void render();
};

