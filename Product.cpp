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

#include "Product.hpp"


/**************************************************************
 *                  Product::Product
 * Description: takes as parameters five values with which to
 * initialize the Product's idCode, title, description, price,
 * and quantity available
**************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa) {

}

/**************************************************************
 *                  Product::getIDCode
 * Description: return the value of the corresponding data
 * member
**************************************************************/
std::string Product::getIdCode() {
    return std::string();
}

/**************************************************************
 *                  Product::getTitle
 * Description: return the value of the corresponding data
 * member
**************************************************************/
std::string Product::getTitle() {
    return std::string();
}

/**************************************************************
 *                  Product::getDescription
 * Description: return the value of the corresponding data
 * member
**************************************************************/
std::string Product::getDescription() {
    return std::string();
}

/**************************************************************
 *                  Product::getPrice
 * Description: return the value of the corresponding data
 * member
**************************************************************/
double Product::getPrice() {
    return 0;
}

/**************************************************************
 *                  Product::getQuantityAvailable
 * Description: return the value of the corresponding data
 * member
**************************************************************/
int Product::getQuantityAvailable() {
    return 0;
}

/**************************************************************
 *                  Product::decreaseQuantity
 * Description: decreases the quantity available by one
**************************************************************/
void Product::decreaseQuantity() {

}
