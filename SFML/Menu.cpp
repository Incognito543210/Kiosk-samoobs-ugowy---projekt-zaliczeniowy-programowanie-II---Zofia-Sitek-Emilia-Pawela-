#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setPosition(64.f,245.f);

	menu[1].setFont(font);
	menu[1].setFillColor(Color::Black);
	menu[1].setPosition(64.f, 340.f);

	menu[2].setFont(font);
	menu[2].setFillColor(Color::Black);
	menu[2].setPosition(64.f, 423.f);

	menu[3].setFont(font);
	menu[3].setFillColor(Color::Black);
	menu[3].setPosition(64.f, 510.f);

	menu[4].setFont(font);
	menu[4].setFillColor(Color::Black);
	menu[4].setPosition(64.f, 595.f);

	menu[5].setFont(font);
	menu[5].setFillColor(Color::Black);
	menu[5].setPosition(530.f,762.f);



	selectedItemIndex = 0;
}

Menu::~Menu()
{};

void Menu::nazwa(string naz, int k)
{
	menu[k].setString(naz);

}

void Menu::draw(RenderWindow& window)
{

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);

	}


}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);

	}


}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);

	}


}














