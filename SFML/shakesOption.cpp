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


using namespace sf;
using namespace std;

void shakeOption(Order& anOrder)
{
    RenderWindow windowShakes(VideoMode(600, 800), "Shakes");// -||- dla shakes
    Menu menuShakes(windowShakes.getSize().x, windowShakes.getSize().y);//obiekt dla shakes
    menuShakes.nazwa("Strawberry", 0);//przypisanie nazw dla menu shakes
    menuShakes.nazwa("Vanilla", 1);
    menuShakes.nazwa("Chocolate", 2);
    menuShakes.nazwa("Caramel", 3);
    menuShakes.nazwa("Blueberry", 4);
    menuShakes.nazwa("Exit", 5);
    RectangleShape backShakes;//tlo dla shakes
    backShakes.setSize(Vector2f(600, 800));
    Texture imageBackShakes;
    imageBackShakes.loadFromFile("shakes.png");
    backShakes.setTexture(&imageBackShakes);

    while (windowShakes.isOpen())
    {
        Event shakesEvent;

        while (windowShakes.pollEvent(shakesEvent))
        {
            if (shakesEvent.type == Event::Closed)
            {
                windowShakes.close();
            }
            if (shakesEvent.type == Event::KeyPressed)
            {
                if (shakesEvent.key.code == Keyboard::Escape)
                {
                    windowShakes.close();
                }
            }

            if (shakesEvent.type == Event::KeyReleased)
            {
                if (shakesEvent.key.code == Keyboard::Up)
                {
                    menuShakes.MoveUp();
                    break;
                }
                if (shakesEvent.key.code == Keyboard::Down)
                {
                    menuShakes.MoveDown();
                    break;

                }

                if (shakesEvent.key.code == Keyboard::Return)
                {
                    int x = menuShakes.GetPressedItem();

                    //opcje dla menu shakes
                    if (x == 0)
                    {
                        anOrder.productName = "Strawberry shake";
                        anOrder.addToOrder(anOrder.productName);                    
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Vanilla shake";
                        anOrder.addToOrder(anOrder.productName);                    
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Chocolate shake";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "Caramel shake";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 4)
                    {
                        anOrder.productName = "Blueberry shake";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 5)
                    {
                        windowShakes.close();
                        break;
                    }
                }

            }


        }
       

        windowShakes.clear();
        windowShakes.draw(backShakes);
        menuShakes.draw(windowShakes);
        windowShakes.display();
    }







}