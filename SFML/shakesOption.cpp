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

    Font font;
    font.loadFromFile("BAUHS93.ttf");

    Text noteShakes(" Note: Press ENTER to add a product to the order.", font, 18);
    noteShakes.setFillColor(Color::Black);
    noteShakes.setPosition(57.f, 730.f);

    
    RenderWindow windowShakes(VideoMode(600, 800), "Shakes");// -||- dla shakes
    Menu menuShakes(windowShakes.getSize().x, windowShakes.getSize().y);//obiekt dla shakes
    menuShakes.name("Strawberry", 0);//przypisanie nazw dla menu shakes
    menuShakes.name("Vanilla", 1);
    menuShakes.name("Chocolate", 2);
    menuShakes.name("Caramel", 3);
    menuShakes.name("Blueberry", 4);
    menuShakes.name("EXIT", 5);
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
                        anOrder.addToOrder(anOrder.productName,3);                    
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Vanilla shake";
                        anOrder.addToOrder(anOrder.productName,3);                    
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Chocolate shake";
                        anOrder.addToOrder(anOrder.productName,3);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "Caramel shake";
                        anOrder.addToOrder(anOrder.productName,3);
                    }
                    if (x == 4)
                    {
                        anOrder.productName = "Blueberry shake";
                        anOrder.addToOrder(anOrder.productName,3);
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
        windowShakes.draw(noteShakes);
        windowShakes.display();
    }







}