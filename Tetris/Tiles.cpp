#include "Tiles.h"

void Tiles::initVariables()
{
	this->figures[7][4] =
	{
1,3,5,7, // I
2,4,5,7, // Z
3,5,4,6, // S
3,5,4,7, // T
2,3,5,7, // L
3,5,7,6, // J
2,3,4,5, // O
	};
}

void Tiles::initTexture()
{

	if (!this->texture.loadFromFile("Texture/SkardFlatAtlas.png"))
	{
		std::cout << "ile tiles does not exits" << std::endl;
	}
}

void Tiles::initSprites()
{
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.1f, 0.1f);
	this->sprite.setColor(sf::Color::Red);
	this->sprite.setPosition(sf::Vector2f(20.f, 10.f));
}

Tiles::Tiles()
{
	this->initVariables();
	this->initTexture();
	this->initSprites();

}

Tiles::~Tiles()
{
}

void Tiles::update()
{
}

void Tiles::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
