// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			11-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {

  class Book {

    std::string b_author;
    std::string b_title;
    std::string b_country;
    std::string b_summary;

    size_t b_year;
    double b_price;

  public:

    Book(); // Default constructor

    Book(const std::string &); // Constructor that receives a string with book information.

    const std::string & title() const; // Query that returns the book title

    const std::string & country() const; // Query that returns the book country

    const size_t & year() const; // Query that returns the book year of publication

    double & price(); // Returns the price by reference (allows modification)

  private:

    friend std::ostream & operator<<(std::ostream &, const Book &); // Friend helper that inserts the content of the object into the output stream

  }; // class Book

  // Free Helpers

  // Trim all white spaces from the beginning and end of a string.
  std::string & trim(std::string &, const std::string & = " ");

} // namespace sdds

#endif
