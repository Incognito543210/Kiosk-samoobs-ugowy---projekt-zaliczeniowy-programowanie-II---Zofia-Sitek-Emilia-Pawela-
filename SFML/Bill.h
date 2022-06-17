#pragma once
#include <SFML/Graphics.hpp>
#include "AnOrder.h"

//klasa dla menu przy wybraniu opcji bill

using namespace std;
using namespace sf;

class classBill
{
private:
	int selectedItemIndex;
	Font font;
	Text enter[12];
public:
	string orderSum;
	classBill(float width, float height, Order &anOrder);
	~classBill();
	void MoveLeft();
	void MoveRight();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};