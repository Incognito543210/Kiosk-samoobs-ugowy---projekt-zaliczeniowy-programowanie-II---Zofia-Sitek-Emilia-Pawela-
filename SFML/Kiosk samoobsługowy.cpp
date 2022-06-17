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
#include "AnOrder.h"

using namespace sf;
using namespace std;


//funkcja main

int main()
{
    srand(time(NULL));
    Order yourOrder;
    startAndMainMenu(yourOrder);
    
    return 0;
 }

