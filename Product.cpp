/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 3.10.2017
 *
 * Description: This file hosts the member functions of the
 * Product class.  This allows the user to register products
 * with a name, id #, short description of the item, price
 * and even how many items it has.  The user can then get
 * this information returned to them and even decrease the
 * quantity available after creation.
**************************************************************/

#include "Product.hpp"


/**************************************************************
 *                  Product::Product
 * Description: takes as parameters five values with which to
 * initialize the Product's idCode, title, description, price,
 * and quantity available
**************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa) {
    idCode              = id;
    title               = t;
    description         = d;
    price               = p;
    quantityAvailable   = qa;

}

/**************************************************************
 *                  Product::getIDCode
 * Description: return the value stored within that Product's
 * ID Code Variable.
**************************************************************/
std::string Product::getIdCode() {
    return idCode;
}

/**************************************************************
 *                  Product::getTitle
 * Description: return the value within that Product's Title
 * Variable.
**************************************************************/
std::string Product::getTitle() {
    return title;
}

/**************************************************************
 *                  Product::getDescription
 * Description: return the value stored within that Product's
 * Description Variable.
**************************************************************/
std::string Product::getDescription() {
    return description;
}

/**************************************************************
 *                  Product::getPrice
 * Description: return the value stored within tha Product's
 * Price Variable.
**************************************************************/
double Product::getPrice() {
    return price;
}

/**************************************************************
 *                  Product::getQuantityAvailable
 * Description: return the value stored within that Product's
 * Quantity Available Variable.
**************************************************************/
int Product::getQuantityAvailable() {
    return quantityAvailable;
}

/**************************************************************
 *                  Product::decreaseQuantity
 * Description: decreases the quantity available by one within
 * that Product.
**************************************************************/
void Product::decreaseQuantity() {
    quantityAvailable --;
}
