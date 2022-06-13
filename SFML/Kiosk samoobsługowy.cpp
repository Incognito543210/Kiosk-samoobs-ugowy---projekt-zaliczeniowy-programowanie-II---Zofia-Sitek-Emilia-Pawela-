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
    Enter enter(windowStart.getSize().x, windowStart.getSize().y);//obiekt menu dla start
    RectangleShape entertlo;//tło dla startu
    entertlo.setSize(Vector2f(600, 800));
    Texture enterstart;
    enterstart.loadFromFile("start.jpg");
    entertlo.setTexture(&enterstart);
    
    while (windowStart.isOpen()) //okno start otworzenie
    {
        Text tekst("cpp0x.pl",font,12);
        tekst.setFillColor(Color::Black);
        tekst.setPosition(70.f, 600.f);

        Event evententer;
        while (windowStart.pollEvent(evententer))
        {
            if (evententer.type == Event::Closed)//zamkniecie okna start
            {
                windowStart.close();
            }
            if (evententer.type == Event::KeyReleased)
            {
                if (evententer.key.code == Keyboard::Up)// strowanie strzałka w góre
                {
                    enter.MoveUp();
                    break;
                }
                if (evententer.key.code == Keyboard::Down)//sterowanie strzałka w dół
                {
                    enter.MoveDown();
                    break;
                }

                if (evententer.key.code == Keyboard::Return)
                {
                    int x = enter.GetPressedItem();
                if (x == 0)//wybór start w oknie start
                {
                    RenderWindow Mainmenu{ VideoMode(600,800),"MainMenu" };//renderowanie okna dla main menu
                    Menu menu(Mainmenu.getSize().x, Mainmenu.getSize().y);//obiekt dla main menu
                    menu.nazwa("Sandwishes", 0);
                    menu.nazwa("Shakes", 1);
                    menu.nazwa("Sides", 2);
                    menu.nazwa("Meals", 3);
                    menu.nazwa("Bill", 4);
                    menu.nazwa("Exit", 5);

                    RectangleShape tlostart;//tło dla main menu
                    tlostart.setSize(Vector2f(600, 800));
                    Texture start;
                    start.loadFromFile("Menu.png");
                    tlostart.setTexture(&start);
                    windowStart.close();


                    while (Mainmenu.isOpen())//otwracie okna dla main menu
                    {
                        Event event;
                        while (Mainmenu.pollEvent(event))
                        {
                            if (event.type == Event::Closed)//zamkniecie okna main menu
                            {
                                Mainmenu.close();
                            }
                            if (event.type == Event::KeyReleased)
                            {
                                if (event.key.code==Keyboard::Up)//sterowanie w góre
                                {
                                    menu.MoveUp();
                                    
                                }
                                if (event.key.code==Keyboard::Down)//sterowanie w dół
                                {
                                    menu.MoveDown();
                                    
                                }
                                if (event.key.code == Keyboard::Return)
                                {
                                    int x = menu.GetPressedItem();

                                    RenderWindow Kanapki(VideoMode(600, 800), "Sandwich"); //renderowanie okna dla kanapek
                                    Menu menukanapki(Kanapki.getSize().x, Kanapki.getSize().y);//obiekt dla kanapek
                                    menukanapki.nazwa("Beef", 0);//przypisanie nazw dla menu kanapki
                                    menukanapki.nazwa("Chicken", 1);
                                    menukanapki.nazwa("Tost with ham", 2);
                                    menukanapki.nazwa("Tost with tuna", 3);
                                    menukanapki.nazwa("Creator Sandwich", 4);
                                    menukanapki.nazwa("Exit", 5);

                                    RectangleShape background;//tlo dla kanapek
                                    background.setSize(Vector2f(600, 800));
                                    Texture obrazek;
                                    obrazek.loadFromFile("kanapki.png");
                                    background.setTexture(&obrazek);

                                    RenderWindow Shakes(VideoMode(600, 800), "Shakes");// -||- dla shakes
                                    Menu menuShakes(Shakes.getSize().x, Shakes.getSize().y);//obiekt dla shakes
                                    menuShakes.nazwa("Strawberry", 0);//przypisanie nazw dla menu shakes
                                    menuShakes.nazwa("Vanilla", 1);
                                    menuShakes.nazwa("Chocolate", 2);
                                    menuShakes.nazwa("Carmel", 3);
                                    menuShakes.nazwa("Berry", 4);
                                    menuShakes.nazwa("Exit", 5);
                                    RectangleShape tloshakes;//tlo dla shakes
                                    tloshakes.setSize(Vector2f(600, 800));
                                    Texture obrazshakes;
                                    obrazshakes.loadFromFile("shakes.png");
                                    tloshakes.setTexture(&obrazshakes);

                                    RenderWindow Sides(VideoMode(600, 800), "Sides");// -||- dla Sides
                                    Menu menuSides(Sides.getSize().x, Sides.getSize().y);//obiekt dla sides
                                    menuSides.nazwa("Chips", 0);//przypisanie nazw dla menu sides
                                    menuSides.nazwa("Salad", 1);
                                    menuSides.nazwa("Ketchup", 2);
                                    menuSides.nazwa("KentackyGold", 3);
                                    menuSides.nazwa("Garlic", 4);
                                    menuSides.nazwa("Exit", 5);
                                    RectangleShape tlosides;//tlo dla sides
                                    tlosides.setSize(Vector2f(600, 800));
                                    Texture obrazsides;
                                    obrazsides.loadFromFile("dodatki.png");
                                    tlosides.setTexture(&obrazsides);

                                    RenderWindow Meals(VideoMode(600, 800), "Meals");// -||- dla MEals
                                    Menu menuMeals(Meals.getSize().x, Meals.getSize().y);//obiekt dla Meals
                                    menuMeals.nazwa("Good Meal ", 0);//przypisanie nazw dla menu Meals
                                    menuMeals.nazwa("Tost Ham Meal", 1);
                                    menuMeals.nazwa("Tost Tuna Meal", 2);
                                    menuMeals.nazwa("Studnet Meal", 3);
                                    menuMeals.nazwa("Create your Meal", 4);
                                    menuMeals.nazwa("Exit", 5);
                                    RectangleShape tlomenumeals;//tlo dla Meals
                                    tlomenumeals.setSize(Vector2f(600, 800));
                                    Texture obrazmenumeals;
                                    obrazmenumeals.loadFromFile("baza.png");
                                    tlomenumeals.setTexture(&obrazmenumeals);

                                    RenderWindow Bill(VideoMode(600, 800), "Bill");// -||- dla rachunku
                                    Rachunek rachunek(Bill.getSize().x, Bill.getSize().y);//obiekt dla rachunku
                                    RectangleShape tlorachunek;//tło dla srachunku
                                    tlorachunek.setSize(Vector2f(600, 800));
                                    Texture obrazrachunek;
                                    obrazrachunek.loadFromFile("paymecash.png");
                                    tlorachunek.setTexture(&obrazrachunek);
                                   
                              
                                    if (x == 0)// opcja kanapki
                                    {
                                        while (Kanapki.isOpen())
                                        {
                                            Event avent;
                                            while (Kanapki.pollEvent(avent))
                                            {
                                                if (avent.type == Event::Closed)
                                                {
                                                    Kanapki.close();
                                                }
                                                if (avent.type == Event::KeyReleased)
                                                {
                                                    if (avent.key.code == Keyboard::Up)
                                                    {
                                                        menukanapki.MoveUp();
                                                        break;
                                                    }
                                                    if (avent.key.code == Keyboard::Down)
                                                    {
                                                        menukanapki.MoveDown();
                                                        break;

                                                    }
                                                    if (event.key.code == Keyboard::Return)
                                                    {
                                                     

                                                        int x = menukanapki.GetPressedItem();
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

                                                            RenderWindow KreatorKanapki(VideoMode(600, 800), "SandwichCreator");//okno dla kreatora kanapki
                                                            Menu menukreatorkanapki(KreatorKanapki.getSize().x, KreatorKanapki.getSize().y);//obiekt menau dla kreatora kanapki
                                                            menukreatorkanapki.nazwa("Beef", 0);
                                                            menukreatorkanapki.nazwa("Ham", 1);
                                                            menukreatorkanapki.nazwa("Cheasse", 2);
                                                            menukreatorkanapki.nazwa("Tuna", 3);
                                                            menukreatorkanapki.nazwa("Salad", 4);
                                                            menukreatorkanapki.nazwa("Exit", 5);
                                                            RectangleShape tlokrekan;//tło dla kreatora kanapki
                                                            tlokrekan.setSize(Vector2f(600, 800));
                                                            Texture krekan;
                                                            krekan.loadFromFile("kreatorwybur kanapki.png");
                                                            tlokrekan.setTexture(&krekan);
                                                            while (KreatorKanapki.isOpen())
                                                            {
                                                                Event Kkevent;
                                                                while (KreatorKanapki.pollEvent(Kkevent))
                                                                {
                                                                    if (Kkevent.type == Event::Closed)
                                                                    {
                                                                        KreatorKanapki.close();
                                                                    }
                                                                    if (Kkevent.type == Event::KeyPressed)
                                                                    {
                                                                        if (Kkevent.key.code == Keyboard::Escape)
                                                                        {
                                                                            KreatorKanapki.close();
                                                                        }
                                                                    }
                                                                    if (Kkevent.type == Event::KeyReleased)
                                                                    {
                                                                        if (Kkevent.key.code == Keyboard::Up)
                                                                        {
                                                                            menukreatorkanapki.MoveUp();
                                                                            break;
                                                                        }
                                                                        if (Kkevent.key.code == Keyboard::Down)
                                                                        {
                                                                            menukreatorkanapki.MoveDown();
                                                                            break;
                                                                        }
                                                                        int x = menukreatorkanapki.GetPressedItem();
                                                                        if (Kkevent.key.code == Keyboard::Return)
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
                                                                                KreatorKanapki.close();
                                                                                break;
                                                                            }
                                                                        }


                                                                    }
                                                                }
                                                                KreatorKanapki.clear();//czyszczenie okna 
                                                                KreatorKanapki.draw(tlokrekan);//przypisanie tła dla okna
                                                                menukreatorkanapki.draw(KreatorKanapki);//przypisanie okna do obiketu menu
                                                                KreatorKanapki.display();



                                                            }
                                                        }
                                                        if (x == 5)//zamkniecie okna kanapki
                                                        {
                                                            Kanapki.close();
                                                            break;
                                                        }

                                                    }





                                                }
                                                
                                            }
                                            Shakes.close();//zamykanie okien innych niż menu kanapek
                                            Sides.close();
                                            Meals.close();
                                            Bill.close();

                                            Kanapki.clear();
                                            Kanapki.draw(background);
                                            menukanapki.draw(Kanapki);
                                            Kanapki.display();
                                        }
                                    }
                                    if (x == 1)
                                    {
                                        while (Shakes.isOpen())
                                        {
                                            Event eventshakes;

                                            while (Shakes.pollEvent(eventshakes))
                                            {
                                                if (eventshakes.type == Event::Closed)
                                                {
                                                    Shakes.close();
                                                }
                                                if (eventshakes.type == Event::KeyPressed)
                                                {
                                                    if (eventshakes.key.code == Keyboard::Escape)
                                                    {
                                                        Shakes.close();
                                                    }
                                                }

                                                if (eventshakes.type == Event::KeyReleased)
                                                {
                                                    if (eventshakes.key.code == Keyboard::Up)
                                                    {
                                                        menuShakes.MoveUp();
                                                        break;
                                                    }
                                                    if (eventshakes.key.code == Keyboard::Down)
                                                    {
                                                        menuShakes.MoveDown();
                                                        break;

                                                    }

                                                    if (eventshakes.key.code == Keyboard::Return)
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
                                                            Shakes.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            Kanapki.close();                            
                                            Sides.close();
                                            Meals.close();
                                            Bill.close();

                                            Shakes.clear();
                                            Shakes.draw(tloshakes);
                                            menuShakes.draw(Shakes);
                                            Shakes.display();
                                        }
                                    }

                                    if (x == 2)
                                    {
                                        while (Sides.isOpen())
                                        {
                                            Event eventsides;

                                            while (Sides.pollEvent(eventsides))
                                            {
                                                if (eventsides.type == Event::Closed)
                                                {
                                                    Sides.close();
                                                }
                                                if (eventsides.type == Event::KeyPressed)
                                                {
                                                    if (eventsides.key.code == Keyboard::Escape)
                                                    {
                                                        Sides.close();
                                                    }
                                                }

                                                if (eventsides.type == Event::KeyReleased)
                                                {
                                                    if (eventsides.key.code == Keyboard::Up)
                                                    {
                                                        menuSides.MoveUp();
                                                        break;
                                                    }
                                                    if (eventsides.key.code == Keyboard::Down)
                                                    {
                                                        menuSides.MoveDown();
                                                        break;

                                                    }

                                                    if (eventsides.key.code == Keyboard::Return)
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
                                                            Sides.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            Kanapki.close();
                                            Shakes.close();
                                            Meals.close();
                                            Bill.close();

                                            Sides.clear();
                                            Sides.draw(tlosides);
                                            menuSides.draw(Sides);
                                            Sides.display();
                                        }
                                    }//opcja dodatki

                                    if(x==3)//opcja zestwy
                                    { 
                                        while (Meals.isOpen())
                                        {
                                            Event eventmenumeals;
                                            while (Meals.pollEvent(eventmenumeals))
                                            {
                                                if (eventmenumeals.type == Event::Closed)
                                                {
                                                    Meals.close();
                                                }
                                                if (eventmenumeals.type == Event::KeyReleased)
                                                {
                                                    if (eventmenumeals.key.code == Keyboard::Up)
                                                    {
                                                        menuMeals.MoveUp();
                                                        break;
                                                    }
                                                    if (eventmenumeals.key.code == Keyboard::Down)
                                                    {
                                                        menuMeals.MoveDown();
                                                        break;

                                                    }
                                                    if (eventmenumeals.key.code == Keyboard::Return)
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

                                                            RenderWindow KreatorMeals(VideoMode(600, 800), "MealCreator");//okno dla kreatora Meals
                                                            Menu menukreatorMeals(KreatorMeals.getSize().x, KreatorMeals.getSize().y);//obiekt menau dla kreatora melas
                                                            menukreatorMeals.nazwa("Beff Burger", 0);
                                                            menukreatorMeals.nazwa("Tuna Tost", 1);
                                                            menukreatorMeals.nazwa("Chips", 2);
                                                            menukreatorMeals.nazwa("Salad", 3);
                                                            menukreatorMeals.nazwa("Garlic", 4);
                                                            menukreatorMeals.nazwa("Exit", 5);
                                                            RectangleShape tlokremeals;//tło dla kreatora kanapki
                                                            tlokremeals.setSize(Vector2f(600, 800));
                                                            Texture kremeals;
                                                            kremeals.loadFromFile("mealcreator.png");
                                                            tlokremeals.setTexture(&kremeals);
                                                            while (KreatorMeals.isOpen())
                                                            {
                                                                Event eventkremeals;
                                                                while (KreatorMeals.pollEvent(eventkremeals))
                                                                {
                                                                    if (eventkremeals.type == Event::Closed)
                                                                    {
                                                                        KreatorMeals.close();
                                                                    }
                                                                    if (eventkremeals.type == Event::KeyPressed)
                                                                    {
                                                                        if (eventkremeals.key.code == Keyboard::Escape)
                                                                        {
                                                                            KreatorMeals.close();
                                                                        }
                                                                    }
                                                                    if (eventkremeals.type == Event::KeyReleased)
                                                                    {
                                                                        if (eventkremeals.key.code == Keyboard::Up)
                                                                        {
                                                                            menukreatorMeals.MoveUp();
                                                                            break;
                                                                        }
                                                                        if (eventkremeals.key.code == Keyboard::Down)
                                                                        {
                                                                            menukreatorMeals.MoveDown();
                                                                            break;
                                                                        }
                                                                        int x = menukreatorMeals.GetPressedItem();
                                                                        if (eventkremeals.key.code == Keyboard::Return)
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
                                                                                KreatorMeals.close();
                                                                                break;
                                                                            }
                                                                        }


                                                                    }
                                                                }
                                                                KreatorMeals.clear();
                                                                KreatorMeals.draw(tlokremeals);
                                                                menukreatorMeals.draw(KreatorMeals);
                                                                KreatorMeals.display();



                                                            }
                                                        }
                                                        if (x == 5)//zamkniecie okna meals
                                                        {
                                                            Meals.close();
                                                            break;
                                                        }

                                                    }





                                                }

                                            }
                                            Shakes.close();
                                            Sides.close();
                                            Kanapki.close();
                                            Bill.close();

                                            Meals.clear();
                                            Meals .draw(tlomenumeals);
                                            menuMeals.draw(Meals);
                                            Meals.display();
                                        }
                                    
                                    
                                    }

                                    if(x==4)//opcja rachunek
                                    { 
                                        while (Bill.isOpen())
                                        {
                                            Event eventbill;

                                            while (Bill.pollEvent(eventbill))
                                            {
                                                if (eventbill.type == Event::Closed)
                                                {
                                                    Bill.close();
                                                }
                                                if (eventbill.type == Event::KeyPressed)
                                                {
                                                    if (eventbill.key.code == Keyboard::Escape)
                                                    {
                                                        Bill.close();
                                                    }
                                                }

                                                if (eventbill.type == Event::KeyReleased)
                                                {
                                                    if (eventbill.key.code == Keyboard::Left)
                                                    {
                                                        rachunek.MoveLeft();
                                                        break;
                                                    }
                                                    if (eventbill.key.code == Keyboard::Right)
                                                    {
                                                        rachunek.MoveRight();
                                                        break;

                                                    }

                                                    if (eventbill.key.code == Keyboard::Return)
                                                    {
                                                        RenderWindow Numerorder(VideoMode(600, 800), "Numerorder");// renederowanie okna dla numeru zamowienia
                                                        Ordernumerclass Orderobiekt(Numerorder.getSize().x, Numerorder.getSize().y);//obiekt dla menu numeru zamowienia
                                                        RectangleShape tloorder;//tło dla okna numeru zamowienia
                                                        tloorder.setSize(Vector2f(600, 800));
                                                        Texture obrazorder;
                                                        obrazorder.loadFromFile("bonapetit.png");
                                                        tloorder.setTexture(&obrazorder);

                                                        int x = rachunek.GetPressedItem();
                                                       
                                                        if (x == 0)//opcja zaplac
                                                        {
                                                            Mainmenu.close();
                                                            Bill.close();
                                                            while (Numerorder.isOpen())
                                                            {
                                                                Event eventorder;
                                                                while (Numerorder.pollEvent(eventorder))
                                                                {
                                                                    if (eventorder.type == Event::Closed)
                                                                    {
                                                                        Numerorder.close();
                                                                    }
                                                                    if (eventorder.type == Event::KeyPressed)
                                                                    {
                                                                        if (eventorder.key.code == Keyboard::Escape)
                                                                        {
                                                                            Numerorder.close();
                                                                        }
                                                                    }
                                                                    if (eventorder.type == Event::KeyReleased)
                                                                    {
                                                                      
                                                                       
                                                                        if (eventorder.key.code == Keyboard::Return)
                                                                        {
                                                                            int x = Orderobiekt.GetPressedItem();
                                                                            if (x == 0)//opcja exit
                                                                            {
                                                                                Numerorder.close();
                                                                                break;
                                                                            }
                                                                            
                                                                        }


                                                                    }
                                                                }
                                                               
                                                                Numerorder.clear();
                                                                Numerorder.draw(tloorder);
                                                                Orderobiekt.draw(Numerorder);
                                                                Numerorder.display();



                                                            }

                                                        }
                                                        if (x == 1)
                                                        {
                                                        }
                                                        if(x==2)//opcja exit
                                                        { 
                                                            Bill.close();
                                                            break;
                                                        }
                                                    }

                                                }


                                            }
                                            Kanapki.close();
                                            Sides.close();
                                            Meals.close();
                                            Shakes.close();

                                            Bill.clear();
                                            Bill.draw(tlorachunek);
                                            rachunek.draw(Bill);
                                            Bill.display();
                                        }
                                    
                                    }

                                    if (x == 5)//zamyka okno menu- guzik exit
                                    {
                                        Mainmenu.close();
                                        
                                        break;
                                    }


                                }
                            }
                            Mainmenu.clear();
                            Mainmenu.draw(tlostart);
                            menu.draw(Mainmenu);
                            Mainmenu.display();
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
            windowStart.draw(entertlo);//wyswietalnie tła dla enter
            windowStart.draw(tekst);//wyswietlanie tekstu
            enter.draw(windowStart);
            windowStart.display();
    }
        
    
        return 0;
    }

