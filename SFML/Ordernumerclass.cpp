#include "Ordernumerclass.h"

Ordernumerclass::Ordernumerclass(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	enter[0].setFont(font);
	enter[0].setFillColor(Color::Black);
	enter[0].setString("EXIT");
	enter[0].setPosition(505.f, 752.f);

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