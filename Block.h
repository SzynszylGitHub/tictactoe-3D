#pragma once
#include "SFML/Graphics.hpp"

class Block : public sf::Sprite
{
public:
    Block(const sf::Texture&, sf::Vector2f Position = sf::Vector2f(0, 0));
    sf::Vector2f translateToIsometricGrid(sf::Vector2f);
};
