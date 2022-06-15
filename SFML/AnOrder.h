#pragma once
#include <iostream>
#include <string>

using namespace std;
 
class Order
{
public:
	int productNumber;
	string orderTab[8];
	int showOrderCounter;
	string showOrderText;
	string sandwichTab[4];
	int sandwichCreatorCounter;
	string mealTab[3];
	int mealCreatorCounter;
	void showOrder();
	string productName;
	void addToOrder(string text);
	string ingredientName;
	void addToSandwich(string text);
	string partOfMealName;
	void addToMeal(string text);
	int isSandwich;
	int isMeal;

	Order();
	~Order();
};
