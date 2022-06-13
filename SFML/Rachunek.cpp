#include "Rachunek.h"

Rachunek::Rachunek(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}


	enter[0].setFont(font);
	enter[0].setFillColor(Color::Red);
	enter[0].setString("Pay");
	enter[0].setPosition(340.f, 750.f);

	enter[1].setFont(font);
	enter[1].setFillColor(Color::Black);
	enter[1].setString("EXIT");
	enter[1].setPosition(500.f, 750.f);

	selectedItemIndex = 0;
}



Rachunek::~Rachunek()
{};

void Rachunek::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(enter[i]);

	}
}
void Rachunek::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		enter[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Rachunek::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		enter[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
