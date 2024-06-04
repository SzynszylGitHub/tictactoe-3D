#pragma once
#include <map>
#include "Block.h"
#include "BetterTexture.h"
#include "SFML/Graphics.hpp"
#include <iostream>

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

    Set();
    Set(const std::string& textureAdres, sf::Vector2f position = sf::Vector2f(0, 0));
    Set(const std::map<std::string, BetterTexture>& textures, sf::Vector2f position = sf::Vector2f(0, 0));
    Set(const Set& other);

    void addBlock(const std::string textureAdres, sf::Vector2f position);

    void deleteBlock(sf::Vector2f position);
    void listTexture();

    void Scale(sf::Vector2f);
    void addTexture(const std::string textureAdres);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getSizeOfBlock();


    int getNumOfBlocks();
    void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition() const;
    

private:
    int NumOfBlocks = 0;
    sf::Vector2f _scale = sf::Vector2f(1, 1);
    sf::Vector2f _position;

    std::map<std::string,BetterTexture> Asset;
    std::map<sf::Vector2f, std::unique_ptr<Block>,Less> Blocks;
};
