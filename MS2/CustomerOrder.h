// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			24-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include <iostream>
#include "Item.h"


struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

  // Name of the customer
  std::string m_name;

  // Name of the product being assembled
  std::string m_product;

  // Count of the number of the items for the customer's order
  unsigned int m_cntItem;

  // Dynamically allocated list of objects of type 'ItemInfo'
  ItemInfo** m_lstItem;

  // The maximum characters to be displayed for a field
  static size_t m_widthField;

public:

  // Default constructor
  CustomerOrder();

  // 1 parameter constructor
  CustomerOrder(std::string);

  // Copy constructor should throw an exception
  CustomerOrder(const CustomerOrder &);

  // Move constructor
  CustomerOrder(CustomerOrder &&) noexcept;

  // Destructor
  ~CustomerOrder();

  // Move assign operator
  CustomerOrder & operator=(CustomerOrder &&);

  // Delete copy operator
  CustomerOrder & operator=(const CustomerOrder &) = delete;

  // Query function that returns 'ItemInfo::m_fillState' of the item specified as parameter
  bool getItemFillState(std::string) const;

  // Query string that returns 'true' if all the items have been filled or 'false' otherwise
  bool getOrderFillState() const;

  // Attempts to fill the current item and prints a message regarding the result
  void fillItem(Item &, std::ostream &);

  // Query function that inserts the current object in the output stream in a formated way
  void display(std::ostream &) const;

}; // class CustomerOrder

#endif
