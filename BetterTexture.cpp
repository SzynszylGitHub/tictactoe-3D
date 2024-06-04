#include "BetterTexture.h"

BetterTexture::BetterTexture(std::string adres) 
	: _adres(adres)
{
		if(!loadFromFile(_adres))
			printf("\n");
}

BetterTexture::BetterTexture(const BetterTexture& other) 
	:BetterTexture(other._adres)
{}

void BetterTexture::setAdres(std::string adres) {
	_adres = adres;
	loadFromFile(_adres);
}

std::string BetterTexture::getAdres() const{
	return _adres;
}

const sf::Texture& BetterTexture::getFckAdres() const{
	
	return *this;
}

//bool BetterTexture::operator<(BetterTexture bt1) const {
//	return getAdress() < bt1.getAdress();
//}

bool operator<(const BetterTexture bt1,const BetterTexture bt2) {
	return bt1.getAdres() < bt2.getAdres();
}

bool operator>(const BetterTexture bt1, const BetterTexture bt2) {
	return bt1.getAdres() > bt2.getAdres();
}

bool operator==(const BetterTexture bt1,const BetterTexture bt2) {
	return bt1.getAdres() == bt2.getAdres();
}

bool operator==(const BetterTexture bt1, const std::string st) {
	return bt1.getAdres() == st;
}

bool operator==(const std::string st, const BetterTexture bt2) {
	return st == bt2.getAdres();
}