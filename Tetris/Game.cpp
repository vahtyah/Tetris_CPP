#include "Game.h"

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::endgame() const
{
	return this->endGame;
}

void Game::initTiles()
{
	this->tiles = new Tiles();
}

void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(500, 900);
	this->window = new sf::RenderWindow(videoMode, "Tetris");
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initTiles();
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
	delete this->tiles;
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		default:
			break;
		case sf::Event::Closed: this->window->close(); break;
		case sf::Event::KeyPressed: if (this->event.key.code == sf::Keyboard::Escape) this->window->close(); break;
		}
	}
}

void Game::updateTiles()
{
}

void Game::update()
{
	this->pollEvent();
}

void Game::renderTiles()
{
	this->tiles->render(*this->window);
}

void Game::render()
{
	sf::Texture tuan;
	tuan.loadFromFile("Texture/SkardFlatAtlas.png");
		sf::Sprite tuan1(tuan);
		tuan1.setColor(sf::Color::Cyan);
		tuan1.setScale(0.25f, 0.25f);
	this->window->clear(sf::Color::White);
	//draw
	this->renderTiles();
	//this->window->draw(tuan1);
	//this->tiles->render(*this->window);
	this->window->display();
}
