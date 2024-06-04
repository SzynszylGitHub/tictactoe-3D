#pragma once
#include <SFML/Graphics.hpp>

class BetterTexture: public sf::Texture
{
public:
	BetterTexture(std::string adres = "");
	BetterTexture(const BetterTexture& other);
	BetterTexture(const BetterTexture&& other) = delete;

	void setAdres(std::string);
	
	std::string getAdres() const;
	const sf::Texture& getFckAdres() const;
	

	//bool operator<(const BetterTexture) const;
	BetterTexture& operator=(const BetterTexture&) = delete;

	friend bool operator<(const BetterTexture&,const BetterTexture&);
	friend bool operator>(const BetterTexture&,const BetterTexture&);
	friend bool operator==(const BetterTexture&,const BetterTexture&);
	friend bool operator==(const BetterTexture&, const std::string&);
	friend bool operator==(const std::string&,const BetterTexture&);
private:
	std::string _adres;
};

