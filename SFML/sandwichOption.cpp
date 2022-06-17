#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include "sandwichOption.h"
#include "Menu.h"
#include "Enter.h"
#include "Ordernumerclass.h"
#include "DeletingOrder.h"
#include "Bill.h"
#include "AnOrder.h"


using namespace sf;
using namespace std;

void sandwichOption(Order &anOrder)
{
    RenderWindow windowSandwich(VideoMode(600, 800), "Sandwich"); //renderowanie okna dla kanapek
    Menu menuSandwich(windowSandwich.getSize().x, windowSandwich.getSize().y);//obiekt dla kanapek
    menuSandwich.nazwa("Beef burger", 0);//przypisanie nazw dla menu kanapki
    menuSandwich.nazwa("Chicken burger", 1);
    menuSandwich.nazwa("Ham&cheese sandwich", 2);
    menuSandwich.nazwa("Tuna sandwich", 3);
    menuSandwich.nazwa("Sandwich creator", 4);
    menuSandwich.nazwa("Exit", 5);

    RectangleShape backSandwich;//tlo dla kanapek
    backSandwich.setSize(Vector2f(600, 800));
    Texture imageBackSandwich;
    imageBackSandwich.loadFromFile("kanapki.png");
    backSandwich.setTexture(&imageBackSandwich);

    while (windowSandwich.isOpen())
    {
        Event sandwichEvent;
        while (windowSandwich.pollEvent(sandwichEvent))
        {
            if (sandwichEvent.type == Event::Closed)
            {
                windowSandwich.close();
            }
            if (sandwichEvent.type == Event::KeyReleased)
            {
                if (sandwichEvent.key.code == Keyboard::Up)
                {
                    menuSandwich.MoveUp();
                    break;
                }
                if (sandwichEvent.key.code == Keyboard::Down)
                {
                    menuSandwich.MoveDown();
                    break;

                }
                if (sandwichEvent.key.code == Keyboard::Return)
                {


                    int x = menuSandwich.GetPressedItem();
                    //wybór kanapek w menu
                    if (x == 0)
                    {
                        anOrder.productName = "Beef burger";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 1)
                    {
                        anOrder.productName = "Chicken burger";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 2)
                    {
                        anOrder.productName = "Ham&cheese sandwich";
                        anOrder.addToOrder(anOrder.productName);
                    }
                    if (x == 3)
                    {
                        anOrder.productName = "Tuna sandwich";
                        anOrder.addToOrder(anOrder.productName);
                    }

                    if (x == 4)//kreator kanapki
                    {

                        RenderWindow windowCreatorSandwich(VideoMode(600, 800), "SandwichCreator");//okno dla kreatora kanapki
                        Menu menuCreatorSandwich(windowCreatorSandwich.getSize().x, windowCreatorSandwich.getSize().y);//obiekt menau dla kreatora kanapki
                        menuCreatorSandwich.nazwa("Beef", 0);
                        menuCreatorSandwich.nazwa("Ham", 1);
                        menuCreatorSandwich.nazwa("Cheese", 2);
                        menuCreatorSandwich.nazwa("Tuna", 3);
                        menuCreatorSandwich.nazwa("Lettuce", 4);
                        menuCreatorSandwich.nazwa("Exit", 5);
                        RectangleShape backCreatorSandwich;//t³o dla kreatora kanapki
                        backCreatorSandwich.setSize(Vector2f(600, 800));
                        Texture imageBackCreatorSandwich;
                        imageBackCreatorSandwich.loadFromFile("kreatorwybur kanapki.png");
                        backCreatorSandwich.setTexture(&imageBackCreatorSandwich);
                        while (windowCreatorSandwich.isOpen())
                        {
                            Event creatorSandwichEvent;
                            while (windowCreatorSandwich.pollEvent(creatorSandwichEvent))
                            {
                                if (creatorSandwichEvent.type == Event::Closed)
                                {
                                    windowCreatorSandwich.close();
                                }
                                if (creatorSandwichEvent.type == Event::KeyPressed)
                                {
                                    if (creatorSandwichEvent.key.code == Keyboard::Escape)
                                    {
                                        windowCreatorSandwich.close();
                                    }
                                }
                                if (creatorSandwichEvent.type == Event::KeyReleased)
                                {
                                    if (creatorSandwichEvent.key.code == Keyboard::Up)
                                    {
                                        menuCreatorSandwich.MoveUp();
                                        break;
                                    }
                                    if (creatorSandwichEvent.key.code == Keyboard::Down)
                                    {
                                        menuCreatorSandwich.MoveDown();
                                        break;
                                    }
                                    int x = menuCreatorSandwich.GetPressedItem();
                                    if (creatorSandwichEvent.key.code == Keyboard::Return)
                                    {//opcje dla kreatora kanapki
                                        if (x == 0)
                                        {                                        
                                            anOrder.ingredientName = "Beef";
                                            anOrder.addToSandwich(anOrder.ingredientName);
                                        }
                                        if (x == 1)
                                        {
                                            anOrder.ingredientName = "Ham";
                                            anOrder.addToSandwich(anOrder.ingredientName);
                                        }
                                        if (x == 2)
                                        {
                                            anOrder.ingredientName = "Cheese";
                                            anOrder.addToSandwich(anOrder.ingredientName);
                                        }
                                        if (x == 3)
                                        {
                                            anOrder.ingredientName = "Tuna";
                                            anOrder.addToSandwich(anOrder.ingredientName);
                                        }
                                        if (x == 4)
                                        {
                                            anOrder.ingredientName = "Lettuce";
                                            anOrder.addToSandwich(anOrder.ingredientName);
                                        }
                                        if (x == 5)
                                        {
                                            anOrder.addSandwich();
                                            windowCreatorSandwich.close();
                                            break;
                                        }
                                    }


                                }
                            }
                            windowCreatorSandwich.clear();//czyszczenie okna 
                            windowCreatorSandwich.draw(backCreatorSandwich);//przypisanie t³a dla okna
                            menuCreatorSandwich.draw(windowCreatorSandwich);//przypisanie okna do obiketu menu
                            windowCreatorSandwich.display();



                        }
                    }
                    if (x == 5)//zamkniecie okna kanapki
                    {
                        windowSandwich.close();
                        break;
                    }

                }





            }

        }
   

        windowSandwich.clear();
        windowSandwich.draw(backSandwich);
        menuSandwich.draw(windowSandwich);
        windowSandwich.display();
    }
}