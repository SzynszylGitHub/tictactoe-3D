#include "Set.h"

Set::Set(const std::string textureAdress, sf::Vector2f position)
	:_position(position)
{
	addTexture(textureAdress);
}

Set::Set(const std::map<std::string,BetterTexture>& textures,sf::Vector2f position)
		:_position(position), Asset(textures)
{

}

void Set::addBlock(const std::string textureAdress,sf::Vector2f position){
	addTexture(textureAdress);
	Blocks[position] = std::make_unique<Block>((Asset.find(textureAdress))->getFckadress(), position);
}

void Set::deleteBlock(sf::Vector2f position)
{
	Blocks.erase(position);
}

void Set::addTexture(const std::string textureAdress) {
	if(Asset.find(textureAdress)==Asset.end())
		Asset.emplace(textureAdress,BetterTexture(textureAdress));
}

void Set::draw(sf::RenderWindow& handle)const {
	for (const auto& el : Blocks)
		handle.draw(*el.second);
}

void Set::printfTextureList() {
	for (auto& el : Blokcs)
		std::cout << "niebieski" << el.second->getAdress() << "reset" << std::endl;
}

void Set::setPosition(sf::Vector2f position) {
	for (auto& el : Blocks)
		el.second->setPosition(el.second->getPosition() - _position);

	_position = position;
	
	for (auto& el : Blocks)
		el.second->setPosition(el.second->getPosition() + _position);
}

sf::Vector2f Set::getPosition() const {
	return _position;
}
