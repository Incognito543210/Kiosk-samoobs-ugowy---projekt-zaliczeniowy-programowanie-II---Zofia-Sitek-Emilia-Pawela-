#include "DeletingOrder.h"

//klasa dla menu, kanapek, shake itp oraz kreatorow

DeletingOrder::DeletingOrder(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Product number: 1");
	menu[0].setPosition(64.f, 190.f);

	menu[1].setFont(font);
	menu[1].setFillColor(Color::Black);
	menu[1].setString("Product number: 2");
	menu[1].setPosition(64.f, 240.f);

	menu[2].setFont(font);
	menu[2].setFillColor(Color::Black);
	menu[2].setString("Product number: 3");
	menu[2].setPosition(64.f, 290.f);

	menu[3].setFont(font);
	menu[3].setFillColor(Color::Black);
	menu[3].setString("Product number: 4");
	menu[3].setPosition(64.f, 340.f);

	menu[4].setFont(font);
	menu[4].setFillColor(Color::Black);
	menu[4].setString("Product number: 5");
	menu[4].setPosition(64.f, 390.f);

	menu[5].setFont(font);
	menu[5].setFillColor(Color::Black);
	menu[5].setString("Product number: 6");
	menu[5].setPosition(64.f, 440.f);

	menu[6].setFont(font);
	menu[6].setFillColor(Color::Black);
	menu[6].setString("Product number: 7");
	menu[6].setPosition(64.f, 490.f);

	menu[7].setFont(font);
	menu[7].setFillColor(Color::Black);
	menu[7].setString("Product number: 8");
	menu[7].setPosition(64.f, 540.f);

	menu[8].setFont(font);
	menu[8].setFillColor(Color::Black);
	menu[8].setString("EXIT");
	menu[8].setPosition(526.f, 763.f);





	selectedItemIndex = 0;
}

DeletingOrder::~DeletingOrder()
{};

void DeletingOrder::nazwa(string naz, int k)
{
	menu[k].setString(naz);

}

void DeletingOrder::draw(RenderWindow& window)
{

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);

	}


}


void DeletingOrder::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);

	}


}

void DeletingOrder::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);

	}


}














