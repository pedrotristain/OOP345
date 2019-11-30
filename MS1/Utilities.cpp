// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			12-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include<string>
#include<iostream>
#include "Utilities.h"

char Utilities::m_delimiter = ',';


// Sets the field width (m_widthField) of the current object.
void Utilities::setFieldWidth(size_t _new_field_width){

  m_widthField = _new_field_width;

} // void Utilities::setFieldWidth(size_t)

// Query function that returns the field width (m_widthField).
size_t Utilities::getFieldWidth() const{

  return m_widthField;

} // size_t Utilities::getFieldWidth() const

// Extract tokens from the first parameter.
const std::string Utilities::extractToken(const std::string & _extract_str, size_t & _next_pos, bool & _more){

  // Control variables for exctracting tokens.
  size_t start = _next_pos, end = 0; 

  // Return variable that will hold and extracted token.
  std::string token;

  // Set the end position to the index of the next delimiter.
  end = _extract_str.find(m_delimiter, start);

  // If there are 2 delimiters and no token between them, throw error
  if(start == end)
    throw "ERROR";

  // Check if the delimiter was found. If true, extract the token.
  else {

    // Sets the parameter 'more' to TRUE
    _more = true;

    // Sets the next position to the end + 1
    _next_pos = end + 1;

    // Extract the token and store it into the return variable 'token'
    token = _extract_str.substr(start, end - start);

    // If the token length is greater than the current field width, update it to the token length. Ignores the last token (DESCRIPTION)
    if(m_widthField < token.length() && end != std::string::npos)
      setFieldWidth(token.length());

  } // if( != )


  // Return extracted token
  return token;

} // const std::string Utilities::extractToken(const std::string &, size_t &, bool &)

// Sets the delimiter for this class (static duration).
void Utilities::setDelimiter(const char _new_delimiter){

  Utilities::m_delimiter = _new_delimiter;

} // void Utilities::setDelimiter(const char)

// Query function that returns the set delimiter.
const char Utilities::getDelimiter() const{

  return Utilities::m_delimiter;

} // const char Utilities::getDelimiter() const