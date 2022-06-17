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
	string sandwichIngredients;
	void addToSandwich(string text);
	void addSandwich();
	string partOfMealName;
	string mealIngredients;
	void addToMeal(string text);
	void addMeal();

	Order();
	~Order();
};
