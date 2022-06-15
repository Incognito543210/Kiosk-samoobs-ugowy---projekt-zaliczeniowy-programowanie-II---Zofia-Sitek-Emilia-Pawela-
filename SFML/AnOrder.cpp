#include "AnOrder.h"
#include <iostream>

using namespace std;

Order::Order()
{
	productNumber = 0;
	showOrderCounter = 0;
	string showOrderText = "";
	for (int i = 0; i <= 7; i++)
	{
		orderTab[i] = "";
	}
	for (int i = 0; i <= 3; i++)
	{
		sandwichTab[i] = "";
	}
	sandwichCreatorCounter = 0;
	for (int i = 0; i <= 2; i++)
	{
		mealTab[i] = "";
	}
	mealCreatorCounter = 0;
	productName = "";
	ingredientName = "";
	partOfMealName = "";
	isSandwich = 0;
	isMeal = 0;
}

void Order::showOrder()
{

}

void Order::addToOrder(string text)
{
	if (productNumber <= 7)
	{
		orderTab[productNumber] = text;
		productNumber++;
		cout << productNumber << " " << text << endl;
	}
}

void Order::addToSandwich(string text)
{
	if (isSandwich == 1)
	{
		addToOrder("Sandwich");
	}
	if (sandwichCreatorCounter <= 3)
	{
		sandwichTab[sandwichCreatorCounter] = text;
		sandwichCreatorCounter++;
		cout << sandwichCreatorCounter << " " << text << endl;
	}
}

void Order::addToMeal(string text)
{
	addToOrder("Meal");
	if (mealCreatorCounter <= 2)
	{
		mealTab[mealCreatorCounter] = text;
		mealCreatorCounter++;
		cout << mealCreatorCounter << " " << text << endl;
	}
}

Order::~Order()
{

}

