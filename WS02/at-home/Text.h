// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			09-24-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <string>

namespace sdds {

  class Text {

    std::string * records; // Dynamically allocated strings

    int num_recs;

  public:

    // Data constructors
    Text();

    Text(char *);

    // Copy constructor and assignment
    Text(const Text &);

    Text& operator=(const Text&);

    // Move constructor and assignment
    Text(Text&&);

    Text& operator=(Text&&);

    // Destructor
    ~Text();

    size_t size() const;

  };

}

#endif
