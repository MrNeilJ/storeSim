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
     Product banana(        "100",
                            "Banana",
                            "yellow fruit, lots of potassium",
                            1.25,
                            10);

    Product apple(          "200",
                            "Apple",
                            "red fruit, keeps the doctor away.",
                            1.50,
                            30);

    Product cookies(        "305",
                            "Cookies",
                            "fresh sweets, chocolate chips, and baked fresh daily",
                            3.25,
                            12);

    Product milk(           "400",
                            "Milk",
                            "Lots of protein and calcium, keeps your bones strong",
                            2.50,
                            40);

    Product beer(           "2002",
                            "Beer",
                            "Craft selections changed out weekly, extra hops for you!",
                            6.50,
                            6);

    Product iceCream(       "505",
                            "Ice Cream",
                            "Great on a hot day, frozen desserts churned daily",
                            3.50,
                            15);

    Product bread(          "502",
                            "Bread",
                            "Baked daily. Soft, whole-grain loafs.",
                            4.25,
                            2);

    Product redBlender(     "720",
                            "Red Blender",
                            "Sturdy blender perfect for making smoothies and sauces",
                            350,
                            1);

    Product hotAirBalloon(  "8220",
                            "Hot Air Balloon",
                            "Fly into the sky in your own balloon - comes in red, blue or chartreuse",
                            700,
                            1);

    Product giantRobot(     "900",
                            "Giant Robot",
                            "Pierce the heavens with your drill in this glorious robot! Size may vary",
                            7000,
                            1);

    Product liveGoat(       "650",
                            "Live Goat",
                            "Yes, you read this right. One live goat. Take it, it eats everything",
                            1,
                            1);

    Product oakTable(       "1984",
                            "Oak and Glass Coffee Table",
                            "Only the highest of quality woods used in our tables here, oh and oak",
                            250,
                            10);

    // Add products to the store for use
    testStore.addProduct(&banana);
    testStore.addProduct(&apple);
    testStore.addProduct(&cookies);
    testStore.addProduct(&milk);
    testStore.addProduct(&beer);
    testStore.addProduct(&iceCream);
    testStore.addProduct(&bread);
    testStore.addProduct(&redBlender);
    testStore.addProduct(&hotAirBalloon);
    testStore.addProduct(&giantRobot);
    testStore.addProduct(&liveGoat);
    testStore.addProduct(&oakTable);

    /*********************************************
     *              STORE MEMBERS
     *********************************************/
    Customer danny(     "Danny",    "1", true);
    Customer todd(      "Todd",     "2", true);
    Customer chase(     "Chase",    "3", false);
    Customer kyle(      "Kyle",     "4", true);
    Customer travis(    "Travis",   "5", true);
    Customer doug(      "Doug",     "6", false);
    Customer haley(     "Haley",    "7", true);
    Customer andy(      "Andy",     "8", true);
    Customer Shaun(     "Shaun",    "9", false);
    Customer brendan(   "Brendan",  "10", true);




    return 0;
}