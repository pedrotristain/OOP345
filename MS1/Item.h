// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			12-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>


class Item {

  // Name of the item
  std::string m_name;

  // Description of the item
  std::string m_description;

  // Holds the next serial number to be assigned on the assembly line.
  unsigned int m_serialNumber;

  // The quantity of current items in stock
  unsigned int m_quantity;

  // The maximum characters to be displayed for a field
  static size_t m_widthField;

public:

  // 1 parameter constructor. Receives an string with tokens with the items data to be extracted.
  Item(const std::string);

  // Query function that returns the name (m_name) of current object
  const std::string & getName() const;

  // Returns next serial number (m_serialNumber) to be used by assembly line and increments it.
  const unsigned int getSerialNumber();

  // Returns the remaining quantity (m_quantity) of the current item
  const unsigned int getQuantity();

  // Subtracts 1 from current quantity (m_quantity). Should not go below 0
  void updateQuantity();

  // Inserts the contet of the current object into the output stream
  void display(std::ostream &, bool);

}; // class Item

// Free Helpers

// // Trim all white spaces from the beginning and end of a string.
// std::string & trim(std::string &, const std::string & = " ");

// // Free helper that add a song to the output stream.
// std::ostream & operator<<(std::ostream & os, const Song &);

// std::string intToTime(int); // Converts an integer into Time


#endif
