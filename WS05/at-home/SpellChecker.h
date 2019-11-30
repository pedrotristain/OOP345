// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds {

  class SpellChecker {

    std::string m_badWords[5];
    std::string m_goodWords[5];

  public:

    SpellChecker(const char *); // One Parameter constructor. Receives a file name.

    void operator()(std::string &) const; // Search the text for mispelled words and fix them.

  }; // class SpellChecker

} // namespace sdds

#endif
