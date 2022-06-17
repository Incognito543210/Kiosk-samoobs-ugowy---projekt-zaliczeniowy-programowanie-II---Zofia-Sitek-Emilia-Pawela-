#pragma once
#include <iostream>
#include <string>

using namespace std;
 
class Order
{
public:
	int sum;
	int productNumber;
	string orderTab[8];
	int orderPrices[8];
	int showOrderCounter;
	string showOrderText;
	string sandwichTab[4];
	int sandwichCreatorCounter;
	string mealTab[3];
	int mealCreatorCounter;
	string productName;
	void addToOrder(string text, int price);
	string ingredientName;
	string sandwichIngredients;
	void addToSandwich(string text);
	void addSandwich();
	string partOfMealName;
	string mealIngredients;
	void addToMeal(string text);
	void addMeal();
	void removeFromOrder(int numberOfProduct);
	void upgradeOrder();

	Order();
	~Order();
};
