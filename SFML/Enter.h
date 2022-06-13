#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 6
using namespace std;
using namespace sf;

class Enter
{
private:
	int selectedItemIndex;
	Font font;
	Text enter[MAX_NUMBER_OF_ITEMS];
public:

	Enter(float width, float height);
	~Enter();
	void MoveUp();
	void MoveDown();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

};

