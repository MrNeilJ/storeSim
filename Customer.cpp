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
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
Customer::Customer(std::string n, std::string a, bool pm) {

}

/**************************************************************
 *                  Customer::getAccountID
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
std::string Customer::getAccountID() {
    return std::string();
}

/**************************************************************
 *                  Customer::getCart
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
std::vector<std::string> Customer::getCart() {
    return std::vector<std::string>();
}

/**************************************************************
 *                  Customer::addProductToCart
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
void Customer::addProductToCart(std::string) {

}

/**************************************************************
 *                  Customer::isPremiumMember
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
bool Customer::isPremiumMember() {
    return false;
}

/**************************************************************
 *                  Customer::emptyCart
 * Description: Constructor for the class to allow the user
 * to build a blank table 3 x 3 array
**************************************************************/
void Customer::emptyCart() {

}
