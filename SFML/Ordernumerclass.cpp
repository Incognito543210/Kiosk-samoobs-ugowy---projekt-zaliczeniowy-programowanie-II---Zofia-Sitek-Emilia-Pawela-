#include "Ordernumerclass.h"
//klasa dla menu przy numerze zamowienia
Ordernumerclass::Ordernumerclass(float width, float height)
{
	if (!font.loadFromFile("BAUHS93.ttf"))
	{
		//handle error
	}
	enter[0].setFont(font);
	enter[0].setFillColor(Color::Black);
	enter[0].setString("EXIT");
	enter[0].setPosition(525.f, 761.f);

	orderNumber = rand()%50 + 10;

	enter[1].setFont(font);
	enter[1].setCharacterSize(100);
	enter[1].setFillColor(Color::Black);
	enter[1].setString(to_string(orderNumber));
	enter[1].setPosition(235.f, 230.f);

	selectedItemIndex = 0;
}
Ordernumerclass::~Ordernumerclass()
{};

void Ordernumerclass::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(enter[i]);
	}
}