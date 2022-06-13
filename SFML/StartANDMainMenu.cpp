#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include "Menu.h"
#include "Enter.h"
#include "Ordernumerclass.h"
#include "DeletingOrder.h"
#include "Bill.h"
#include "sandwichOption.h"
#include "sidesOption.h"
#include "shakesOption.h"
#include "mealsOption.h"
#include "StartANDMainMenu.h"
#include "ExitSure.h"

using namespace sf;
using namespace std;


void startAndMainMenu()
{
    Font font;
    font.loadFromFile("arial.ttf");//zaladowanie czcionki

    RenderWindow windowStart{ VideoMode(600,800),"Start" };//renderowamie okno dla start
    Enter menuStart(windowStart.getSize().x, windowStart.getSize().y);//obiekt menu dla start
    RectangleShape backStart;//t這 dla startu
    backStart.setSize(Vector2f(600, 800));
    Texture imageBackStart;
    imageBackStart.loadFromFile("start.jpg");
    backStart.setTexture(&imageBackStart);

    while (windowStart.isOpen()) //okno start otworzenie
    {
        Text warninng1(" Note: The maximum number of products in an order is 8, products above", font, 14);
        warninng1.setFillColor(Color::Black);
        warninng1.setPosition(63.f, 630.f);
        Text warninng2(" this quantity are not added to the basket. To check the status of the", font, 14);
        warninng2.setFillColor(Color::Black);
        warninng2.setPosition(63.f, 644.f);
        Text warninng3(" basket or remove products from it, go to the -Bill- tab. ", font, 14);
        warninng3.setFillColor(Color::Black);
        warninng3.setPosition(63.f, 658.f);


        Event eventStart;
        while (windowStart.pollEvent(eventStart))
        {
            if (eventStart.type == Event::Closed)//zamkniecie okna start
            {
                windowStart.close();
            }
            if (eventStart.type == Event::KeyReleased)
            {
                if (eventStart.key.code == Keyboard::Up)// strowanie strza趾a w g鏎e
                {
                    menuStart.MoveUp();
                    break;
                }
                if (eventStart.key.code == Keyboard::Down)//sterowanie strza趾a w d馧
                {
                    menuStart.MoveDown();
                    break;
                }

                if (eventStart.key.code == Keyboard::Return)
                {
                    int x = menuStart.GetPressedItem();
                    if (x == 0)//wyb鏎 start w oknie start
                    {
                        RenderWindow windowMainMenu{ VideoMode(600,800),"MainMenu" };//renderowanie okna dla main menu
                        Menu menuMainMenu(windowMainMenu.getSize().x, windowMainMenu.getSize().y);//obiekt dla main menu
                        menuMainMenu.nazwa("Sandwiches", 0);
                        menuMainMenu.nazwa("Shakes", 1);
                        menuMainMenu.nazwa("Sides", 2);
                        menuMainMenu.nazwa("Meals", 3);
                        menuMainMenu.nazwa("Bill", 4);
                        menuMainMenu.nazwa("Exit", 5);

                        RectangleShape backMainMenu;//t這 dla main menu
                        backMainMenu.setSize(Vector2f(600, 800));
                        Texture imageBackMainMenu;
                        imageBackMainMenu.loadFromFile("Menu.png");
                        backMainMenu.setTexture(&imageBackMainMenu);
                        windowStart.close();


                        while (windowMainMenu.isOpen())//otwracie okna dla main menu
                        {
                            Event eventMainMenu;
                            while (windowMainMenu.pollEvent(eventMainMenu))
                            {
                                if (eventMainMenu.type == Event::Closed)//zamkniecie okna main menu
                                {
                                    windowMainMenu.close();
                                }
                                if (eventMainMenu.type == Event::KeyReleased)
                                {
                                    if (eventMainMenu.key.code == Keyboard::Up)//sterowanie w g鏎e
                                    {
                                        menuMainMenu.MoveUp();

                                    }
                                    if (eventMainMenu.key.code == Keyboard::Down)//sterowanie w d馧
                                    {
                                        menuMainMenu.MoveDown();

                                    }
                                    if (eventMainMenu.key.code == Keyboard::Return)
                                    {
                                        int x = menuMainMenu.GetPressedItem();

                                        RenderWindow windowBill(VideoMode(600, 800), "Bill");// -||- dla rachunku
                                        classBill menuBill(windowBill.getSize().x, windowBill.getSize().y);//obiekt dla rachunku
                                        RectangleShape backBill;//t這 dla srachunku
                                        backBill.setSize(Vector2f(600, 800));
                                        Texture imageBackBill;
                                        imageBackBill.loadFromFile("paymecash.png");
                                        backBill.setTexture(&imageBackBill);


                                        if (x == 0)// opcja kanapki
                                        {
                                            sandwitchOption();
                                        }
                                        if (x == 1)
                                        {
                                            shakeOption();
                                        }

                                        if (x == 2)
                                        {
                                            sidesOption();

                                        }//opcja dodatki

                                        if (x == 3)//opcja zestwy
                                        {
                                            mealsOption();


                                        }

                                        if (x == 4)//opcja rachunek
                                        {
                                            while (windowBill.isOpen())
                                            {
                                                Event billEvent;

                                                while (windowBill.pollEvent(billEvent))
                                                {
                                                    if (billEvent.type == Event::Closed)
                                                    {
                                                        windowBill.close();
                                                    }
                                                    if (billEvent.type == Event::KeyPressed)
                                                    {
                                                        if (billEvent.key.code == Keyboard::Escape)
                                                        {
                                                            windowBill.close();
                                                        }
                                                    }

                                                    if (billEvent.type == Event::KeyReleased)
                                                    {
                                                        if (billEvent.key.code == Keyboard::Left)
                                                        {
                                                            menuBill.MoveLeft();
                                                            break;
                                                        }
                                                        if (billEvent.key.code == Keyboard::Right)
                                                        {
                                                            menuBill.MoveRight();
                                                            break;

                                                        }

                                                        if (billEvent.key.code == Keyboard::Return)
                                                        {
                                                            RenderWindow windowNumerOrder(VideoMode(600, 800), "NumerOrder");// renederowanie okna dla numeru zamowienia
                                                            Ordernumerclass menuNumerOrder(windowNumerOrder.getSize().x, windowNumerOrder.getSize().y);//obiekt dla menu numeru zamowienia
                                                            RectangleShape backNumerOrder;//t這 dla okna numeru zamowienia
                                                            backNumerOrder.setSize(Vector2f(600, 800));
                                                            Texture imageBackNumerOrder;
                                                            imageBackNumerOrder.loadFromFile("bonapetit.png");
                                                            backNumerOrder.setTexture(&imageBackNumerOrder);

                                                            windowBill.close();
                                                            RenderWindow windowDeletingOrder(VideoMode(600, 800), "DeletingOrder");// renederowanie okna dla numeru zamowienia
                                                            DeletingOrder menuDeletingOrder(windowDeletingOrder.getSize().x, windowDeletingOrder.getSize().y);//obiekt dla menu numeru zamowienia
                                                            RectangleShape backDeletingOrder;//t這 dla okna us闚ania zam闚ienia
                                                            backDeletingOrder.setSize(Vector2f(600, 800));
                                                            Texture imageBackDeletingOrder;
                                                            imageBackDeletingOrder.loadFromFile("delate.png");
                                                            backDeletingOrder.setTexture(&imageBackDeletingOrder);

                                                            int x = menuBill.GetPressedItem();

                                                            if (x == 0)//opcja zaplac
                                                            {
                                                                windowMainMenu.close();
                                                                windowBill.close();
                                                                while (windowNumerOrder.isOpen())
                                                                {
                                                                    Event numerOrderEvent;
                                                                    while (windowNumerOrder.pollEvent(numerOrderEvent))
                                                                    {
                                                                        if (numerOrderEvent.type == Event::Closed)
                                                                        {
                                                                            windowNumerOrder.close();
                                                                        }
                                                                        if (numerOrderEvent.type == Event::KeyPressed)
                                                                        {
                                                                            if (numerOrderEvent.key.code == Keyboard::Escape)
                                                                            {
                                                                                windowNumerOrder.close();
                                                                            }
                                                                        }
                                                                        if (numerOrderEvent.type == Event::KeyReleased)
                                                                        {


                                                                            if (numerOrderEvent.key.code == Keyboard::Return)
                                                                            {
                                                                                int x = menuNumerOrder.GetPressedItem();
                                                                                if (x == 0)//opcja exit
                                                                                {
                                                                                    windowNumerOrder.close();
                                                                                    break;
                                                                                }

                                                                            }


                                                                        }
                                                                    }
                                                                    windowDeletingOrder.close();
                                                                    windowNumerOrder.clear();
                                                                    windowNumerOrder.draw(backNumerOrder);
                                                                    menuNumerOrder.draw(windowNumerOrder);
                                                                    windowNumerOrder.display();



                                                                }

                                                            }
                                                            if (x == 1)//opcja usun
                                                            {
                                                                windowBill.close();



                                                                while (windowDeletingOrder.isOpen())
                                                                {
                                                                    Event deletingOrderEvent;
                                                                    while (windowDeletingOrder.pollEvent(deletingOrderEvent))
                                                                    {
                                                                        if (deletingOrderEvent.type == Event::Closed)
                                                                        {
                                                                            windowDeletingOrder.close();
                                                                        }
                                                                        if (deletingOrderEvent.type == Event::KeyPressed)
                                                                        {
                                                                            if (deletingOrderEvent.key.code == Keyboard::Escape)
                                                                            {
                                                                                windowDeletingOrder.close();
                                                                            }
                                                                        }
                                                                        if (deletingOrderEvent.type == Event::KeyReleased)
                                                                        {

                                                                            if (deletingOrderEvent.key.code == Keyboard::Up)
                                                                            {
                                                                                menuDeletingOrder.MoveUp();
                                                                                break;
                                                                            }
                                                                            if (deletingOrderEvent.key.code == Keyboard::Down)
                                                                            {
                                                                                menuDeletingOrder.MoveDown();
                                                                                break;

                                                                            }

                                                                            if (deletingOrderEvent.key.code == Keyboard::Return)
                                                                            {
                                                                                int x = menuDeletingOrder.GetPressedItem();

                                                                                if (x == 0)
                                                                                {

                                                                                }

                                                                                if (x == 1)
                                                                                {

                                                                                }
                                                                                if (x == 2)
                                                                                {

                                                                                }
                                                                                if (x == 3)
                                                                                {

                                                                                }
                                                                                if (x == 4)
                                                                                {

                                                                                }
                                                                                if (x == 5)
                                                                                {

                                                                                }


                                                                                if (x == 6)
                                                                                {

                                                                                }
                                                                                if (x == 7)
                                                                                {

                                                                                }

                                                                                if (x == 8)//opcja exit
                                                                                {
                                                                                    windowDeletingOrder.close();
                                                                                    break;
                                                                                }

                                                                            }


                                                                        }
                                                                    }
                                                                    windowNumerOrder.close();
                                                                    windowDeletingOrder.clear();
                                                                    windowDeletingOrder.draw(backDeletingOrder);
                                                                    menuDeletingOrder.draw(windowDeletingOrder);
                                                                    windowDeletingOrder.display();



                                                                }

                                                            }
                                                            if (x == 2)//opcja exit
                                                            {
                                                                windowBill.close();
                                                                break;
                                                            }
                                                        }

                                                    }


                                                }



                                                windowBill.clear();
                                                windowBill.draw(backBill);
                                                menuBill.draw(windowBill);
                                                windowBill.display();
                                            }

                                        }

                                        if (x == 5)//zamyka okno menu- guzik exit
                                        {

                           
                                            RenderWindow windowExitSure(VideoMode(600, 800), "ExitSure");// renederowanie okna dla upewnienia
                                            ExitSure menuExitSure(windowExitSure.getSize().x, windowExitSure.getSize().y);//obiekt dla upewnienia
                                            RectangleShape backExitSure;//t這 dla okna upewnienia
                                            backExitSure.setSize(Vector2f(600, 800));
                                            Texture imageBackExitSure;
                                            imageBackExitSure.loadFromFile("baza2.png");
                                            backExitSure.setTexture(&imageBackExitSure);

                                            while (windowExitSure.isOpen())
                                            {
                                                Event exitSureEvent;
                                                while (windowExitSure.pollEvent(exitSureEvent))
                                                {
                                                    if (exitSureEvent.type == Event::Closed)
                                                    {
                                                        windowExitSure.close();
                                                    }
                                                    if (exitSureEvent.type == Event::KeyPressed)
                                                    {
                                                        if (exitSureEvent.key.code == Keyboard::Escape)
                                                        {
                                                            windowExitSure.close();
                                                        }
                                                    }
                                                    if (exitSureEvent.type == Event::KeyReleased)
                                                    {

                                                        if (exitSureEvent.key.code == Keyboard::Left)
                                                        {
                                                            menuExitSure.MoveLeft();
                                                            break;
                                                        }
                                                        if (exitSureEvent.key.code == Keyboard::Right)
                                                        {
                                                            menuExitSure.MoveRight();
                                                            break;

                                                        }

                                                        if (exitSureEvent.key.code == Keyboard::Return)
                                                        {
                                                            int x = menuExitSure.GetPressedItem();

                                                            if (x == 0)
                                                            {
                                                                windowExitSure.close();
                                                                windowMainMenu.close();
                                                            }

                                                            if (x == 1)
                                                            {
                                                               
                                                                windowExitSure.close();
 
                                                            }
                                                         

                                                        }


                                                    }
                                                }
                                              
                                                windowExitSure.clear();
                                                windowExitSure.draw(backExitSure);
                                                menuExitSure.draw(windowExitSure);
                                                windowExitSure.display();



                                            }
                                          
                                        }


                                    }
                                }
                                windowMainMenu.clear();
                                windowMainMenu.draw(backMainMenu);
                                menuMainMenu.draw(windowMainMenu);
                                windowMainMenu.display();
                            }
                        }


                    }
                    if (x == 1)//exit dla okna startu
                    {
                        windowStart.close();
                        break;
                    }
                }

            }
        }

        windowStart.clear();//czyszczenie okna
        windowStart.draw(backStart);//wyswietalnie t豉 dla enter
        windowStart.draw(warninng1);
        windowStart.draw(warninng2);
        windowStart.draw(warninng3);//wyswietlanie tekstu
        menuStart.draw(windowStart);
        windowStart.display();
    }


}