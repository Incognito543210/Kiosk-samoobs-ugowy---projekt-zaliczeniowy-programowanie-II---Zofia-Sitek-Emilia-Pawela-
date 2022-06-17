#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 6
using namespace std;
using namespace sf;
//klasa dla menu przy numerze zamowienia
class Ordernumerclass
{
private:
	int selectedItemIndex;
	int orderNumber;
	Font font;
	Text enter[MAX_NUMBER_OF_ITEMS];
public:

	Ordernumerclass(float width, float height);
	~Ordernumerclass();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};