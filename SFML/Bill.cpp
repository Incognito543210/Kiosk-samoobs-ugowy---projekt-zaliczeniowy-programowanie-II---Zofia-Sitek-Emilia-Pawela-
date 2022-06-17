#include "Bill.h"
//klasa dla menu przy wybraniu opcji bill
classBill::classBill(float width, float height, Order &anOrder)
{
	if (!font.loadFromFile("BAUHS93.ttf"))
	{
		//handle error
	}

	enter[0].setFont(font);
	enter[0].setFillColor(Color::Red);
	enter[0].setString("PAY");
	enter[0].setPosition(375.f, 761.f);

	enter[1].setFont(font);
	enter[1].setFillColor(Color::Black);
	enter[1].setString("REMOVE");
	enter[1].setCharacterSize(20);
	enter[1].setPosition(443.f, 767.f);

	enter[2].setFont(font);
	enter[2].setFillColor(Color::Black);
	enter[2].setString("EXIT");
	enter[2].setPosition(525.f, 761.f);

	for (int i = 3; i < 11; i++)
	{
		enter[i].setCharacterSize(20);
		enter[i].setFont(font);
		enter[i].setFillColor(Color::Black);
		enter[i].setString(anOrder.orderTab[i-3]);
		enter[i].setPosition(40.f, 200.f+(i-3)*50.f);
	}

	enter[11].setFont(font);
	enter[11].setFillColor(Color::Black);
	enter[11].setString("Total: "+to_string(anOrder.sum));
	enter[11].setPosition(350.f, 700.f);

	selectedItemIndex = 0;
}

classBill::~classBill()
{};

void classBill::draw(RenderWindow& window)
{
	for (int i = 0; i < 12; i++)
	{
		window.draw(enter[i]);
	}
}
void classBill::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		enter[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
void classBill::MoveRight()
{
	if (selectedItemIndex + 1 < 3)
	{
		enter[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
