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
#include <string>

int main() {
    // STORE CREATION
    Store testStore;

    /*********************************************
     *              STORE PRODUCTS
     *********************************************/
     Product banana(        "1",
                            "Banana",
                            "yellow fruit, lots of potassium",
                            1.25,
                            10);

    Product apple(          "2",
                            "Apple",
                            "red fruit, keeps the doctor away.",
                            1.50,
                            30);

    Product cookies(        "3",
                            "Cookies",
                            "fresh sweets, chocolate chips, and baked fresh daily",
                            3.25,
                            12);

    Product milk(           "4",
                            "Milk",
                            "Lots of protein and calcium, keeps your bones strong",
                            2.50,
                            40);

    Product beer(           "5",
                            "Beer",
                            "Craft selections changed out weekly, extra hops for you!",
                            6.50,
                            6);

    Product iceCream(       "6",
                            "Ice Cream",
                            "Great on a hot day, frozen desserts churned daily",
                            3.50,
                            15);

    Product bread(          "7",
                            "Bread",
                            "Baked daily. Soft, whole-grain loafs.",
                            4.25,
                            2);

    Product redBlender(     "8",
                            "Red Blender",
                            "Sturdy blender perfect for making smoothies and sauces",
                            350,
                            1);

    Product hotAirBalloon(  "9",
                            "Hot Air Balloon",
                            "Fly into the sky in your own balloon - comes in red, blue or chartreuse",
                            700,
                            1);

    Product giantRobot(     "10",
                            "Giant Robot",
                            "Pierce the heavens with your drill in this glorious robot! Size may vary",
                            7000,
                            1);

    Product liveGoat(       "11",
                            "Live Goat",
                            "Yes, you read this right. One live goat. Take it, it eats everything",
                            1,
                            0);

    Product oakTable(       "12",
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
    Customer shaun(     "Shaun",    "9", false);
    Customer brendan(   "Brendan",  "10", true);

    // Add members to the store roster
    testStore.addMember(&danny);
    testStore.addMember(&todd);
    testStore.addMember(&chase);
    testStore.addMember(&kyle);
    testStore.addMember(&travis);
    testStore.addMember(&doug);
    testStore.addMember(&haley);
    testStore.addMember(&andy);
    testStore.addMember(&shaun);
    testStore.addMember(&brendan);




    /*********************************************
     *          STORE FUNCTIONALITY
     *********************************************/
    std::cout << "****************************************" << std::endl;
    std::cout << "*             TESTER STORE            *" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "Welcome to Tester Store, Home of products!" << std::endl;
    std::cout << "\nWhat can we help you out with today?" << std::endl;


    int entrance;
    do {
        std::cout << "  1) New Member Signup" << std::endl;
        std::cout << "  2) Returning Customer" << std::endl;


        std::cin >> entrance;
        if (entrance <= 0 || entrance >= 3)
        {
            std::cout << "Did not recognize that input, please try again. Here are you options:" << std::endl;
        }

    } while (entrance != 1 && entrance != 2);

    // If it is a new member signup
    if (entrance == 1)
    {
        std::cout << "Type in the name, member id, and if you are a premium member (1 or 0) (seprate by spaces)" << std::endl;
        std::string newName;
        std::cin >> newName;

        std::string newMemberID;
        std::cin >> newMemberID;

        bool newPremium;
        std::cin >> newPremium;

        testStore.addMember(new Customer(newName, newMemberID, newPremium));

        std::cout << "Member #" << newMemberID << " registered for store membership.  Thank you!" << std::endl;
    }

    // Ask for user ID and make sure they are apart of the membership.
    std::cout << "Thank you for choosing Test Store, type in your membership ID:";

    std::string currUser;
    std::cin >> currUser;

    Customer *currentCust;
    currentCust = testStore.getMemberFromID(currUser);

    // Check to see if the user is in the system
    if (currentCust == NULL)
    {
        std::cout << "I'm sorry, you don't appear to be registered, come back once you're a member.";
        return 0;
    }
    else
    {
        std::cout << "Welcome #" << currentCust->getAccountID() << " what would you like to do?\n";

        int response = 0;
        do
        {
            std::cout << "  1) Search for a product"    << std::endl;
            std::cout << "  2) Add product by known ID" << std::endl;
            std::cout << "  3) View current cart"       << std::endl;
            std::cout << "  4) Empty Cart"              << std::endl;
            std::cout << "  5) Checkout"                << std::endl;
            std::cout << "  6) Quit"                    << std::endl;

            std::cin >> response;

            // Variables needed for the switch below
            std::string wordSearch;
            std::string currProduct;

            switch(response) {
                // User Selected to search for items
                case 1:
                    std::cout << "Give us word to search for in our inventory: ";
                    std::cin >> wordSearch;
                    testStore.productSearch(wordSearch);
                    break;

                    // User selected to add an item to their cart
                case 2:
                    std::cout << "Type in the product ID of the item you would like to add: ";
                    std::cin >> currProduct;
                    testStore.addProductToMemberCart(currProduct, currUser);
                    break;

                    // User selected to view the items currently in their cart
                case 3: {
                            std::vector<std::string> currCart = currentCust->getCart();

                            for (int i = 0; i < currentCust->getCart().size(); i++)
                            {
                                std::cout << testStore.getProductFromID(currCart.at(i))->getTitle()
                                          << " -  ID: #" << testStore.getProductFromID(currCart.at(i))->getIdCode()
                                          <<  std::endl;
                            }
                        }
                        break;

                // User selected to Empty their cart
                case 4:
                        currentCust->emptyCart();
                        std::cout << "Cart is empty, now keep shopping!" << std::endl;
                        break;

                // User selected to Checkout
                case 5: std::cout << "Checking out customer #" << currUser << "." << std::endl;
                        testStore.checkOutMember(currUser);
                        std::cout << "Thank you and have a great day!" << std::endl;
                        return 0;

                // User selected to leave store
                case 6: std::cout << "Now leaving Tester Store, have a great day!" << std::endl;
                        return 0;

                // Unknown response added
                default: std::cout << "I do not recognize that request, look at the options and try again." << std::endl;
                         break;
            }
        }while(response != 6);
    }
    return 0;
}