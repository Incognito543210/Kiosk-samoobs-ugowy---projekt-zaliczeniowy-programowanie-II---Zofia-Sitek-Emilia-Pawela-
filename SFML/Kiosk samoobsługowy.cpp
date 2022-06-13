#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include "Menu.h"
#include "Enter.h"
#include "Ordernumerclass.h"
#include "Rachunek.h"

using namespace sf;
using namespace std;

//funkcja main

int main()

{
    Font font;
    font.loadFromFile("arial.ttf");//zaladowanie czcionki

    RenderWindow windowStart{ VideoMode(600,800),"Start" };//renderowamie okno dla start
    Enter menuStart(windowStart.getSize().x, windowStart.getSize().y);//obiekt menu dla start
    RectangleShape backStart;//tło dla startu
    backStart.setSize(Vector2f(600, 800));
    Texture imageBackStart;
    imageBackStart.loadFromFile("start.jpg");
    backStart.setTexture(&imageBackStart);
    
    while (windowStart.isOpen()) //okno start otworzenie
    {
        Text warninng1(" Note: The maximum number of products in an order is 8, products above",font,14);
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
                if (eventStart.key.code == Keyboard::Up)// strowanie strzałka w góre
                {
                    menuStart.MoveUp();
                    break;
                }
                if (eventStart.key.code == Keyboard::Down)//sterowanie strzałka w dół
                {
                    menuStart.MoveDown();
                    break;
                }

                if (eventStart.key.code == Keyboard::Return)
                {
                    int x = menuStart.GetPressedItem();
                if (x == 0)//wybór start w oknie start
                {
                    RenderWindow windowMainMenu{ VideoMode(600,800),"MainMenu" };//renderowanie okna dla main menu
                    Menu menuMainMenu(windowMainMenu.getSize().x, windowMainMenu.getSize().y);//obiekt dla main menu
                    menuMainMenu.nazwa("Sandwiches", 0);
                    menuMainMenu.nazwa("Shakes", 1);
                    menuMainMenu.nazwa("Sides", 2);
                    menuMainMenu.nazwa("Meals", 3);
                    menuMainMenu.nazwa("Bill", 4);
                    menuMainMenu.nazwa("Exit", 5);

                    RectangleShape backMainMenu;//tło dla main menu
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
                                if (eventMainMenu.key.code==Keyboard::Up)//sterowanie w góre
                                {
                                    menuMainMenu.MoveUp();
                                    
                                }
                                if (eventMainMenu.key.code==Keyboard::Down)//sterowanie w dół
                                {
                                    menuMainMenu.MoveDown();
                                    
                                }
                                if (eventMainMenu.key.code == Keyboard::Return)
                                {
                                    int x = menuMainMenu.GetPressedItem();

                                    RenderWindow windowSandwich(VideoMode(600, 800), "Sandwich"); //renderowanie okna dla kanapek
                                    Menu menuSandwich(windowSandwich.getSize().x, windowSandwich.getSize().y);//obiekt dla kanapek
                                    menuSandwich.nazwa("Beef", 0);//przypisanie nazw dla menu kanapki
                                    menuSandwich.nazwa("Chicken", 1);
                                    menuSandwich.nazwa("Tost with ham", 2);
                                    menuSandwich.nazwa("Tost with tuna", 3);
                                    menuSandwich.nazwa("Creator Sandwich", 4);
                                    menuSandwich.nazwa("Exit", 5);

                                    RectangleShape backSandwich;//tlo dla kanapek
                                    backSandwich.setSize(Vector2f(600, 800));
                                    Texture imageBackSandwich;
                                    imageBackSandwich.loadFromFile("kanapki.png");
                                    backSandwich.setTexture(&imageBackSandwich);

                                    RenderWindow windowShakes(VideoMode(600, 800), "Shakes");// -||- dla shakes
                                    Menu menuShakes(windowShakes.getSize().x, windowShakes.getSize().y);//obiekt dla shakes
                                    menuShakes.nazwa("Strawberry", 0);//przypisanie nazw dla menu shakes
                                    menuShakes.nazwa("Vanilla", 1);
                                    menuShakes.nazwa("Chocolate", 2);
                                    menuShakes.nazwa("Carmel", 3);
                                    menuShakes.nazwa("Berry", 4);
                                    menuShakes.nazwa("Exit", 5);
                                    RectangleShape backShakes;//tlo dla shakes
                                    backShakes.setSize(Vector2f(600, 800));
                                    Texture imageBackShakes;
                                    imageBackShakes.loadFromFile("shakes.png");
                                    backShakes.setTexture(&imageBackShakes);

                                    RenderWindow windowSides(VideoMode(600, 800), "Sides");// -||- dla Sides
                                    Menu menuSides(windowSides.getSize().x, windowSides.getSize().y);//obiekt dla sides
                                    menuSides.nazwa("Chips", 0);//przypisanie nazw dla menu sides
                                    menuSides.nazwa("Salad", 1);
                                    menuSides.nazwa("Ketchup", 2);
                                    menuSides.nazwa("KentackyGold", 3);
                                    menuSides.nazwa("Garlic", 4);
                                    menuSides.nazwa("Exit", 5);
                                    RectangleShape backSides;//tlo dla sides
                                    backSides.setSize(Vector2f(600, 800));
                                    Texture imageBackSides;
                                    imageBackSides.loadFromFile("dodatki.png");
                                    backSides.setTexture(&imageBackSides);

                                    RenderWindow windowMeals(VideoMode(600, 800), "Meals");// -||- dla MEals
                                    Menu menuMeals(windowMeals.getSize().x, windowMeals.getSize().y);//obiekt dla Meals
                                    menuMeals.nazwa("Good Meal ", 0);//przypisanie nazw dla menu Meals
                                    menuMeals.nazwa("Tost Ham Meal", 1);
                                    menuMeals.nazwa("Tost Tuna Meal", 2);
                                    menuMeals.nazwa("Studnet Meal", 3);
                                    menuMeals.nazwa("Create your Meal", 4);
                                    menuMeals.nazwa("Exit", 5);
                                    RectangleShape backMeals;//tlo dla Meals
                                    backMeals.setSize(Vector2f(600, 800));
                                    Texture imageBackMeals;
                                    imageBackMeals.loadFromFile("baza.png");
                                    backMeals.setTexture(&imageBackMeals);

                                    RenderWindow windowBill(VideoMode(600, 800), "Bill");// -||- dla rachunku
                                    Rachunek menuBill(windowBill.getSize().x, windowBill.getSize().y);//obiekt dla rachunku
                                    RectangleShape backBill;//tło dla srachunku
                                    backBill.setSize(Vector2f(600, 800));
                                    Texture imageBackBill;
                                    imageBackBill.loadFromFile("paymecash.png");
                                    backBill.setTexture(&imageBackBill);
                                   
                              
                                    if (x == 0)// opcja kanapki
                                    {
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
                                                    if (eventMainMenu.key.code == Keyboard::Return)
                                                    {
                                                     

                                                        int x = menuSandwich.GetPressedItem();
                                                        //wybór kanapek w menu
                                                        if (x == 0) 
                                                        {
                                                           
                                                           
                                                        }

                                                        if (x == 1)
                                                        {
                                                          
                                                        }
                                                        if(x==2)
                                                        {
                                                           
                                                        }
                                                        if(x==3)
                                                        {
                                                           
                                                        }
                                                   
                                                        if(x==4)//kreator kanapki
                                                        {

                                                            RenderWindow windowCreatorSandwich(VideoMode(600, 800), "SandwichCreator");//okno dla kreatora kanapki
                                                            Menu menuCreatorSandwich(windowCreatorSandwich.getSize().x, windowCreatorSandwich.getSize().y);//obiekt menau dla kreatora kanapki
                                                            menuCreatorSandwich.nazwa("Beef", 0);
                                                            menuCreatorSandwich.nazwa("Ham", 1);
                                                            menuCreatorSandwich.nazwa("Cheasse", 2);
                                                            menuCreatorSandwich.nazwa("Tuna", 3);
                                                            menuCreatorSandwich.nazwa("Salad", 4);
                                                            menuCreatorSandwich.nazwa("Exit", 5);
                                                            RectangleShape backCreatorSandwich;//tło dla kreatora kanapki
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
                                                                            if(x==0)
                                                                            { }
                                                                            if(x==1)
                                                                            { }
                                                                            if (x == 3)
                                                                            {
                                                                            }
                                                                            if (x == 4)
                                                                            {
                                                                            }
                                                                            if (x == 5)
                                                                            {
                                                                                windowCreatorSandwich.close();
                                                                                break;
                                                                            }
                                                                        }


                                                                    }
                                                                }
                                                                windowCreatorSandwich.clear();//czyszczenie okna 
                                                                windowCreatorSandwich.draw(backCreatorSandwich);//przypisanie tła dla okna
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
                                            windowShakes.close();//zamykanie okien innych niż menu kanapek
                                            windowSides.close();
                                            windowMeals.close();
                                            windowBill.close();

                                            windowSandwich.clear();
                                            windowSandwich.draw(backSandwich);
                                            menuSandwich.draw(windowSandwich);
                                            windowSandwich.display();
                                        }
                                    }
                                    if (x == 1)
                                    {
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
                                                        if(x==0)
                                                        { }
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
                                                            windowShakes.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            windowSandwich.close();                            
                                            windowSides.close();
                                            windowMeals.close();
                                            windowBill.close();

                                            windowShakes.clear();
                                            windowShakes.draw(backShakes);
                                            menuShakes.draw(windowShakes);
                                            windowShakes.display();
                                        }
                                    }

                                    if (x == 2)
                                    {
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
                                                            windowSides.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            windowSandwich.close();
                                            windowShakes.close();
                                            windowMeals.close();
                                            windowBill.close();

                                            windowSides.clear();
                                            windowSides.draw(backSides);
                                            menuSides.draw(windowSides);
                                            windowSides.display();
                                        }
                                    }//opcja dodatki

                                    if(x==3)//opcja zestwy
                                    { 
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

                                                            RenderWindow windowCreatorMeals(VideoMode(600, 800), "MealCreator");//okno dla kreatora Meals
                                                            Menu menuCreatorMeals(windowCreatorMeals.getSize().x, windowCreatorMeals.getSize().y);//obiekt menau dla kreatora melas
                                                            menuCreatorMeals.nazwa("Beff Burger", 0);
                                                            menuCreatorMeals.nazwa("Tuna Tost", 1);
                                                            menuCreatorMeals.nazwa("Chips", 2);
                                                            menuCreatorMeals.nazwa("Salad", 3);
                                                            menuCreatorMeals.nazwa("Garlic", 4);
                                                            menuCreatorMeals.nazwa("Exit", 5);
                                                            RectangleShape backCreatorMeals;//tło dla kreatora kanapki
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
                                                                            }
                                                                            if (x == 1)
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
                                            windowShakes.close();
                                            windowSides.close();
                                            windowSandwich.close();
                                            windowBill.close();

                                            windowMeals.clear();
                                            windowMeals .draw(backMeals);
                                            menuMeals.draw(windowMeals);
                                            windowMeals.display();
                                        }
                                    
                                    
                                    }

                                    if(x==4)//opcja rachunek
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
                                                        RenderWindow windowNumerOrder(VideoMode(600, 800), "Numerorder");// renederowanie okna dla numeru zamowienia
                                                        Ordernumerclass menuNumerOrder(windowNumerOrder.getSize().x, windowNumerOrder.getSize().y);//obiekt dla menu numeru zamowienia
                                                        RectangleShape backNumerOrder;//tło dla okna numeru zamowienia
                                                        backNumerOrder.setSize(Vector2f(600, 800));
                                                        Texture imageBackNumerOrder;
                                                        imageBackNumerOrder.loadFromFile("bonapetit.png");
                                                        backNumerOrder.setTexture(&imageBackNumerOrder);

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
                                                               
                                                                windowNumerOrder.clear();
                                                                windowNumerOrder.draw(backNumerOrder);
                                                                menuNumerOrder.draw(windowNumerOrder);
                                                                windowNumerOrder.display();



                                                            }

                                                        }
                                                        if (x == 1)
                                                        {
                                                        }
                                                        if(x==2)//opcja exit
                                                        { 
                                                            windowBill.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            windowSandwich.close();
                                            windowSides.close();
                                            windowMeals.close();
                                            windowShakes.close();

                                            windowBill.clear();
                                            windowBill.draw(backBill);
                                            menuBill.draw(windowBill);
                                            windowBill.display();
                                        }
                                    
                                    }

                                    if (x == 5)//zamyka okno menu- guzik exit
                                    {
                                        windowMainMenu.close();
                                        
                                        break;
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
            windowStart.draw(backStart);//wyswietalnie tła dla enter
            windowStart.draw(warninng1);
            windowStart.draw(warninng2);
            windowStart.draw(warninng3);//wyswietlanie tekstu
            menuStart.draw(windowStart);
            windowStart.display();
    }
        
    
        return 0;
    }

