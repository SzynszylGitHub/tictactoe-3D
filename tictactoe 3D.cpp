#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Block.h"
#include "Set.h"

#define width 1000
#define height 1000
int main()
{
    std::string adres = "asset/normal.png";
    std::vector<Set> layer;
    
    int sizeOfCube = 3;
    for (int i = 0; i <sizeOfCube ; i++) {
        
        layer.emplace_back(adres);
        for (int j = 0; j < sizeOfCube; j++)
            for (int k = 0; k < sizeOfCube; k++)
                layer[i].addBlock(adres, sf::Vector2f(j, k));
    }
    for (int i = 0; i < layer.size(); i++) {
        //layer[i].Scale(sf::Vector2f(1,1));
        layer[i].setPosition(sf::Vector2f(300, i * layer[i].getSizeOfBlock().y/2 +300 ));
    }
    std::cout << "layer size: {" << layer.size() << "}\n";
    for (int i = 0; i < layer.size(); i++) {
        std::cout << "layer[" << i << "] Number of Blocks: {" << layer[i].getNumOfBlocks() << "}\n";
        std::cout << "layer[" << i << "] Size of Blocks: {" << layer[i].getSizeOfBlock().y << "}\n";
        std::cout << "layer[" << i << "] Position: {" << layer[i].getPosition().x<<","<< layer[i].getPosition().y<< "}\n";
        layer[i].listTexture();
    }

     sf::RenderWindow window(sf::VideoMode(width, height), "Gra");
     sf::Event event;

     while (window.isOpen()) {
         while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
                 
                 window.close();
             }
         }
         window.clear();

         for (int i = layer.size() - 1; i >= 0; i--)
            layer[i].draw(window);

         window.display();

     }


    return 0;
}
