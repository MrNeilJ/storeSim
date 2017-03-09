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

#include "Customer.hpp"

/**************************************************************
 *                  Customer::Customer
 * Description: takes as parameters three values with which to
 * initialize the Customer's name, account ID, and whether the
 * customer is a premium member
**************************************************************/
Customer::Customer(std::string n, std::string a, bool pm) {

}

/**************************************************************
 *                  Customer::getAccountID
 * Description: return the value of the corresponding data
 * member
**************************************************************/
std::string Customer::getAccountID() {
    return std::string();
}

/**************************************************************
 *                  Customer::getCart
 * Description: return the value of the corresponding data
 * member
**************************************************************/
std::vector<std::string> Customer::getCart() {
    return std::vector<std::string>();
}

/**************************************************************
 *                  Customer::addProductToCart
 * Description: adds the product ID code to the Customer's
 * cart
**************************************************************/
void Customer::addProductToCart(std::string) {

}

/**************************************************************
 *                  Customer::isPremiumMember
 * Description: returns whether the customer is a premium
 * member
**************************************************************/
bool Customer::isPremiumMember() {
    return false;
}

/**************************************************************
 *                  Customer::emptyCart
 * Description: empties the Customer's cart
**************************************************************/
void Customer::emptyCart() {

}
