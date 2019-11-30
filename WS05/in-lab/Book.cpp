// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			11-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds {

  // Default constructor. Sets the object into a safe empty state
  Book::Book(){

    b_author = "";
    b_title = "";
    b_country = "";
    b_summary = "";

    b_price = 0.0f;
    b_year = 0;

  } // Book::Book()

  // Constructor that receives a string with book information.
  // Retrieves the book info from the string and store them in the object.
  Book::Book(const std::string & str_book){

    size_t count = 0, previous = 0, current = str_book.find(','); // Temp variables to get the tokens.
    std::string tokens[6]; // Temporary variable to hold values from token string

    // Search the string for ',' characters
    if(current > 0){

      // Extract substrings from the tokens string until it reaches the second last
      while(count < 5){

        tokens[count] = str_book.substr(previous, current - previous); // Capture the token before the ',' delimiter

        tokens[count] = trim(tokens[count]); // Trim the white spaces from the token

        previous = current + 1; // Tells where to begin the next substr
        current = str_book.find(',', previous); // Tells where to end the next substr

        count++;

      } // while()

      // The last token may contain comma characters ',', so manually extract it from the string.
      tokens[5] = str_book.substr(previous);
      tokens[5] = trim(tokens[5]);

      // Populate the object
      b_author = tokens[0];
      b_title = tokens[1];
      b_country = tokens[2];
      b_price = std::stod(tokens[3]);
      b_year = std::stoi(tokens[4]);
      b_summary = tokens[5];

    } // if (current > 0)

  } // Book::Book(const std::string &)

  // Query that returns the book title
  const std::string & Book::title() const{

    return b_title;

  } // const std::string & Book::title() const

  // Query that returns the book country
  const std::string & Book::country() const{

    return b_country;

  } // const std::string & Book::country() const

  // Query that returns the book year of publication
  const size_t & Book::year() const{

    return b_year;

  } // const size_t & Book::year() const

  // Returns the price by reference (allows modification)
  double & Book::price(){

    return b_price;

  } // double & Book::price()

  // Friend Helpers

  // Friend helper that inserts the content of the object into the output stream
  std::ostream & operator<<(std::ostream & os, const Book & book){

    os
      << std::setw(20) << book.b_author << " | "
      << std::setw(22) << book.b_title << " | "
      << std::setw( 5) << book.b_country << " | "
      << std::setw( 4) << book.b_year << " | "
      << std::setw( 6) << std::fixed << std::setprecision(2) << book.b_price << " | "
      << book.b_summary << std::endl;

    return os;

  } // std::ostream & operator<<(std::ostream &, const Book &)

  // Free Helpers

  // Trim all white spaces from the beginning and end of a string.
  std::string & trim(std::string & str_to_trim, const std::string & trim_chars) {

    str_to_trim.erase(0, str_to_trim.find_first_not_of(trim_chars)); // Remove all spaces from the beginning of the string.

    str_to_trim.erase(str_to_trim.find_last_not_of(trim_chars) + 1); // Remove all spaces from the end of the string.

    return str_to_trim; // Returns the trimmed string

  } // trim()

} // namespace sdds
