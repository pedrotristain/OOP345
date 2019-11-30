// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <fstream>
#include <iostream>
#include "SpellChecker.h"

namespace sdds {

  // One Parameter constructor. Receives a file name.
  SpellChecker::SpellChecker(const char * file_name){

    // Open the file
    std::ifstream file (file_name);

    if(!file)
      throw("Bad file name!");

    size_t x = 0, empty_begin = 0, empty_end = 0; // Counter variables to iterate through each line.
    std::string str, good_str, bad_str; // Control variables that will hold the strings to populate the object.

    // Iterate through the file to grab the strings.
    do {

      // Grab the current line from the file and store it in the 'str' variable
      std::getline(file, str);

      // Check if the getline command was successful.
      if (file){

        empty_begin = str.find(' ');
        empty_end = str.rfind(' ');

        size_t end = str.length() - empty_end - 2; // Don't know why, but this fixes Matrix

        bad_str = str.substr(0, empty_begin);
        good_str = str.substr(empty_end + 1, end);


        m_badWords[x] = bad_str;
        m_goodWords[x] = good_str;

        x++;

      } // if(file)

    } while (file);

    // Close the file
    file.close();

  } // SpellChecker(const char *)

  // Search the text for mispelled words and fix them.
  void SpellChecker::operator()(std::string & search_str) const{

    std::string::size_type n; // Control variable to hold the index of the found match.
    n = 0;

    // Iterate through the bad word array looking for matches and fixing them.
    for(size_t x = 0; x < 5; x++){   

     do{ // Recursively fix the spelling

        n = search_str.find(m_badWords[x]); // Check if there is a match.
	
        if(n != std::string::npos) // If there is a match, fix the bad spelling.
          search_str.replace(n, m_badWords[x].length(), m_goodWords[x]);

     } while(n != std::string::npos);

    } // for()

  } // void operator()(std::string &) const

} // namespace sdds
