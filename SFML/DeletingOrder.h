#pragma once
#include <SFML/Graphics.hpp>

//klasa dla menu, kanapek, shake itp oraz kreatorow
#define MAX_NUMBER_OF_ITEMS 9

using namespace std;
using namespace sf;


class DeletingOrder
{
public:

private:

	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
public:

	DeletingOrder(float width, float height);
	~DeletingOrder();


	void draw(RenderWindow& window);
	void nazwa(string nazwa, int k);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};





