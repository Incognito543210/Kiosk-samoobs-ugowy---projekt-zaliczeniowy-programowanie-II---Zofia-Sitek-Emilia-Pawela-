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
	sandwichIngredients = "";
	mealIngredients = "";
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
	if (sandwichCreatorCounter <= 3)
	{
		sandwichTab[sandwichCreatorCounter] = text;
		sandwichCreatorCounter++;
		cout << sandwichCreatorCounter << " " << text << endl;
	}
}

void Order::addSandwich()
{
	if (sandwichCreatorCounter > 0)
	{
		for (int i = 0; i <= 3; i++)
		{
			sandwichIngredients += sandwichTab[i] + " ";
		}
		addToOrder("Sandwich " + sandwichIngredients);
		//czyszczenie element�w kanapki
		sandwichCreatorCounter = 0;
		sandwichIngredients = "";
		for (int i = 0; i <= 3; i++)
		{
			sandwichTab[i] = "";
		}
	}	
}

void Order::addToMeal(string text)
{
	if (mealCreatorCounter <= 2)
	{
		mealTab[mealCreatorCounter] = text;
		mealCreatorCounter++;
		cout << mealCreatorCounter << " " << text << endl;
	}
}

void Order::addMeal()
{
	if (mealCreatorCounter > 0)
	{
		for (int i = 0; i <= 2; i++)
		{
			mealIngredients += mealTab[i] + " ";
		}
		addToOrder("Meal " + mealIngredients);
		//czyszczenie elementow posilku
		mealCreatorCounter = 0;
		mealIngredients = "";
		for (int i = 0; i <= 2; i++)
		{
			mealTab[i] = "";
		}
	}
}

Order::~Order()
{

}

