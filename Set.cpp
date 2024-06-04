#include "Set.h"

Set::Set() 
	:_position(sf::Vector2f(0,0))
{}

Set::Set(const std::string& textureAdres, sf::Vector2f position)
	: _position(position) {
	
	addTexture(textureAdres);
}

Set::Set(const std::map<std::string, BetterTexture>& textures, sf::Vector2f position)
	: _position(position), Asset(textures) {}

Set::Set(const Set& other) 
	:_position(other._position), Asset(other.Asset)
{
	for (const auto& el : other.Blocks)
		addBlock(el.second->getAdres(), el.second->getPositionCartesianSystem());
}


void Set::addBlock(const std::string textureAdres,sf::Vector2f position){
	
	addTexture(textureAdres);
	Blocks[position] = std::make_unique<Block>(Asset[textureAdres], position);
	Blocks[position]->setScale(_scale);
	Blocks[position]->setPosition(Blocks[position]->translateToIsometricGridScaled(Blocks[position]->getPositionCartesianSystem(),_scale));
	NumOfBlocks++;
}

void Set::deleteBlock(sf::Vector2f position)
{
	Blocks.erase(position);
}


void Set::listTexture() {
	for (auto& el : Asset)
		std::cout << "\033[34m" << el.second.getAdres() << "\033[0m" << "\n";
}

void Set::Scale(sf::Vector2f Scale) {
	_scale = Scale;
	for (auto& el : Blocks) {
		el.second->setScale(_scale);
		el.second->setPosition(el.second->translateToIsometricGridScaled(el.second->getPositionCartesianSystem(),_scale));
	}
}

void Set::addTexture(const std::string textureAdres) {
	if (Asset.find(textureAdres) == Asset.end()) 
		Asset.emplace(textureAdres, BetterTexture(textureAdres));
	
}

void Set::draw(sf::RenderWindow& window) const {
	
	for (const auto& el : Blocks) {
		window.draw(*el.second);
	}
}


sf::Vector2f Set::getSizeOfBlock() {
	auto size = Asset.begin()->second.getSize();
	return sf::Vector2f(size.x*_scale.x,size.y*_scale.y);
}

int Set::getNumOfBlocks(){
	return NumOfBlocks;

void Set::setPosition(sf::Vector2f position) {
	
	_position = position;

	for (auto& el : Blocks) {
		el.second->setPosition(el.second->translateToIsometricGrid(el.second->getPositionCartesianSystem()) + _position);
	}

}

sf::Vector2f Set::getPosition() const {
	return _position;
}
