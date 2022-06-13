#pragma once
#include <SFML/Graphics.hpp>

//klasa dla menu przy wybraniu opcji bill

#define MAX_NUMBER_OF_ITEMS 6
using namespace std;
using namespace sf;

class classBill
{
private:
	int selectedItemIndex;
	Font font;
	Text enter[MAX_NUMBER_OF_ITEMS];
public:

	classBill(float width, float height);
	~classBill();
	void MoveLeft();
	void MoveRight();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};