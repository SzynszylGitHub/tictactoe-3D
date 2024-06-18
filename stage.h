#pragma once
#include <map>
#include "Block.h"

struct Less {
public:
    constexpr bool operator()(const sf::Vector3f& v1, const sf::Vector3f& v2) const {
        
        if (v1.y < v2.y) return true;
        if (v1.y > v2.y) return false;

        if (v1.x < v2.x) return true;
        if (v1.x > v2.x) return false;
                
        return v1.z < v2.z;
    }
};

class Stage
{
public:
    Stage();
    Stage(sf::Vector2f position);
    Stage(const std::map<std::string,BetterTexture>& Assets,const sf::Vector2f position = sf::Vector2f(0, 0));
    Stage(const Stage& other);

    void addBlock(const std::string textureAdres, const sf::Vector3f position,const Type type);
    void deleteBlock(sf::Vector3f position);
    void listTexture() const;

    void setTexture(const std::string textureAdres,const sf::Vector3f position);
    void addTexture(const std::string textureAdres);
    void draw(sf::RenderWindow& handle);

    sf::Vector2f getPosition() const;
    sf::Vector2f getSizeOfBlock() const;
    int getNumOfBlocks() const;


private:
    int NumOfBlocks = 0;
    sf::Vector2f _position;
    std::map<std::string, BetterTexture> Assets;
    std::map<sf::Vector3f, std::unique_ptr<Block>, Less> Blocks;
};

