// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			12-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>


class Utilities {

  // Specify the length of the token.
  size_t m_widthField = 1; 

  // Delimiter that separates the tokens.
  static char m_delimiter;

public:
  
  // Default constructor. Sets the field width to 1
  Utilities() : m_widthField(1) { };

  // Sets the field width (m_widthField) of the current object.
  void setFieldWidth(size_t);

  // Query function that returns the field width (m_widthField).
  size_t getFieldWidth() const; 

  // Extract tokens from the first parameter.
  const std::string extractToken(const std::string &, size_t &, bool &);

  // Sets the delimiter for this class (static duration).
  static void setDelimiter(const char);

  // Query function that returns the set delimiter.
  const char getDelimiter() const;
  
}; // class Utilities

// Free Helpers

// // Trim all white spaces from the beginning and end of a string.
// std::string & trim(std::string &, const std::string & = " ");

// // Free helper that add a song to the output stream.
// std::ostream & operator<<(std::ostream & os, const Song &);

// std::string intToTime(int); // Converts an integer into Time

#endif
