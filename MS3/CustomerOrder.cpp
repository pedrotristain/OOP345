// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			24-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"
#include "Utilities.h"
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 1;

// Default constructor. Initiates the object in a empty safe state
CustomerOrder::CustomerOrder(){

  m_name = "";
  m_product = "";
  m_cntItem = 0;
  m_lstItem = nullptr;

} // CustomerOrder::CustomerOrder()

// 1 parameter constructor
// Receieves a single record from the input file and uses an 'Utilities' to extract the tokens.
CustomerOrder::CustomerOrder(std::string _tokens_str){

  // Control variables to extract tokens from the received string
  Utilities util;
  std::vector<std::string> tokens;
  size_t x = 0, start_pos = 0;
  bool more = false;

  // Extract all tokens from the string
  do {

    tokens.push_back( util.extractToken(_tokens_str, start_pos, more) );
    x++;

  } while(more);

  // Set the item count to be equal to the number of tokens minus 2 (for the customer and product name)
  m_cntItem = tokens.size() - 2;

  // Initialize the list of 'ItemInfos' dynamically
  m_lstItem = new ItemInfo * [m_cntItem];

  // Populate the object with the extracted data
  for(size_t x = 0; x < tokens.size(); x++ ){

    // If x == 0, the extracted token is the name of the customer
    if(x == 0){
      m_name = tokens[x];
    }

    // If x == 1, the extracted token is the name of the product
    else if (x == 1) {
      m_product = tokens[x];
    }

    // If x > 1, the extracted token is all the pieces to be assembled
    else {
      m_lstItem[x - 2] = new ItemInfo(tokens[x]); //(tokens[x]);
    }

  } // for()

  // Set the field width to the max between CustomerOrder::m_widthField and Utilities::m_widthField
  m_widthField =
    (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();

} // CustomerOrder::CustomerOrder(std::string)

// Copy constructor should throw an exception
CustomerOrder::CustomerOrder(const CustomerOrder & _co){

  throw "ERROR";

} // CustomerOrder::CustomerOrder(const CustomerOrder &)

// Move constructor
CustomerOrder::CustomerOrder(CustomerOrder && _co) noexcept{

  * this = std::move(_co);

} // CustomerOrder::CustomerOrder(const CustomerOrder &&) noexcept

// Destructor
CustomerOrder::~CustomerOrder(){

  delete [] m_lstItem;

} // CustomerOrder::~CustomerOrder()

// Move assign operator
CustomerOrder & CustomerOrder::operator=(CustomerOrder && _co){

  if( this != & _co ){

    m_name = _co.m_name;
    m_product = _co.m_product;
    m_cntItem = _co.m_cntItem;
    m_lstItem = _co.m_lstItem;

    _co.m_name = "";
    _co.m_product = "";
    _co.m_cntItem = 0;
    _co.m_lstItem = nullptr;

  } // if()

  return * this;

} // CustomerOrder & CustomerOrder::operator=(const CustomerOrder &&)

// Query function that returns 'ItemInfo::m_fillState' of the item specified as parameter
bool CustomerOrder::getItemFillState(std::string _item_name) const{

  // Control variables.
  // 'is_filled' will return the filled state if found
  // 'item_found' tells if the item was found
  bool is_filled = false, item_found = false;

  for(size_t x = 0; x < m_cntItem; x++){

    if( m_lstItem[x]->m_itemName == _item_name ){

      is_filled = m_lstItem[x]->m_fillState;
      item_found = true;

    } // if()

  } // for()

  // If the item doesn't exist in the order, return true
  if(!item_found)
    is_filled = true;

  return is_filled;

} // bool CustomerOrder::getItemFillState(std::string) const

// Query string that returns 'true' if all the items have been filled or 'false' otherwise
bool CustomerOrder::getOrderFillState() const{

  // Control variable.
  // 'is_filled' will return TRUE if all items are filled or FALSE otherwise
  bool is_filled = true;

  for(size_t x = 0; x < m_cntItem; x++){

    if( !m_lstItem[x]->m_fillState ){

      is_filled = false;

    } // if()

  } // for()

  return is_filled;

} // bool CustomerOrder::getOrderFillState() const

// Attempts to fill the current item and prints a message regarding the result
void CustomerOrder::fillItem(Item & _item, std::ostream & os){

  // Iterate through all items in the order looking for a match with the '_item' parameter
  for(size_t x = 0; x < m_cntItem; x++){

    // If a match is found, proceed. Otherwise, this functions does nothing
    if( m_lstItem[x]->m_itemName == _item.getName() ){

      // Checks if  inventory contains at least one unit of the item
      if( _item.getQuantity() > 0 ){

        // Subtracts 1 from the quantity.
        _item.updateQuantity();

        // If TRUE, subtract 1 from the inventory and updates ItemInfo::m_serialNumber and ItemInfo::m_fillState
        m_lstItem[x]->m_serialNumber = _item.getSerialNumber();
        m_lstItem[x]->m_fillState = true;

        // Print a message to the screen confirming the item has been filled
        os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[x]->m_itemName << "]" << std::endl;

      } else {

        // If item is full but inventory is empty:
        // Print a message to the screen confirming the item has been filled
        os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[x]->m_itemName << "]" << std::endl;

      } // if (not empty)

    } // if(found)

  } // for()

} // void CustomerOrder::fillItem(Item &, std::ostream &)

// Query function that inserts the current object in the output stream in a formated way
void CustomerOrder::display(std::ostream & os) const{

  os
    << m_name << " - " << m_product << std::endl;

    for(size_t x = 0; x < m_cntItem; x++){

      os
        << "["
        << std::setw(6) << std::right << std::setfill('0') << m_lstItem[x]->m_serialNumber
        << "] " << std::left
        << std::setfill(' ') << std::setw(CustomerOrder::m_widthField) << m_lstItem[x]->m_itemName << " - "
        << ((m_lstItem[x]->m_fillState) ? "FILLED" : "MISSING") << std::endl;

    } // for()

} // void CustomerOrder::display(std::ostream &) const
