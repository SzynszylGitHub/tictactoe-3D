#pragma once
#include <map>
#include <iostream>
#include "Block.h"
#include "BetterTexture.h"
#include "SFML/Graphics.hpp"

struct Less {
public:
    constexpr bool operator()(const sf::Vector2f& v1, const sf::Vector2f& v2) const {
        if (v1.x < v2.x) return true;
        if (v1.x > v2.x) return false;
        return v1.y < v2.y;
    }
};

class Set {
public:
    Set(const std::string& textureAdress, sf::Vector2f position = sf::Vector2f(0, 0));
    Set(const std::map<std::string, BetterTexture>& textures, sf::Vector2f position = sf::Vector2f(0, 0));

    void addBlock(const std::string textureAdress, sf::Vector2f position);
    void deleteBlock(sf::Vector2f position);
    void listTexture();

    void addTexture(const std::string textureAdress);
    void draw(sf::RenderWindow& window) const;


    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;

private:
    sf::Vector2f _position;
    std::map<std::string, BetterTexture> Asset;
    std::map<sf::Vector2f, std::unique_ptr<Block>, Less> Blocks;
};
