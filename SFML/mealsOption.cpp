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
    Font font;
    font.loadFromFile("BAUHS93.ttf");

    Text noteMeals(" Note: Press ENTER to add a product to the order.", font, 18);
    noteMeals.setFillColor(Color::Black);
    noteMeals.setPosition(57.f, 730.f);

    RenderWindow windowMeals(VideoMode(600, 800), "Meals");// -||- dla MEals
    Menu menuMeals(windowMeals.getSize().x, windowMeals.getSize().y);//obiekt dla Meals
    menuMeals.name("Beef+Chips+Bberry", 0);//przypisanie nazw dla menu Meals
    menuMeals.name("Ham+Chips+Sberry", 1);
    menuMeals.name("Tuna+Salad+Choco", 2);
    menuMeals.name("Student Meal", 3);
    menuMeals.name("Create your meal", 4);
    menuMeals.name("EXIT", 5);
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
                        anOrder.productName = "Beef+Chips+Bberry";
                        anOrder.addToOrder(anOrder.productName,10);
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Ham+Chips+Sberry";
                        anOrder.addToOrder(anOrder.productName,10);
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Tuna+Salad+Choco";
                        anOrder.addToOrder(anOrder.productName,10);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "Student Meal";
                        anOrder.addToOrder(anOrder.productName,5);
                    }

                    if (x == 4)
                    {

                        RenderWindow windowCreatorMeals(VideoMode(600, 800), "MealCreator");//okno dla kreatora Meals
                        Menu menuCreatorMeals(windowCreatorMeals.getSize().x, windowCreatorMeals.getSize().y);//obiekt menau dla kreatora melas
                        menuCreatorMeals.name("Beef burger", 0);
                        menuCreatorMeals.name("Ham&cheese", 1);
                        menuCreatorMeals.name("Chips", 2);
                        menuCreatorMeals.name("Salad", 3);
                        menuCreatorMeals.name("Garlic dip", 4);
                        menuCreatorMeals.name("EXIT", 5);
                        RectangleShape backCreatorMeals;//t³o dla kreatora kanapki
                        backCreatorMeals.setSize(Vector2f(600, 800));
                        Texture imageBackCreatorMeals;
                        imageBackCreatorMeals.loadFromFile("mealcreator.png");
                        backCreatorMeals.setTexture(&imageBackCreatorMeals);

       

                        Text warninngCreatorMeals1(" Note: The maximum number of products in a meal is 3, products", font, 14);
                        warninngCreatorMeals1.setFillColor(Color::Black);
                        warninngCreatorMeals1.setPosition(63.f, 650.f);
                        Text warninngCreatorMeals2(" above this quantity are not added to the meal.", font, 14);
                        warninngCreatorMeals2.setFillColor(Color::Black);
                        warninngCreatorMeals2.setPosition(63.f, 664.f);

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
                                            anOrder.partOfMealName = "Ham&cheese";
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
                                            anOrder.addMeal();
                                            windowCreatorMeals.close();
                                            break;
                                        }
                                    }
                                }
                            }
                            windowCreatorMeals.clear();
                            windowCreatorMeals.draw(backCreatorMeals);
                            menuCreatorMeals.draw(windowCreatorMeals);
                            windowCreatorMeals.draw(warninngCreatorMeals1);
                            windowCreatorMeals.draw(warninngCreatorMeals2);
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
        windowMeals.draw(noteMeals);
        windowMeals.display();
    }
}

