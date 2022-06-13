#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 6
using namespace std;
using namespace sf;

class Rachunek
{
private:
	int selectedItemIndex;
	Font font;
	Text enter[MAX_NUMBER_OF_ITEMS];
public:

	Rachunek(float width, float height);
	~Rachunek();
	void MoveLeft();
	void MoveRight();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};