#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 2
using namespace std;
using namespace sf;

class ExitSure
{
private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
public:

	ExitSure(float width, float height);
	~ExitSure();
	void MoveLeft();
	void MoveRight();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};

