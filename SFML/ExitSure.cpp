#include "ExitSure.h"

ExitSure::ExitSure(float width, float height)
{
	if (!font.loadFromFile("BAUHS93.ttf"))
	{
		//handle error
	}


	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Yes");
	menu[0].setScale(2.f, 2.f);
	menu[0].setPosition(180.f, 300.f);

	menu[1].setFont(font);
	menu[1].setFillColor(Color::Black);
	menu[1].setScale(2.f, 2.f);
	menu[1].setString("No");
	menu[1].setPosition(340.f, 300.f);


	selectedItemIndex = 0;
}



ExitSure::~ExitSure()
{};

void ExitSure::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(menu[i]);

	}
}
void ExitSure::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
void ExitSure::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
