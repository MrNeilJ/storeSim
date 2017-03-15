/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.10.2017
 *
 * Description: This file hosts the member functions of the
 * Customer class. This allows the user to create customers
 * and associate personal information to them.  This includes
 * a name, ID# and status of their membership.  This information
 * is all retrievable with the associated getter functions.
**************************************************************/

#include "Customer.hpp"

/**************************************************************
 *                  Customer::Customer
 * Description: takes as parameters three values with which to
 * initialize the Customer's name, account ID, and whether the
 * customer is a premium member.
**************************************************************/
Customer::Customer(std::string n, std::string a, bool pm) {
    name            = n;
    accountID       = a;
    premiumMember   = pm;
}

/**************************************************************
 *                  Customer::getAccountID
 * Description: returns the values stored in that Customer's
 * AccountID variable.
**************************************************************/
std::string Customer::getAccountID() {
    return accountID;
}

/**************************************************************
 *                  Customer::getCart
 * Description: return the value stored in taht Customer's
 * Cart variable.
**************************************************************/
std::vector<std::string> Customer::getCart() {
    return cart;
}

/**************************************************************
 *                  Customer::addProductToCart
 * Description: adds the product ID code (as a string) to the
 * Customer's personal cart.
**************************************************************/
void Customer::addProductToCart(std::string item) {
    cart.push_back(item);
}

/**************************************************************
 *                  Customer::isPremiumMember
 * Description: retruns a boolean value that checks if the user
 * is registered as a premium member.
**************************************************************/
bool Customer::isPremiumMember() {
    // Check to see if the user is a premium member, if so return true.
    if (premiumMember)
    {
        return true;
    }
    // Else return false
    else
    {
        return false;
    }
}

/**************************************************************
 *                  Customer::emptyCart
 * Description: removes all of the items in that Customer's
 * cart.
**************************************************************/
void Customer::emptyCart() {
    cart.clear();
}
