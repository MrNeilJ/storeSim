/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.10.2017
 *
 * Description: This file hosts the member functions of the
 * Store class.  This hosts the main functionality of the
 * application.  Here the previously created items and members
 * can be added to a single Store class.  We can freely search
 * store inventory, empty user carts, and even check individual
 * customers out with the various member functions hosted in
 * this Store class.
**************************************************************/

#include "Store.hpp"
#include <iostream>

/**************************************************************
 *                  Store::addProduct
 * Description: adds a product to the inventory of the store
**************************************************************/
void Store::addProduct(Product *p) {
    inventory.push_back(p);
}

/**************************************************************
 *                  Store::addMember
 * Description: adds a customer to the members of the store
**************************************************************/
void Store::addMember(Customer *c) {
    members.push_back(c);
}

/**************************************************************
 *                  Store::getProductFromID
 * Description: returns pointer to product with matching ID.
 * Returns NULL if no matching ID is found.
**************************************************************/
Product *Store::getProductFromID(std::string item) {
    // Search through the exact amount of inventory items at that moment
    for(int i = 0; i < inventory.size(); i++)
    {
        // If the item code matches on in our inventory, return a pointer to it
        if (item == inventory[i]->getIdCode())
        {
            return inventory[i];
        }
    }
    return NULL;
}

/**************************************************************
 *                  Store::getMemberFromID
 * Description: returns pointer to customer with matching ID.
 * Returns NULL if no matching ID is found.
**************************************************************/
Customer *Store::getMemberFromID(std::string cx) {
    // Search through the exact amount of currently registered members
    for(int i = 0; i < members.size(); i++)
    {
        // If the current member search ID is equivalent to the customer query
        if (cx == members[i]->getAccountID())
        {
            // return the pointer to that member
            return members[i];
        }
    }
    return NULL;
}

/**************************************************************
 *                  Store::productSearch
 * Description:  for every product whose title or description
 * contains the search string, prints out that product's title,
 * ID code, price and description.  The first letter of the
 * search string should be case-insensitive, i.e. a search for
 * "wood" should match Products that have "Wood" in their title
 * or description, and a search for "Wood" should match
 * Products that have "wood" in their title or description.
**************************************************************/
void Store::productSearch(std::string str) {
    // Set an exists boolean variable to check the items is in inventory
    bool exists = false;

    // Save the current size of the inventory
    double invSize = inventory.size();

    for (int i = 0; i < invSize; i++)
    {
        // Set the first letter to a lower case in the title
        std::string itemTitle = inventory.at(i)->getTitle();
        itemTitle[0] = tolower(itemTitle[0]);

        // Set the first letter to a lower case in the description
        std::string itemDesc = inventory.at(i)->getDescription();
        itemDesc[0] = tolower(itemDesc[0]);

        // Set the first letter to a lower case in the search term
        str[0] = tolower(str[0]);


        // Utilized the find function learned of npos from the .find() man pages
        if (itemTitle.find(str)!=std::string::npos || itemDesc.find(str)!=std::string::npos)
        {
            exists = true;
            std::cout << "Item:        " << inventory[i]->getTitle()  << std::endl;
            std::cout << "ID Code:     " << inventory[i]->getIdCode() << std::endl;
            std::cout << "Price:       " << inventory[i]->getPrice()  << std::endl;
            std::cout << "Description: " << inventory[i]->getDescription() << std::endl;
            std::cout << "\n";
        }
    }
    // If the product is not found in inventory, alert the user.
    if (!exists)
    {
        std::cout << "There are no items that match this search. Try again!\n" << std::endl;
    }
}

/**************************************************************
 *                  Store::addProductToMemberCart
 * Description: If the product isn't found in the inventory,
 * print "Product #[idCode goes here] not found."  If the
 * member isn't found in the members, print "Member #[accountID
 * goes here] not found."  If both are found and the product is
 * still available, calls the member's addProductToCart method.
 * Otherwise it prints "Sorry, product #[idCode goes here] is
 * currently out of stock."  The same product can be added
 * multiple times if the customer wants more than one of
 * something.
**************************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID) {
    // Variables needed to keep track on items and assist with readability
    bool inStore   = false;
    bool inMember  = false;
    bool inStock   = false;
    int itemLocation = -1;
    int memberLocation = -1;
    double invSize    = inventory.size();
    double memberSize = members.size();

    // Check if item is in the store
    for (int i = 0; i < invSize; i++)
    {
        // If we are able to find the item, mark inStore as true and save it's location
        if (inventory[i]->getIdCode() == pID)
        {
            inStore = true;
            itemLocation = i;

            // Check if the item is in stock
            if (inventory[i]->getQuantityAvailable() > 0)
            {
                inStock = true;
            }
        }
    }
    // Check if individual is a member
    for (int j = 0; j < memberSize; j++)
    {
        if (members[j]->getAccountID() == mID)
        {
            inMember = true;
            memberLocation = j;
        }
    }
    // Check to make sure they are a member, the item is in stock, and we have the item
    if (inMember && inStock && inStore)
    {
       members[memberLocation]->addProductToCart(pID);
    }
    // Check to see if the customer is a member
    else if (!inMember)
    {
        std::cout << "Sorry you are not a member." << std::endl;
    }
    // Check to see if the item is actually in inventory
    else if (!inStore)
    {
        std::cout << "Sorry, the item you are looking for is not in our store" << std::endl;
    }
    // Check to see if they are a member, the item is in store, and that the item is out of stock
    else if (!inStock)
    {
        std::cout   << "Sorry, product #" << inventory[itemLocation]->getIdCode()
                    << " is currently out of stock." << std::endl;
    }
    // Just a fallback if it misses everything...somehow
    else
    {
        std::cout << "Sorry, an error has occurred, try again." << std::endl;
    }

}

/**************************************************************
 *                  Store::checkOutMember
 * Description: If the member isn't found in the members, print
 * "Member #[accountID goes here] not found."  Otherwise prints
 * out the title and price for each product in the cart and
 * decreases the available quantity of that product by 1.  If
 * any product has already sold out, then on that line it
 * should print 'Sorry, product #[idCode goes here], "[product
 * name goes here]", is no longer available.'  At the bottom it
 * should print out the subtotal for the cart, the shipping
 * cost ($0 for premium members, 7% of the cart cost for
 * normal members), and the final total cost for the cart
 * (subtotal plus shipping).  If the cart is empty, it should
 * just print "There are no items in the cart."  When the
 * calculations are complete, the member's cart should be
 * emptied.
**************************************************************/
void Store::checkOutMember(std::string mID)
{
    // Variables needed for function functionality
    // Amount of members
    int memberSize = members.size();
    // Found the Member
    bool exists = false;
    // Variable to hold the total cart value
    double totalCost = 0;
    // Variable to hold the end cost of shipping
    double shipping = 0;

    // Loop through members to see if the inputted member is in it
    for (int i = 0; i < memberSize; i++)
    {
        // If the member in the store matches the current member search mark as true.
        if (members[i]->getAccountID() == mID) {
            exists = true;

            // Pull the size of that current users cart
            double cartSize = members[i]->getCart().size();

            // If there are no items in the cart, let the user know
            if (cartSize == 0)
            {
                std::cout << "There are no items in the cart." << std::endl;
            }
            else
            {
                // Select each cart item
                for (int j = 0; j < cartSize; j++)
                {
                    // Search through entire inventory for matching item
                    for (int k = 0; k < inventory.size(); k++)
                    {
                        // When we find a matching item...
                        if (inventory.at(k)->getIdCode() == members[i]->getCart().at(j))
                        {
                            // Check to see if it is in stock, if not let customer know
                            if (inventory.at(k)->getQuantityAvailable() < 1)
                            {
                                std::cout << "Sorry, product #" << inventory.at(k)->getIdCode()
                                          << ", " << inventory.at(k)->getTitle() << " is no longer available"
                                          << std::endl;
                            }
                            // Otherwise print out name and price and add it to total
                            else
                            {
                                std::cout << inventory.at(k)->getTitle() << " - "
                                          << inventory.at(k)->getPrice() << std::endl;

                                // Add price to total and decrease quantity
                                totalCost += inventory.at(k)->getPrice();
                                inventory.at(k)->decreaseQuantity();
                            }
                        }
                    }
                }
                // Check to see if the user is a premium member and link respective shipping costs
                if (members[i]->isPremiumMember())
                {
                    shipping = 0;
                } else
                {
                    shipping = totalCost * 0.07;
                }

                // Print out the subtotal and shipping for the user
                std::cout << "===========================================" << std::endl;
                std::cout << "Subtotal: " << totalCost << std::endl;
                std::cout << "Shipping: " << shipping << std::endl;
                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "Total:    " << totalCost + shipping << std::endl;

                // Empty the cart once done
                members[i]->emptyCart();
            }
        }
    }
    // If the member does not exist, then let the user know they couldn't be found
    if (!exists)
    {
        std::cout << "Member #" << mID << " not found." << std::endl;
    }
}



