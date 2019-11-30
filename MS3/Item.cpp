// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			12-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>

#include "Item.h"
#include "Utilities.h"


size_t Item::m_widthField = 1;

// 1 parameter constructor. Receives an string with tokens with the items data to be extracted.
Item::Item(const std::string _tokens_str){

  // Control variables to extract tokens from the received string
  Utilities util;
  std::string tokens[4];
  size_t x = 0, start_pos = 0;
  bool more = false;

  // Extract all tokens from the string
  do {
    
    tokens[x] = util.extractToken(_tokens_str, start_pos, more);
    x++;

  } while(more && x <4);

  // Populate the object with the extracted data
  m_name = tokens[0];
  m_serialNumber = std::stoi(tokens[1]);
  m_quantity = std::stoi(tokens[2]);
  m_description = tokens[3];

  // Set the field width to the max between Item::m_widthField and Utilities::m_widthField
  m_widthField = 
    (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();

} // Item::Item(const std::string)

// Query function that returns the name (m_name) of current object
const std::string & Item::getName() const{

  return m_name;

} // const std::string & Item::getName() const{

// Returns next serial number (m_serialNumber) to be used by assembly line and increments it.
const unsigned int Item::getSerialNumber(){

  return m_serialNumber++;

} // const unsigned int Item::getSerialNumber()

// Returns the remaining quantity (m_quantity) of the current item
const unsigned int Item::getQuantity(){

  return m_quantity;

} // const unsigned int Item::getQuantity()

// Subtracts 1 from current quantity (m_quantity). Should not go below 0
void Item::updateQuantity(){

  // If quantity is greater than 0, decreament it by 1
  if(m_quantity > 0)
    m_quantity--;

} // void Item::updateQuantity()

// Inserts the contet of the current object into the output stream
// If '_full' is TRUE, insert all data into the output stream
// If '_full' is FALSE, insert only the name and serial number in the os
void Item::display(std::ostream & os, bool _full) const {

  // Insert the name and serial number in the output stream
  os 
      << std::left << std::setw(m_widthField) << m_name
      << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << "]"
      << std::left << std::setfill(' ');

  // If '_full' is TRUE, also insert the quantity and description
  if(_full){

    os
      << " Quantity: " << std::setw(m_widthField) << m_quantity
      << " Description: " << m_description;
    
  } // if( _full )

  // Add line break at the end of the record
  os << std::endl;

} // void Item::display(std::ostream &, bool)

