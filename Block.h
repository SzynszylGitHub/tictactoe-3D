#pragma once
#include "SFML/Graphics.hpp"
#include "BetterTexture.h"

class Block : public sf::Sprite
{
public:
    Block(const BetterTexture&, sf::Vector2f Position = sf::Vector2f(0, 0));
    sf::Vector2f translateToIsometricGrid(sf::Vector2f);
    sf::Vector2f translateToIsometricGridScaled(sf::Vector2f position,sf::Vector2f Scale);

    void scaleImg(sf::Vector2f);
    sf::Vector2f getPositionCartesianSystem();
    std::string getAdres();
    
private:
    sf::Vector2f _position;
    std::string adres;
};
