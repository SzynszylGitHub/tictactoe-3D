#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Block.h"
#include "Set.h"

#define width 800
#define height 1000


int main()
{
    std::string adres = "asset/schematic.png";
    Set set(adres);
    set.addBlock(adres, sf::Vector2f(0, 0));
    set.addBlock(adres, sf::Vector2f(0, 1));
    set.addBlock(adres, sf::Vector2f(0, 2));
    
    set.setPosition(sf::Vector2f(200, 0));
   
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
