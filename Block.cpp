#include "Block.h"
#include <iostream>

Block::Block(const sf::Texture& texture, sf::Vector2f position)
    : sf::Sprite(texture)
{
    sf::Vector2f newPos = translateToIsometricGrid(position);
    setPosition(newPos);
    //std::cout << newPos.x <<"," << newPos.y << std::endl;
}

sf::Vector2f Block::translateToIsometricGrid(sf::Vector2f position) {
    float w = getTexture()->getSize().x;
    float h = getTexture()->getSize().y;
    float x = position.x;
    float y = position.y;
    std::cout << "input: [" << position.x << "," << position.y << "]\n";

    sf::Vector2f i(x * 0.5 * w, x * 0.25 * h);
    sf::Vector2f j(-y * 0.5 * w, y * 0.25 * h);

    sf::Vector2f result = i + j;
    std::cout << "normal -> isometric : [" << result.x << "," << result.y << "]\n";

    return result;
}