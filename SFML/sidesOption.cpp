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


void sidesOption(Order &anOrder)
{

    RenderWindow windowSides(VideoMode(600, 800), "Sides");// -||- dla Sides
    Menu menuSides(windowSides.getSize().x, windowSides.getSize().y);//obiekt dla sides
    menuSides.name("Chips", 0);//przypisanie nazw dla menu sides
    menuSides.name("Salad", 1);
    menuSides.name("Ketchup", 2);
    menuSides.name("KentuckyGold dip", 3);
    menuSides.name("Garlic dip", 4);
    menuSides.name("EXIT", 5);
    RectangleShape backSides;//tlo dla sides
    backSides.setSize(Vector2f(600, 800));
    Texture imageBackSides;
    imageBackSides.loadFromFile("dodatki.png");
    backSides.setTexture(&imageBackSides);



    while (windowSides.isOpen())
    {
        Event sidesEvent;

        while (windowSides.pollEvent(sidesEvent))
        {
            if (sidesEvent.type == Event::Closed)
            {
                windowSides.close();
            }
            if (sidesEvent.type == Event::KeyPressed)
            {
                if (sidesEvent.key.code == Keyboard::Escape)
                {
                    windowSides.close();
                }
            }

            if (sidesEvent.type == Event::KeyReleased)
            {
                if (sidesEvent.key.code == Keyboard::Up)
                {
                    menuSides.MoveUp();
                    break;
                }
                if (sidesEvent.key.code == Keyboard::Down)
                {
                    menuSides.MoveDown();
                    break;

                }

                if (sidesEvent.key.code == Keyboard::Return)
                {
                    //opcje dla dodatkow
                    int x = menuSides.GetPressedItem();
                    if (x == 0)
                    {
                        anOrder.productName = "Chips";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Salad";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Ketchup";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "KentuckyGold dip";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 4)
                    {
                        anOrder.productName = "Garlic dip";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 5)
                    {
                        windowSides.close();
                        break;
                    }
                }

            }


        }


        windowSides.clear();
        windowSides.draw(backSides);
        menuSides.draw(windowSides);
        windowSides.display();


    }
}