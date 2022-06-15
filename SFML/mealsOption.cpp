#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include "sandwichOption.h"
#include "shakesOption.h"
#include "Menu.h"
#include "Enter.h"
#include "Ordernumerclass.h"
#include "DeletingOrder.h"
#include "Bill.h"
#include "sidesOption.h"
#include "mealsOption.h"

void mealsOption(Order &anOrder)
{
    RenderWindow windowMeals(VideoMode(600, 800), "Meals");// -||- dla MEals
    Menu menuMeals(windowMeals.getSize().x, windowMeals.getSize().y);//obiekt dla Meals
    menuMeals.nazwa("Beef+Chips+Blueberry", 0);//przypisanie nazw dla menu Meals
    menuMeals.nazwa("Ham+Chips+Strawberry", 1);
    menuMeals.nazwa("Tuna+Salad+Chocolate", 2);
    menuMeals.nazwa("Student Meal", 3);
    menuMeals.nazwa("Create your meal", 4);
    menuMeals.nazwa("Exit", 5);
    RectangleShape backMeals;//tlo dla Meals
    backMeals.setSize(Vector2f(600, 800));
    Texture imageBackMeals;
    imageBackMeals.loadFromFile("baza.png");
    backMeals.setTexture(&imageBackMeals);

    while (windowMeals.isOpen())
    {
        Event mealsEvent;
        while (windowMeals.pollEvent(mealsEvent))
        {
            if (mealsEvent.type == Event::Closed)
            {
                windowMeals.close();
            }
            if (mealsEvent.type == Event::KeyReleased)
            {
                if (mealsEvent.key.code == Keyboard::Up)
                {
                    menuMeals.MoveUp();
                    break;
                }
                if (mealsEvent.key.code == Keyboard::Down)
                {
                    menuMeals.MoveDown();
                    break;

                }
                if (mealsEvent.key.code == Keyboard::Return)
                {


                    int x = menuMeals.GetPressedItem();

                    //opcje dla zestawow
                    if (x == 0)
                    {
                        anOrder.productName = "Beef+Chips+Blueberry";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Ham+Chips+Strawberry";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Tuna+Salad+Chocolate";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "Student Meal";
                        anOrder.addToOrder(anOrder.productName);
                    }

                    if (x == 4)
                    {

                        RenderWindow windowCreatorMeals(VideoMode(600, 800), "MealCreator");//okno dla kreatora Meals
                        Menu menuCreatorMeals(windowCreatorMeals.getSize().x, windowCreatorMeals.getSize().y);//obiekt menau dla kreatora melas
                        menuCreatorMeals.nazwa("Beef burger", 0);
                        menuCreatorMeals.nazwa("Ham&cheese sandwich", 1);
                        menuCreatorMeals.nazwa("Chips", 2);
                        menuCreatorMeals.nazwa("Salad", 3);
                        menuCreatorMeals.nazwa("Garlic dip", 4);
                        menuCreatorMeals.nazwa("Exit", 5);
                        RectangleShape backCreatorMeals;//t³o dla kreatora kanapki
                        backCreatorMeals.setSize(Vector2f(600, 800));
                        Texture imageBackCreatorMeals;
                        imageBackCreatorMeals.loadFromFile("mealcreator.png");
                        backCreatorMeals.setTexture(&imageBackCreatorMeals);
                        while (windowCreatorMeals.isOpen())
                        {
                            Event creatorMealsEvent;
                            while (windowCreatorMeals.pollEvent(creatorMealsEvent))
                            {
                                if (creatorMealsEvent.type == Event::Closed)
                                {
                                    windowCreatorMeals.close();
                                }
                                if (creatorMealsEvent.type == Event::KeyPressed)
                                {
                                    if (creatorMealsEvent.key.code == Keyboard::Escape)
                                    {
                                        windowCreatorMeals.close();
                                    }
                                }
                                if (creatorMealsEvent.type == Event::KeyReleased)
                                {
                                    if (creatorMealsEvent.key.code == Keyboard::Up)
                                    {
                                        menuCreatorMeals.MoveUp();
                                        break;
                                    }
                                    if (creatorMealsEvent.key.code == Keyboard::Down)
                                    {
                                        menuCreatorMeals.MoveDown();
                                        break;
                                    }
                                    int x = menuCreatorMeals.GetPressedItem();
                                    if (creatorMealsEvent.key.code == Keyboard::Return)
                                    {
                                        //opcje dla kreatora zestawow
                                        if (x == 0)
                                        {
                                            anOrder.partOfMealName = "Beef burger";
                                            anOrder.addToMeal(anOrder.partOfMealName);
                                        }
                                        if (x == 1)
                                        {
                                            anOrder.partOfMealName = "Ham&cheese sandwich";
                                            anOrder.addToMeal(anOrder.partOfMealName);
                                        }
                                        if (x == 2)
                                        {
                                            anOrder.partOfMealName = "Chips";
                                            anOrder.addToMeal(anOrder.partOfMealName);
                                        }
                                        if (x == 3)
                                        {
                                            anOrder.partOfMealName = "Salad";
                                            anOrder.addToMeal(anOrder.partOfMealName);
                                        }
                                        if (x == 4)
                                        {
                                            anOrder.partOfMealName = "Garlic dip";
                                            anOrder.addToMeal(anOrder.partOfMealName);
                                        }
                                        if (x == 5)
                                        {
                                            windowCreatorMeals.close();
                                            break;
                                        }
                                    }
                                }
                            }
                            windowCreatorMeals.clear();
                            windowCreatorMeals.draw(backCreatorMeals);
                            menuCreatorMeals.draw(windowCreatorMeals);
                            windowCreatorMeals.display();
                        }
                    }
                    if (x == 5)//zamkniecie okna meals
                    {
                        windowMeals.close();
                        break;
                    }
                }
            }
        }
        windowMeals.clear();
        windowMeals.draw(backMeals);
        menuMeals.draw(windowMeals);
        windowMeals.display();
    }
}

