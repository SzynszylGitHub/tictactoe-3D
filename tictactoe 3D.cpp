#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Block.h"
#include "Set.h"

#define width 1000
#define height 1000


int main()
{
    std::string adres = "asset/schematic.png";
    Set set(adres);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            set.addBlock(adres, sf::Vector2f(i,j));
    set.setPosition(sf::Vector2f(500, 0));
    set.addTexture("asset/birds.png");
    set.addTexture("asset/cactus.png");

    std::cout << "loaded texture: \n";
    set.listTexture();

     sf::RenderWindow window(sf::VideoMode(width, height), "Gra");
     sf::Event event;

     while (window.isOpen()) {
         while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
                 
                 window.close();
             }
         }
         window.clear();

         set.draw(window);

         window.display();

     }


    return 0;
}
