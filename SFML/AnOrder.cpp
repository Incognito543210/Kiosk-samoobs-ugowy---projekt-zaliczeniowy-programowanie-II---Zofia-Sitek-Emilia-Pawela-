#include "AnOrder.h"
#include <iostream>

using namespace std;

Order::Order()
{
	sum = 0;
	productNumber = 0;
	showOrderCounter = 0;
	string showOrderText = "";
	for (int i = 0; i <= 7; i++)
	{
		orderTab[i] = "";
		orderPrices[i] = 0;
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

void Order::addToOrder(string text, int price)
{
	if (productNumber <= 7)
	{
		orderTab[productNumber] = to_string(productNumber+1)+") "+text;
		orderPrices[productNumber] = price;
		productNumber++;
		cout << productNumber << " " << text << endl;
		sum += price;
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
		addToOrder("Sandwich: " + sandwichIngredients +"5$", 5);
		//czyszczenie elementów kanapki
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
		addToOrder("Meal: " + mealIngredients +" 12$", 12);
		//czyszczenie elementow posilku
		mealCreatorCounter = 0;
		mealIngredients = "";
		for (int i = 0; i <= 2; i++)
		{
			mealTab[i] = "";
		}
	}
}

void Order::removeFromOrder(int numberOfProduct)
{
	if (orderTab[numberOfProduct] != "") productNumber--;
	orderTab[numberOfProduct] = "";
	sum -= orderPrices[numberOfProduct];
	orderPrices[numberOfProduct] = 0;
}

void Order::upgradeOrder()
{
	//tabela produktów
	for (int i = 0; i <= 6; i++)
	{
		if (orderTab[i] == "")
		{
			for (int j = i+1; j <= 7; j++)
			{
				if (orderTab[j] != "")
				{
					orderTab[i] = orderTab[j];
					orderTab[i].replace(0, 1, to_string(i + 1));
					orderTab[j] = "";
					break;
				}
			}
		}
	}
	//tabela cen
	for (int i = 0; i <= 6; i++)
	{
		if (orderPrices[i] == 0)
		{
			for (int j = i + 1; j <= 7; j++)
			{
				if (orderPrices[j] != 0)
				{
					orderPrices[i] = orderPrices[j];
					orderPrices[j] = 0;
					break;
				}
			}
		}
	}
}

Order::~Order()
{

}

