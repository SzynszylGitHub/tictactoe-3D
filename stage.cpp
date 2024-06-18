#include "stage.h"

Stage::Stage()
	:_position(sf::Vector2f(0,0))
{}

Stage::Stage(sf::Vector2f position)
	: _position(position)
{}

Stage::Stage(const std::map<std::string, BetterTexture>& Assets, const sf::Vector2f position)
	: Assets(Assets) , _position(position)
{}

Stage::Stage(const Stage& other) 
	: _position(other._position), Assets(other.Assets)
{
	for (const auto& el : other.Blocks)
		addBlock(el.second->getAdres(), el.second->getPositionCartesianSystem(),el.second->getType());
}


void Stage::addBlock(const std::string textureAdres,const sf::Vector3f position, const Type type){
	addTexture(textureAdres);
	Blocks[position] = std::make_unique<Block>(Assets[textureAdres], position, type);
	Blocks[position]->setPosition(Blocks[position]->getPosition() + _position);
	NumOfBlocks++;
}

void Stage::deleteBlock(sf::Vector3f position)
{
	Blocks.erase(position);
}

void Stage::listTexture() const {
	for (auto& el : Assets) {
		printf(el.second.getAdres().c_str());
		printf("\n");
	}
}

void Stage::setTexture(const std::string textureAdres, const sf::Vector3f position) {
	addTexture(textureAdres);
	Blocks[position]->setTexture(Assets[textureAdres]);
}

void Stage::addTexture(const std::string textureAdres) {
	if (Assets.find(textureAdres) == Assets.end()) 
		Assets.emplace(textureAdres, BetterTexture(textureAdres));
	
}

void Stage::draw(sf::RenderWindow& handle) {

	for (const auto& el : Blocks) {
		el.second->draw(handle);
	}
}

sf::Vector2f Stage::getPosition() const {
	return _position;
}

sf::Vector2f Stage::getSizeOfBlock() const{
	auto size = Assets.begin()->second.getSize();
	return sf::Vector2f(size.x,size.y);
}

int Stage::getNumOfBlocks() const{
	return NumOfBlocks;
}