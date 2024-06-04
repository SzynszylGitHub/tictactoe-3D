#include "BetterTexture.h"

BetterTexture::BetterTexture(std::string adress) 
	: _adress(adress)
{
		if(!loadFromFile(_adress))
			printf("\n");
}

void BetterTexture::setAdress(std::string adress) {
	_adress = adress;
	loadFromFile(_adress);
}

std::string BetterTexture::getAdress() const{
	return _adress;
}

const sf::Texture& BetterTexture::getFckadress() const{
	
	return *this;
}

//bool BetterTexture::operator<(BetterTexture bt1) const {
//	return getAdress() < bt1.getAdress();
//}

bool operator<(const BetterTexture bt1,const BetterTexture bt2) {
	return bt1.getAdress() < bt2.getAdress();
}

bool operator>(const BetterTexture bt1, const BetterTexture bt2) {
	return bt1.getAdress() > bt2.getAdress();
}

bool operator==(const BetterTexture bt1,const BetterTexture bt2) {
	return bt1.getAdress() == bt2.getAdress();
}

bool operator==(const BetterTexture bt1, const std::string st) {
	return bt1.getAdress() == st;
}

bool operator==(const std::string st, const BetterTexture bt2) {
	return st == bt2.getAdress();
}