#pragma once
#include <SFML/Graphics.hpp>


//klasa dla menu, kanapek, shake itp oraz kreatorow
#define MAX_NUMBER_OF_ITEMS 6

using namespace std;
using namespace sf;


class Menu
{public:

private:

	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
public:

	Menu(float width, float height);
	~Menu();


	void draw(RenderWindow& window);
	void name(string nazwa, int k);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};










