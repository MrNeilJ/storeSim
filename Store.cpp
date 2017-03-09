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

/**************************************************************
 *                  Store::addProduct
 * Description: adds a product to the inventory
**************************************************************/
void Store::addProduct(Product *p) {
    inventory.push_back(p);
}

/**************************************************************
 *                  Store::addMember
 * Description: adds a customer to the members
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
    for(int i = 0; i < inventory.size(); i++)
    {
        if (item == inventory[i]->getIdCode())
        {
            return *(inventory[i]);
        }
    }
}

/**************************************************************
 *                  Store::getMemberFromID
 * Description: returns pointer to customer with matching ID.
 * Returns NULL if no matching ID is found.
**************************************************************/
Customer *Store::getMemberFromID(std::string cust) {
    for(int i = 0; i < members.size(); i++)
    {
        if (cust == members[i]->getAccountID())
        {
            return *(members[i]);
        }
    }
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
    int wordLen = str.length();
    int counter = 0;
    for (int i = 0; i < inventory.size(); i++)
    {
        for(int j = 0; j < inventory[i]->getDescription().length(); j++)
        {
            if (inventory[i]->getDescription().at(j) == str.at(counter))
            {
                counter++;
            }

            else if(inventory[i]->getDescription().at(j) != str.at(counter) && counter >= 1)
            {
                counter = 0;
            }
        }
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
void Store::checkOutMember(std::string mID) {

}



