#pragma once
#include <SFML/Graphics.hpp>

class BetterTexture: public sf::Texture
{
public:
	BetterTexture(std::string adress = "");
	void setAdress(std::string);
	std::string getAdress() const;
	const sf::Texture& getFckadress() const;
	//bool operator<(const BetterTexture) const;
	friend bool operator<(const BetterTexture,const BetterTexture);
	friend bool operator>(const BetterTexture,const BetterTexture);
	friend bool operator==(const BetterTexture,const BetterTexture);
	friend bool operator==(const BetterTexture, const std::string);
	friend bool operator==(const std::string,const BetterTexture);
private:
	std::string _adress;
};

