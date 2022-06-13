#include "Enter.h"

//klasa dla menu dla okna startu

Enter::Enter(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}


	enter[0].setFont(font);
	enter[0].setFillColor(Color::Red);
	enter[0].setString("ENTER");
	enter[0].setPosition(260.f, 572.f);

	enter[1].setFont(font);
	enter[1].setFillColor(Color::Black);
	enter[1].setString("EXIT");
	enter[1].setPosition(526.f, 763.f);

	selectedItemIndex = 0;
}



Enter::~Enter()
{};

void Enter::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(enter[i]);

	}
}
void Enter::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		enter[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex--;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Enter::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		enter[selectedItemIndex].setFillColor(Color::Black);
		selectedItemIndex++;
		enter[selectedItemIndex].setFillColor(Color::Red);
	}
}
