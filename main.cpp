/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.3.2017
 *
 * Description: This file hosts the member functions of the
 * board class.  These functions allow the user to create
 * a board, set moves on the blank board, as well as check
 * the status of the game to see if there is a winner or a
 * draw.
**************************************************************/
#include "Store.hpp"

#include <iostream>

int main() {
    // STORE CREATION
    Store testStore;

    /*********************************************
     *              STORE PRODUCTS
     *********************************************/
     Product banana("100",
                    "Banana",
                    "yellow fruit, lots of potassium",
                    1.25,
                    10);

    Product apple(  "200",
                    "Apple",
                    "red fruit, keeps the doctor away.",
                    1.50,
                    30);

    Product cookies("305",
                    "Cookies",
                    "fresh sweets, chocolate chips, and baked fresh daily",
                    3.25,
                    12);

    Product milk(   "400",
                    "Milk",
                    "Lots of protein and calcium, keeps your bones strong",
                    2.50,
                    40);

    Product beer(   "2002",
                    "Beer",
                    "Craft selections changed out weekly, extra hops for you!",
                    6.50,
                    6);

    Product iceCream(   "505",
                        "Ice Cream",
                        "Great on a hot day, frozen desserts churned daily",
                        3.50,
                        15);

    // Add products to the store for use
    testStore.addProduct(&banana);
    testStore.addProduct(&apple);
    testStore.addProduct(&cookies);
    testStore.addProduct(&milk);
    testStore.addProduct(&beer);
    testStore.addProduct(&iceCream);

    /*********************************************
     *              STORE MEMBERS
     *********************************************/


    return 0;
}