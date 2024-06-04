#include "Block.h"
#include <iostream>

Block::Block(const BetterTexture& texture, sf::Vector2f position)
    : sf::Sprite(texture), _position(position), adres(texture.getAdres())
{
    sf::Vector2f newPos = translateToIsometricGrid(position);
    setPosition(newPos);
    //std::cout << newPos.x <<"," << newPos.y << std::endl;
}

void Block::scaleImg(sf::Vector2f scale) {
    setScale(scale);
}

sf::Vector2f Block::getPositionCartesianSystem() {
    return _position;
}

std::string Block::getAdres() {
    return adres;
}

sf::Vector2f Block::translateToIsometricGrid(sf::Vector2f position) {
    float w = getTexture()->getSize().x;
    float h = getTexture()->getSize().y;
    float x = position.x;
    float y = position.y;
  // std::cout << "input: [" << position.x << "," << position.y << "]\n";

    sf::Vector2f i(x * 0.5 * w, x * 0.25 * h);
    sf::Vector2f j(-y * 0.5 * w, y * 0.25 * h);

    sf::Vector2f result = i + j;
    //std::cout << "normal -> isometric : [" << result.x << "," << result.y << "]\n";

    return result;
}

sf::Vector2f Block::translateToIsometricGridScaled(sf::Vector2f position,sf::Vector2f Scale) {
    float w = getTexture()->getSize().x * Scale.x;
    float h = getTexture()->getSize().y * Scale.y;
    float x = position.x;
    float y = position.y;
    std::cout << "input: [" << position.x << "," << position.y << "]\n";

    sf::Vector2f i(x * 0.5 * w, x * 0.25 * h);
    sf::Vector2f j(-y * 0.5 * w, y * 0.25 * h);

    sf::Vector2f result = i + j;
    std::cout << "normal -> isometric : [" << result.x << "," << result.y << "]\n";

    return result;
}
